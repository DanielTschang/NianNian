#ifndef NIANNIAN_C_DIRECTION_HPP
#define NIANNIAN_C_DIRECTION_HPP

#include "Component.hpp"
#include "C_Velocity.hpp"
#include "Object.hpp"
#include "Animation.hpp"
#include <cmath>

class C_Direction : public Component
{
public:
    C_Direction(Object *owner);

    void Awake() override;
    FacingDirection GetDirection();
private:
    FacingDirection currentDir;
    std::shared_ptr<C_Velocity> velocity;

};


#endif //NIANNIAN_C_DIRECTION_HPP
