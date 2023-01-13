#include "Entity.hpp"

Entity::Entity() : movementSpeed(100.f)
{
    this->initVariables();
}

Entity::~Entity() {
    delete this->texture;
}

void Entity::initVariables()
{

}

void Entity::move(const float &deltaTime, const float x, const float y) {
    this->sprite.move(x * this->movementSpeed *deltaTime, y * this->movementSpeed *deltaTime);
}

void Entity::Update(const float &deltaTime) {

}

void Entity::LateUpdate(const float &deltaTime) {

}

void Entity::Draw(Window &window) {
    window.Draw(this->sprite);
}

void Entity::createSprite(sf::Texture *texture) {
    this->texture = texture;
    this->sprite.setTexture(*this->texture);
}
