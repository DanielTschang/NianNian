//
// Created by danchang11 on 2022/12/20.
//

#ifndef NIANNIAN_TILEMAPPARSER_HPP
#define NIANNIAN_TILEMAPPARSER_HPP

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <sstream>

#include "rapidxml.hpp"
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "TileMap.hpp"
#include "utils.hpp"
#include "Object.hpp"
#include "C_Sprite.hpp"
#include <iostream>
#include <cstring>


using namespace rapidxml;

struct TileSheetData
{
    int textureId;
    sf::Vector2u imageSize;
    int columns;
    int rows;
    sf::Vector2u tileSize;
};

using Layer = std::vector<std::shared_ptr<Tile>>;
using MapTiles = std::map<std::string, std::shared_ptr<Layer>>; // Stores layer names with layer.
using TileSet = std::unordered_map<unsigned int, std::shared_ptr<TileInfo>>; // Stores the different tile types that can be used.

class TileMapParser
{
public:
    TileMapParser(ResourceAllocator<sf::Texture>& textureAllocator);

    std::vector<std::shared_ptr<Object>> Parse(const std::string& file, sf::Vector2i offset);

private:
    std::shared_ptr<TileSheetData> BuildTileSheetData(xml_node<>* rootNode);
    std::shared_ptr<MapTiles> BuildMapTiles(xml_node<>* rootNode);
    std::pair<std::string, std::shared_ptr<Layer>> BuildLayer(xml_node<>* layerNode, std::shared_ptr<TileSheetData> tileSheetData);

    ResourceAllocator<sf::Texture>& textureAllocator;
};



#endif //NIANNIAN_TILEMAPPARSER_HPP
