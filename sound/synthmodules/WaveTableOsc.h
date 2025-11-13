#ifndef WaveTableOsc_H
#define WaveTableOsc_H
namespace SynthModules
{
    class WaveTableOsc
    {
        public:
        float finalSample;
        float* wavetable;
        float frequency;
        int tableSize;

        void Tick()
        {
            phase += frequency / 44100.0f; // Assuming a sample rate of 44100 Hz
            if (phase < 0.0f) phase += 1.0f;
            if (phase >= 1.0f) phase -= 1.0f;
            // Calculate the index in the wavetable
            float index = phase * static_cast<float>(tableSize);
            int indexInt = static_cast<int>(index);
            float frac = index - static_cast<float>(indexInt);

            // Wrap around the index if it exceeds table size
            int nextIndex = (indexInt + 1) % tableSize;

            // Linear interpolation between the two nearest samples
            finalSample = (1.0f - frac) * wavetable[indexInt] + frac * wavetable[nextIndex];
        }

        private:
        float phase = 0.0f;
    };
}
#endif