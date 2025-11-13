#include "WaveTableOsc.h"
// float SynthModules::WaveTableOsc::WaveTableOscrun(float* wavetable, int tableSize)
// {
//     // Ensure phase is within the range [0, 1)
//     while (phase < 0.0f) phase += 1.0f;
//     while (phase >= 1.0f) phase -= 1.0f;

//     // Calculate the index in the wavetable
//     float index = phase * static_cast<float>(tableSize);
//     int indexInt = static_cast<int>(index);
//     float frac = index - static_cast<float>(indexInt);

//     // Wrap around the index if it exceeds table size
//     int nextIndex = (indexInt + 1) % tableSize;

//     // Linear interpolation between the two nearest samples
//     float sample = (1.0f - frac) * wavetable[indexInt] + frac * wavetable[nextIndex];

//     return sample;
// }

