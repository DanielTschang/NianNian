#include "C_Sprite.hpp"
#include "Component.hpp"

C_Sprite::C_Sprite(Object* owner) : Component(owner) {}

void C_Sprite::Load(const std::string& filePath)
{
    texture.loadFromFile(filePath);
    sprite.setTexture(texture);
}

void C_Sprite::Draw(Window& window)
{
    window.Draw(sprite);
}

void C_Sprite::LateUpdate(float deltatime)
{
    sprite.setPosition(owner->position->GetPosition());
}