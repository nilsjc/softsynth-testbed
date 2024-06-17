namespace AudioDelay
{
    class Adelay
    {
        public:
            Adelay(int dTime, int sample_freq):
                kSampleFreq(sample_freq),
                delaySize(dTime),
                Feedback(0.7),
                ringMemory(new float[dTime]){};

            void Input(float audioIn);
            float Feedback;
            float m_fDelay_ms = 0;
            void Time(float milliSec);
            float Result;
            ~Adelay() { delete []ringMemory; }

        private:
            float* ringMemory;
            const int kSampleFreq;
            int play = 0;
            int rec = 0;
            float m_fDelayInSamples;
            int delaySize;
            float lerp(float y1, float y2, float x);

        
    };
    inline void Adelay::Time(float milliSec)
    {
        m_fDelayInSamples = milliSec * (float)kSampleFreq / 1000.0;
        play = rec - (int)m_fDelayInSamples;
        if(play<0)play += delaySize;
    }

    inline float Adelay::lerp(float a, float b, float c)
    {
        return a * (1.0 - c) + (b * c);
    }
}