
#ifndef NIANNIAN_TILEMAP_HPP
#define NIANNIAN_TILEMAP_HPP

#include <SFML/Graphics/Rect.hpp>
#include "Tile.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include "ResourceAllocator.hpp"
#include <vector>

class TileMap
{
private:
    float gridSizeF;
    unsigned gridSize;
    unsigned countOfLayers;
    sf::Vector2u mapSize;
    std::vector<std::vector<std::vector<Tile>>> map; //3D vector
public:
    TileMap();
    virtual ~TileMap();
public:
    void Update(const float& deltaTime);
    void LateUpdate(const float& deltaTime);
    void Draw(Window& window);

};


#endif //NIANNIAN_TILEMAP_HPP
