#pragma once

#include "Scene.h"
#include "Input.h"
#include "WorkingDirectory.h"

class SceneGame : public Scene
{
public:
    SceneGame(WorkingDirectory& workingDir);
    
    void onCreate() override;
    void onDestroy() override;
    
    void processInput() override;
    void Update(float deltaTime) override;
    void Draw(Window& window) override;
    
private:
    sf::Texture vikingTexture;
    sf::Sprite vikingSprite;
    
    WorkingDirectory& workingDir;
    Input input;
};