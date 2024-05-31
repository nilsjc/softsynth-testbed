#ifndef ENVELOPE_H
#define ENVELOPE_H
class Envelope
{
    public:
    float Tick();
    void Start();
    float GetValue();
    float DecaySpeed = 0.00008;
    float AttackSpeed =0.005;

    private:
    float envValue = 0.0;
    char segment = 0;
    
};

#endif