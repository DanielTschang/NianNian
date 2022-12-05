#ifndef Game_h
#define Game_h
#include <iostream>
#include <SFML/Graphics.hpp>
#include "WorkingDirectory.h"
#include "Window.h"
#include "Input.h"


class Game
{
public:
    Game();
    
    
    void Update();
    void LateUpdate();
    void Draw();
    void getInput();

    void CalculateDeltaTime(); 
    bool IsRunning() const;
    
private:
    Window window;
    WorkingDirectory workingDir;
    Input input;
    
    sf::Texture vikingTexture;
    sf::Sprite vikingSprite;

    sf::Clock clock;
    float deltaTime;
    
};

#endif /* Game_hpp */
