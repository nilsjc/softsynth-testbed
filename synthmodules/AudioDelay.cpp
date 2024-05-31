#include "audioDelay.h"


float AudioDelay::Use(float audio)
{
    feedBackAudio *= Feedback;
    ringMemory[record] = audio + feedBackAudio;
    feedBackAudio = ringMemory[play];
    play++;
    record++;
    if(play==Time)play=0;
    if(record==Time)record=0;
    return feedBackAudio;
}