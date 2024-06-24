#include <iostream>
#include <portaudio.h>
#include <math.h>
#include "PlateReverb.h"
#include "Adelay.h"
#define PI 3.14159265
#define NUM_SECONDS   (4)
#define SAMPLE_RATE   (44100)

typedef struct
{
    float left_phase;
    float right_phase;
}
paTestData;
//PlateR::Reverb* reverb = new PlateR::Reverb();
AudioDelay::Adelay* aDelay = new AudioDelay::Adelay(16384, SAMPLE_RATE);
float modValue = 0.0;
float tempo = 0.002;
float mRange = 20;
int modDir = 1;
static paTestData data;
typedef float SAMPLE;

float StepSeq()
{
    static float seqValues[]{0.0075f, 0.005f,  0.0081f,  0.0f,  0.00f, 0.0085f, 0.002f, 0.037f, 0.0013f};
    static int index=-1;
    index += 1;
    if(index>5)index=0;
    return seqValues[index];
}



static int patestCallback( const void *inputBuffer, void *outputBuffer,
                           unsigned long framesPerBuffer,
                           const PaStreamCallbackTimeInfo* timeInfo,
                           PaStreamCallbackFlags statusFlags,
                           void *userData )
{
    /* Cast data passed through stream to our structure. */
    paTestData *data = (paTestData*)userData;
    float *out = (float*)outputBuffer;
    unsigned int i;
    //(void) inputBuffer; /* Prevent unused variable warning. */
    const SAMPLE *in = (const SAMPLE*)inputBuffer;

    if( inputBuffer == NULL )
    {
        *out++ = 0;  /* left */
        *out++ = 0;  /* right */
    }
    else
    {
        for( i=0; i<framesPerBuffer; i++ )
        {
            SAMPLE sample = *in++; /* MONO input */


            // // Reverb related

            // // reverb input
            // reverb->Input(sample);
            // // clock reverb memory 1
            // reverb->Tick();
            // // clock reverb memory 2
            // reverb->ModTick();
            
            // *out++ = (reverb->ResultL);  /* left */
            // *out++ = (reverb->ResultR);  /* right */
            if(modDir)
            {
                modValue += tempo; 
            }else
            {
                modValue -= tempo;
            }

            if(modValue<-mRange)modDir = 1;
            if(modValue>mRange)modDir = 0;

            aDelay->Time(150+modValue);

            aDelay->Input(sample);

            *out++ = (aDelay->Result);  /* left */
            *out++ = (aDelay->Result);  /* right */
        }
    }
    
    return 0;
}

int main()
{
    aDelay->Time(350);
    std::cout << "Welcome to the delay\n";
    PaError error;
    PaStream *stream;
    error = Pa_Initialize();
    if(error != paNoError)
    {
        fprintf(stderr, "Problem initializing\n");
        return 1;
    }
    
    /* Get devices */
    // std::cout << "List all devices\n";
    // const PaDeviceInfo* info;
    // auto ndev = Pa_GetDeviceCount();
    // for(int i=0; i<ndev; i++)
    // {
    //     info = Pa_GetDeviceInfo((PaDeviceIndex) i);
    //     if(info->maxOutputChannels > 0)std::cout << "Output device: ";
    //     if(info->maxInputChannels > 0)std::cout << "Input device: ";
    //     printf("%d: %s\n", i, info->name);

    // }
    /* Open an audio I/O stream. */
    error = Pa_OpenDefaultStream( &stream,
                                1,          /* no input channels */
                                2,          /* stereo output */
                                paFloat32,  /* 32 bit floating point output */
                                SAMPLE_RATE,
                                256,        /* frames per buffer */
                                patestCallback,
                                &data );
    if( error != paNoError ) goto error;

    std::cout << "press ENTER to stop listening\n";
    error = Pa_StartStream( stream );
    if( error != paNoError ) goto error;

    // continue until keypress enter
    while ( std::cin.peek() == EOF ) 
    {
            
    }

    // stop streaming
    error = Pa_StopStream( stream );
    if( error != paNoError ) goto error;
    error = Pa_CloseStream( stream );
    if( error != paNoError ) goto error;

    //don´t forget
    std::cout << "Delete reverb" << "\n";
    delete aDelay;

error:
    if(error != paNoError)
    {
        fprintf( stderr, "An error occurred while using the portaudio stream\n" );
    fprintf( stderr, "Error number: %d\n", error );
    fprintf( stderr, "Error message: %s\n", Pa_GetErrorText( error ) );
    }
     /*  Shut down portaudio */
    error = Pa_Terminate();
    if(error != paNoError)
    {
        fprintf(stderr, "Problem terminating\n");
        return 1;
    }
    std::cout << "No found problems\n";
    return 0;
}
