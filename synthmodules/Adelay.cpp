#include "Adelay.h"
#include <iostream>
/*
float result;
float m_fDelayInSamples;
int delaySize;

    float* m_pBuffer; <--ringmemory
    int m_nReadIndex; <--play
    int m_nWriteIndex; <--rec
    int m_nBuffersize; <--length of ringmemory (time * sampleRate) även delaySize skapas i konstruktor
    float m_fDelay_ms; <--delay time cv input
    float m_fDelayInSamples <-- skapas i ett anrop när man ändrar delaytime
        formeln är delayMs*((float)m_nSampleRate/1000.0) så t.ex 2 sek ger 2000*((float)44100/1000.)
*/
void AudioDelay::Adelay::Input(float audioIn)
{
    float getOut = ringMemory[play];
    // if delay < 1 sample interpolate between input x(n) and x(n-1)
    if(play == rec && m_fDelayInSamples < 1.00)
    {
        // interplate x(n) with x(n-1), set yn = xn
        getOut = audioIn;
    } 

    int readIndex_1 = play - 1;
    if(readIndex_1 < 0)
        readIndex_1 = delaySize-1;
    
    // get y(n-1)
    float yn_1 = ringMemory[readIndex_1];

    // interpolate (0,yn) and (1,yn_1)by the amount fracdelay
    float fracDelay = m_fDelayInSamples - (int)m_fDelayInSamples;

    float finterp = lerp(getOut, yn_1, fracDelay);

    if(m_fDelayInSamples == 0)
    {
        getOut = audioIn;
    }else{
        getOut = finterp;
    }


    ringMemory[rec] = audioIn + Feedback * getOut;
    play++;
    if(play>=delaySize)play=0;
    rec++;
    if(rec>=delaySize)rec=0;

    Result = getOut;

}