#ifndef AUDIODELAY_H
#define AUDIODELAY_H
class AudioDelay
{
    public:
    float Use(float audio);
    float Feedback = 0.0;

    AudioDelay(int time):
        Time(time),
        record(time/2),
        ringMemory(new float[time]){};

    ~AudioDelay() { delete []ringMemory; }

    private:
    float* ringMemory;
    float feedBackAudio = 0;
    int play=0;
    int Time;
    int record;
};
#endif