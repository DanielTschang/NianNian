#include "Tile.hpp"

Tile::Tile(float x, float y, float gridSizeF) {
    this->shape.setSize(sf::Vector2f(gridSizeF, gridSizeF));
    this->shape.setFillColor(sf::Color::Green);
    this->shape.setPosition(x,y);
}

void Tile::Update(const float &deltaTime) {

}

void Tile::LateUpdate(const float &deltaTime) {

}

void Tile::Draw(Window &window)
{
     window.Draw(this->shape);
}

Tile::~Tile() {

}

