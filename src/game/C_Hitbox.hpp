#ifndef NIANNIAN_C_HITBOX_HPP
#define NIANNIAN_C_HITBOX_HPP

#include "Component.hpp"
#include "Input.hpp"
#include "C_Animation.hpp"
#include "Object.hpp"
#include "CooldownTimer.hpp"

class C_Hitbox : public Component{
private:
    sf::RectangleShape hitbox;
    float offsetX;
    float offsetY;
    float width;
    float height;
public:
    void setOffset(const float offsetX, const float offsetY);
    void setSize(const float width, const float height);
public:
    C_Hitbox(Object* owner);
    ~C_Hitbox();




    void Update(const float& deltaTime) override;
    void LateUpdate(const float& deltaTime) override;
    void Draw(Window& window) override;

    bool checkCollision(const sf::FloatRect& floatRect);
};


#endif //NIANNIAN_C_HITBOX_HPP
