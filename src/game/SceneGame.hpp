#ifndef SceneGame_hpp
#define SceneGame_hpp

#include <iostream>
#include "Window.hpp"
#include "Scene.hpp"
#include "Input.hpp"
#include "WorkingDirectory.hpp"
#include "Object.hpp"
#include "C_Sprite.hpp"
#include "C_Movement.hpp"
#include "ObjectCollection.hpp"
#include "C_Animation.hpp"


class SceneGame : public Scene
{
public:
    SceneGame(WorkingDirectory& workingDir, ResourceAllocator<sf::Texture>& textureAllocator);

    void onCreate() override;
    void onDestroy() override;
    
    void processInput() override;
    void Update(float deltaTime) override;
    void Draw(Window& window) override;
    void LateUpdate(float deltaTime) override;
    
private:
    ObjectCollection objects;
    WorkingDirectory& workingDir;
    Input input;
    ResourceAllocator<sf::Texture>& textureAllocator;
};

#endif