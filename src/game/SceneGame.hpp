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


class SceneGame : public Scene
{
public:
    SceneGame(WorkingDirectory& workingDir, Window& window);

    void onCreate() override;
    void onDestroy() override;
    
    void processInput() override;
    void Update(float deltaTime) override;
    void Draw(Window& window) override;
    void LateUpdate(float deltaTime) override;
    
private:
    ObjectCollection objects;
    Window& window;
    WorkingDirectory& workingDir;
    Input input;
};

#endif