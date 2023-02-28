#ifndef NIANNIAN_TILE_HPP
#define NIANNIAN_TILE_HPP

#include "SFML/Graphics.hpp"
#include "Window.hpp"

class Tile {
public:
    Tile(){};
    Tile(float x, float y, float gridSizeF);
    virtual ~Tile();
protected:
    sf::RectangleShape shape;
public:
    void Update(const float& deltaTime);
    void LateUpdate(const float& deltaTime);
    void Draw(Window& window);

};


#endif //NIANNIAN_TILE_HPP
