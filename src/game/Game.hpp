#ifndef Game_hpp
#define Game_hpp


#include <iostream>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "WorkingDirectory.hpp"
#include "Window.hpp"
#include "Input.hpp"

#include "SceneStateMachine.hpp"
#include "SceneSplashScreen.hpp"
#include "SceneMainMenu.hpp"
#include "SceneGame.hpp"


class Game
{
public:
    Game();
    void getInput();
    void Update();
    void LateUpdate();
    void Draw(); // render
    void CalculateDeltaTime(); 

    bool IsRunning() const;
    
private:
    Window window;
    WorkingDirectory workingDir;

    sf::Clock clock;
    float deltaTime;

    SceneStateMachine sceneManager;
    
};


#endif
