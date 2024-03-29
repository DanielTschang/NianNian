#pragma once


#include <iostream>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include "Scene.hpp"

#include "WorkingDirectory.hpp"
#include "Window.hpp"
#include "Input.hpp"


#include "SceneStateMachine.hpp"
#include "SceneSplashScreen.hpp"
#include "SceneMainMenu.hpp"
#include "SceneGame.hpp"
#include "AllScenes.hpp"


class Game
{
private:
    void initWindow();
    void initState();
    void initVariables();

public:
    //Constructor / Destructor
    Game();
    virtual ~Game();

    //functions
    void getInput();
    void Update();
    void LateUpdate();
    void Draw(); // render
    void CalculateDeltaTime();
    void run();
    void updateEvents();

    bool IsRunning() const;
    void isClose();
    
private:
    Window* window;
    WorkingDirectory workingDir;
    Input* input;

    sf::Clock deltaTimeClock;
    float deltaTime;

    SceneStateMachine* sceneManager;
    ResourceAllocator<sf::Texture>* textureAllocator;

};

