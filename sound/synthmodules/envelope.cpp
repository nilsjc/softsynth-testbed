#include "envelope.h"

float Envelope::Tick()
{
    switch(segment)
    {
        case 1:
            envValue += AttackSpeed;
            if(envValue>=1.0)
            {
                segment=2;
            }
            break;
        
        case 2:
            envValue -= DecaySpeed;
            if(envValue<= 0.0)
            {
                envValue=0;
                segment=0;
            }
        break;

        default:
            envValue=0;
            break;
    }
    return envValue;
}
float Envelope::GetValue()
{
    return envValue;
}
void Envelope::Start()
{
    segment = 1;
    envValue = 0.0;
}