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
#include "SharedContext.hpp"
#include "ObjectCollection.hpp"
#include "C_Animation.hpp"
//#include "TileMapParser.hpp"
#include "C_DashMovement.hpp"
#include "Player.hpp"


class SceneGame : public Scene
{
public:
    SceneGame(WorkingDirectory &workingDir, ResourceAllocator<sf::Texture> &textureAllocator, Window &window,
              SceneStateMachine &sceneManager, Input &input);

    ~SceneGame();
    void onCreate() override;
    void onDestroy() override;
    
    void processInput() override;
    void Update(const float &deltaTime) override;
    void Draw(Window& window) override;
    void LateUpdate(const float &deltaTime) override;
    void closeScene() override;
    void initInput();
    
private:
    SharedContext sharedContext;
    ObjectCollection objects;
    WorkingDirectory& workingDir;
    ResourceAllocator<sf::Texture>& textureAllocator;
//    TileMapParser mapParser;

private:
    void createPlayer();
};

#endif