#include "SynthManager.h"

float SynthManager::Manager::OutLeft()
{
    return (waveOsc.finalSample / 2.0f) + (waveOsc2.finalSample / 2.0f);
}

float SynthManager::Manager::OutRight()
{
    return (waveOsc.finalSample / 2.0f) + (waveOsc2.finalSample / 2.0f);
}

float *SynthManager::Manager::OutPuts()
{
    return nullptr;
}

void SynthManager::Manager::Input(float *in)
{
    //waveOsc.frequency = 220.0f; // Example: set frequency to 220 Hz
}

void SynthManager::Manager::Tick()
{
    waveOsc.Tick();
    waveOsc2.Tick();
}
