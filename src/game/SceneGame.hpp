#ifndef SceneGame_hpp
#define SceneGame_hpp

#include "Window.hpp"
#include "Scene.hpp"
#include "Input.hpp"
#include "WorkingDirectory.hpp"
#include "Object.hpp"
#include "C_Sprite.hpp"
#include "C_Movement.hpp"
#include <iostream>

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
    std::shared_ptr<Object> player;
    Window& window;
    WorkingDirectory& workingDir;
    Input input;
};

#endif