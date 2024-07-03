#ifndef SYNTHMANAGER_H
#define SYNTHMANAGER_H
#include "synthmodules/PlateReverb.h"
namespace SynthManager
{
    class Manager
    {
        public:
            float OutLeft();
            float OutRight();
            float* OutPuts();
            void Input(float* in);
            void Tick();

        private:
            PlateR::Reverb reverb;

    };
}

#endif