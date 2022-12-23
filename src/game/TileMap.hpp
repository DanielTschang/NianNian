//
// Created by danchang11 on 2022/12/20.
//

#ifndef NIANNIAN_TILEMAP_HPP
#define NIANNIAN_TILEMAP_HPP

#include <SFML/Graphics/Rect.hpp>
#include "ResourceAllocator.hpp"

struct TileInfo
{
    TileInfo() : tileID(-1)
    {}

    TileInfo(int textureID, unsigned int tileID, sf::IntRect textureRect)
            : textureID(textureID), tileID(tileID), textureRect(textureRect) { }

    int tileID; // the id of the texture that contains the tiles sprite. This will be returned by our texture allocator
    int textureID;
    sf::IntRect textureRect;
};

struct Tile
{
    std::shared_ptr<TileInfo> properties;
    int x;
    int y;
};


#endif //NIANNIAN_TILEMAP_HPP
