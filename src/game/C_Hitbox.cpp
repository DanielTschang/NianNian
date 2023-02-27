#include "C_Hitbox.hpp"

C_Hitbox::C_Hitbox(Object* owner) : Component(owner)
{
    this->hitbox.setFillColor(sf::Color::Transparent);

    //for devlopment
    this->hitbox.setOutlineThickness(1.f);
    this->hitbox.setOutlineColor(sf::Color::Green);
}

C_Hitbox::~C_Hitbox()
{

}

void C_Hitbox::Update(const float &deltaTime)
{
    this->hitbox.setPosition(this->owner->position->GetPosition().x + this->offsetX, this->owner->position->GetPosition().y + this->offsetY);
}

void C_Hitbox::LateUpdate(const float &deltaTime) {

}

void C_Hitbox::Draw(Window &window)
{
    window.Draw(this->hitbox);
}

bool C_Hitbox::checkCollision(const sf::FloatRect& floatRect) {
    return this->hitbox.getGlobalBounds().intersects(floatRect);
}

void C_Hitbox::setOffset(const float offsetX, const float offsetY) {
    this->offsetX = offsetX;
    this->offsetY = offsetY;
}

void C_Hitbox::setSize(const float width, const float height) {
    this->width = width;
    this->height = height;
    this->hitbox.setSize(sf::Vector2f(this->width, this->height));
}
