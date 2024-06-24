#include "MoogVCF.h"

float MoogVCF::MoogVCFrun(float input, float fc, float res)
{
    float f = fc * 1.16;
    float fb = res * (1.0 - 0.15 * f * f);
    input -= out4 * fb;
    input *= 0.35013 * (f*f)*(f*f);
    out1 = input + 0.3 * in1 + (1 - f) * out1; // Pole 1
    in1  = input;
    out2 = out1 + 0.3 * in2 + (1 - f) * out2;  // Pole 2
    in2  = out1;
    out3 = out2 + 0.3 * in3 + (1 - f) * out3;  // Pole 3
    in3  = out2;
    out4 = out3 + 0.3 * in4 + (1 - f) * out4;  // Pole 4
    in4  = out3;
    return out4;
}

// float lowpass(float* sig, float freq, float* del, int vecsize, float sr)
// {
//     double costh, coef;
//     costh = 2. - cos(2 * PI*freq/sr);
//     coef = sqrt(costh*costh - 1.) - costh;

//     for(int i = 0; i < vecsize; i++)
//     {
//         sig[i] = (float) (sig[i]*(1 + coef) - *del*coef);
//         *del = sig[i];
//     }
//     return *sig;
// }
