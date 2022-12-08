#ifndef Game_hpp
#define Game_hpp


#include <iostream>
#include <SFML/Graphics.hpp>
#include "WorkingDirectory.hpp"
#include "Window.hpp"
#include "Input.hpp"

#include "SceneStateMachine.hpp"
#include "SceneSplashScreen.hpp"
#include "SceneGame.hpp"


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


#endif
