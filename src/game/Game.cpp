#include "Game.hpp"

void Game::initWindow() {
    this->window = new Window("Default Game Name");
}

void Game::initWindow(std::string WindowName) {
    this->window = new Window(WindowName);
}

void Game::initState()
{
    // This creates a pointer to a splash screen scene.
    SceneSplashScreen *splashScreen = new SceneSplashScreen(workingDir, *sceneManager, *window, textureAllocator);
    unsigned int splashScreenID = sceneManager->Add(splashScreen); // get the id of splash scene

    // This creates a pointer to a game screen scene.
    SceneGame *gameScene = new SceneGame(workingDir, textureAllocator);
    unsigned int gameSceneID = sceneManager->Add(gameScene);

    //we tell the splash screen which scene to switch after finished loading
    splashScreen->setSwitchToScene(gameSceneID);

    //switch to splash screen via sceneManager
    this->sceneManager->switchTo(splashScreenID);
}

Game::Game()
{
    this->initWindow("NianNianAdventure");
    this->CalculateDeltaTime();
    this->initState();
}

Game::~Game() {
    delete this->window;
    delete this->sceneManager;
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



