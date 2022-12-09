#include "Game.hpp"

Game::Game() : window("NianNian Adventure")
{
    // This creates a smart pointer to a splash screen scene.
    std::shared_ptr<SceneSplashScreen> splashScreen = 
        std::make_shared<SceneSplashScreen>(workingDir, sceneManager, window);
    
    // This creates a smart pointer to a game screen scene.
    std::shared_ptr<SceneGame> gameScene = std::make_shared<SceneGame>(workingDir);
       
    unsigned int splashScreenID = sceneManager.Add(splashScreen);
    unsigned int gameSceneID = sceneManager.Add(gameScene);
    
    // Now that we have our game scenes id, we can set the splash screen to transition to the game scene.
    splashScreen->setSwitchToScene(gameSceneID);
    
    // We want the game to start at the splash screen
    sceneManager.switchTo(splashScreenID);
    
    deltaTime = clock.restart().asSeconds();
}

void Game::Update()
{
    window.Update();
    sceneManager.Update(deltaTime);
}

void Game::LateUpdate()
{
    sceneManager.LateUpdate(deltaTime);
}

void Game::Draw()
{
    window.BeginDraw();
    
    sceneManager.Draw(window);

    window.EndDraw();
}

void Game::getInput()
{
    sceneManager.processInput();
}


void Game::CalculateDeltaTime()
{
    deltaTime = clock.restart().asSeconds();
}

bool Game::IsRunning() const
{
    return window.IsOpen();
}