#include "SynthManager.h"

float SynthManager::Manager::OutLeft()
{
    return reverb.ResultL;
}

float SynthManager::Manager::OutRight()
{
    return reverb.ResultR;
}

float *SynthManager::Manager::OutPuts()
{
    return nullptr;
}

void SynthManager::Manager::Input(float *in)
{
    reverb.Input(in[0]);
}

void SynthManager::Manager::Tick()
{
    reverb.Tick();
    reverb.ModTick();
}
