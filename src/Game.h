#ifndef Game_h
#define Game_h
#include <iostream>
#include <SFML/Graphics.hpp>
#include "WorkingDirectory.h"
#include "Window.h"
#include "Input.h"

#include "SceneStateMachine.h"
#include "SceneSplashScreen.h"
#include "SceneGame.h"


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

    sf::Clock clock;
    float deltaTime;

    SceneStateMachine sceneStateMachine;
    SceneStateMachine sceneManager;
    
};

#endif /* Game_hpp */
