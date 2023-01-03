#include "Game.hpp"

void Game::initWindow() {
    this->window = new Window("Default Game Name");
}

void Game::initWindow(std::string WindowName) {
    this->window = new Window(WindowName);
}

Game::Game()
{
    this->initWindow("NianNianAdventure");



    // This creates a smart pointer to a splash screen scene.
//    std::shared_ptr<SceneSplashScreen> splashScreen =
//        std::make_shared<SceneSplashScreen>(workingDir, sceneManager, window, textureAllocator);
//
//    // This creates a smart pointer to a game screen scene.
//    std::shared_ptr<SceneGame> gameScene = std::make_shared<SceneGame>(workingDir, textureAllocator);
//    std::shared_ptr<SceneMainMenu> menuScene =
//            std::make_shared<SceneMainMenu>(workingDir, sceneManager, window);
//
//    unsigned int splashScreenID = sceneManager.Add(splashScreen);
//    unsigned int gameSceneID = sceneManager.Add(gameScene);
//    unsigned int menuSceneID= sceneManager.Add(menuScene);
//
//    // Now that we have our game scene id, we can set the splash screen to transition to the game scene.
//    splashScreen->setSwitchToScene(gameSceneID);
//
//    // We want the game to start at the splash screen
//    sceneManager.switchTo(splashScreenID);
//
//    deltaTime = clock.restart().asSeconds();
}

Game::~Game() {
    delete this->window;
}

void Game::Update()
{
    window->Update();
    sceneManager.Update(deltaTime);
}

void Game::LateUpdate()
{
    sceneManager.LateUpdate(deltaTime);
}

void Game::Draw()
{
    window->BeginDraw(); //sf::window.clear()
    
    sceneManager.Draw(*window); //scene draw

    window->EndDraw(); //sf::window.display
}

void Game::getInput()
{
    sceneManager.processInput();
}

/*
 * updates the deltatime variable with the time it takes to render and update per frame
 */
void Game::CalculateDeltaTime()
{
    this->deltaTime = this->deltaTimeClock.restart().asSeconds();
}

bool Game::IsRunning() const
{
    return window->IsOpen();
}

void Game::run() {
    while (this->IsRunning())
    {
        this->getInput();
        this->Update();
        this->LateUpdate();
        this->Draw();
        this->CalculateDeltaTime();
    }
}

void Game::updateEvents() {

}



