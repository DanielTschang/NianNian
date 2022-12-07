#include "SceneGame.h"
#include <iostream>

SceneGame::SceneGame(WorkingDirectory& workingDir) : workingDir(workingDir)
{
    
}

void SceneGame::onCreate()
{
    vikingTexture.loadFromFile(workingDir.Get() + "viking.png");
    vikingSprite.setTexture(vikingTexture);
}

void SceneGame::onDestroy()
{
    
}

void SceneGame::processInput()
{
    input.Update();
}

void SceneGame::Update(float deltaTime)
{
    const sf::Vector2f& spritePos = vikingSprite.getPosition();
    const int moveSpeed = 100;
    
    int xMove = 0;
    if(input.IsKeyPressed(Input::KEY::LEFT))
    {
        xMove -= moveSpeed;
    }
    if(input.IsKeyPressed(Input::KEY::RIGHT))
    {
        xMove += moveSpeed;
    }
    
    int yMove = 0;
    if(input.IsKeyPressed(Input::KEY::UP))
    {
        yMove -= moveSpeed;
    }
    if(input.IsKeyPressed(Input::KEY::DOWN))
    {
        yMove += moveSpeed;
    }
    
    float xFrameMove = xMove * deltaTime;
    float yFrameMove = yMove * deltaTime;
    
    vikingSprite.setPosition(spritePos.x + xFrameMove, spritePos.y + yFrameMove);
}

void SceneGame::Draw(Window& window)
{
    window.Draw(vikingSprite);
}