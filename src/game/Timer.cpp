
#include "Timer.h"

Timer::Timer() {
    startTime = std::chrono::system_clock::now();
    currentTime = std::chrono::system_clock::now();
}

Timer::~Timer() {

}

void Timer::restartTimer() {
    startTime = std::chrono::system_clock::now();
}


float Timer::getElapsedTime() {
    currentTime = std::chrono::system_clock::now();
    std::chrono::duration<float> elapsedTime = currentTime - startTime;
    return elapsedTime.count();
}
