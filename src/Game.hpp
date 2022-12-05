#pragma once

#include <SFML/Graphics.hpp>
#include "WorkingDirectory.hpp"
#include "Window.hpp"
#include <iostream>

class Game
{
public:
    void Update();
    void LateUpdate();
    void Draw();
    bool IsRunning() const;
    void CalculateDeltaTime();
private:
    Window window;
    WorkingDirectory workingDir;
    
    sf::Texture vikingTexture;
    sf::Sprite vikingSprite;
    sf::Clock clock;
    float deltaTime;
};
