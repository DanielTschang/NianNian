#ifndef NIANNIAN_COOLDOWNTIMER_HPP
#define NIANNIAN_COOLDOWNTIMER_HPP

#include "Timer.h"

class CooldownTimer {
private:
    Timer *timer;
    float cooldown;
public:
    CooldownTimer(float cooldown);
    ~CooldownTimer();

    bool isValid();
    void restartCooldown();
    void setCooldown(float cooldown);

};


#endif //NIANNIAN_COOLDOWNTIMER_HPP
