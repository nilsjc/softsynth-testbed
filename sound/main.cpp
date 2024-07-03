#include <iostream>
#include <portaudio.h>
#include <math.h>
#include "SynthManager.h"
#include "AudioStream.h"
#define PI 3.14159265
#define NUM_SECONDS   (4)
#define SAMPLE_RATE   (44100)


int main()
{
    SynthManager::Manager manager;
    AudioStream::Runner runner;
    runner.SetManager(&manager);
    runner.Open();
    std::cout << "Press to stop listening\n";
    // continue until keypress enter
    while ( std::cin.peek() == EOF ) 
    {
            
    }
    return 0;
}
