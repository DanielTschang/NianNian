#ifndef NIANNIAN_TIMER_H
#define NIANNIAN_TIMER_H

#include <chrono>

class Timer {
public:
    Timer();
    ~Timer();
    void restartTimer();
    float getElapsedTime();

private:
    std::chrono::system_clock::time_point startTime;
    std::chrono::system_clock::time_point currentTime;
    std::chrono::system_clock::time_point lastDeltaTick;

    std::chrono::duration<float> deltaTime;
};


#endif //NIANNIAN_TIMER_H
