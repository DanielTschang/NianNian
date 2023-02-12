#include "CooldownTimer.hpp"

CooldownTimer::CooldownTimer(float cooldown) : cooldown(cooldown) {
    this->timer = new Timer();
}

CooldownTimer::~CooldownTimer() {

}

bool CooldownTimer::isValid() {
    float duration = this->timer->getElapsedTime();
    if(duration > cooldown){
        return true;
    }
    return false;
}

void CooldownTimer::restartCooldown() {
     this->timer->restartTimer();
}

void CooldownTimer::setCooldown(float cooldown) {
    this->cooldown = cooldown;
}
