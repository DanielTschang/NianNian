#include "TileMap.hpp"

TileMap::TileMap() {
    this->gridSizeF = 50.f;
    this->gridSize = static_cast<unsigned>(this->gridSizeF);
    this->mapSize.x = 30;
    this->mapSize.y = 30;
    this->countOfLayers = 1;

    this->map.resize(this->mapSize.x);
    for( size_t i = 0; i < mapSize.x; i++)
    {
        for( size_t j = 0; j<mapSize.y; j++)
        {
            this->map[i].resize(this->mapSize.y);
            for( size_t k = 0; k < this->countOfLayers ; k++)
            {
                this->map[i][j].push_back(Tile(i * this->gridSizeF, j * this->gridSizeF, this->gridSizeF));

            }
        }
    }
}

void TileMap::Update(const float &deltaTime) {

}

void TileMap::LateUpdate(const float &deltaTime) {

}

void TileMap::Draw(Window &window) {
    for(auto &x : this->map)
    {
        for(auto &y : x)
        {
            for(auto &layer : y)
            {
                layer.Draw(window);
            }
        }
    }
}

TileMap::~TileMap() {

}


