#include "Game.hpp"

void Game::initWindow() {
    this->window = new Window("Default Game Name");
}

void Game::initVariables() {
    this->sceneManager = new SceneStateMachine();
    this->textureAllocator = new ResourceAllocator<sf::Texture>();
}

void Game::initWindow(std::string WindowName) {
    this->window = new Window(WindowName);
}

void Game::initState()
{
    // This creates a pointer to a splash screen scene.
    SceneSplashScreen *splashScreen = new SceneSplashScreen(workingDir, *sceneManager, *window, *textureAllocator);
    unsigned int splashScreenID = sceneManager->Add(splashScreen); // get the id of splash scene

    // This creates a pointer to a game screen scene.
    SceneGame *gameScene = new SceneGame(workingDir, *textureAllocator, *this->window);
    unsigned int gameSceneID = sceneManager->Add(gameScene);

    SceneMainMenu *MainMenuScene = new SceneMainMenu(workingDir, *sceneManager, *window);
    unsigned int MainMenuSceneID = sceneManager->Add(MainMenuScene);
    //we tell the splash screen which scene to switch after finished loading
    splashScreen->setSwitchToScene(gameSceneID);

    //switch to splash screen via sceneManager
//    this->sceneManager->switchTo(splashScreenID);
    this->sceneManager->switchTo(MainMenuSceneID);
}

Game::Game()
{
    this->initVariables();
    this->initWindow("NianNianAdventure");
    this->CalculateDeltaTime();
    this->initState();
}

Game::~Game() {
    delete this->window;
}

void Game::Update()
{
    window->Update();
    sceneManager->Update(deltaTime);
}

void Game::LateUpdate()
{
    sceneManager->LateUpdate(deltaTime);
}

void Game::Draw()
{
    window->BeginDraw(); //sf::window.clear()

    sceneManager->Draw(*window); //scene draw

    window->EndDraw(); //sf::window.display
}

void Game::getInput()
{
    sceneManager->processInput();
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

void Game::isClose()
{
    if(sceneManager->isEmpty())
    {
        window->closeWindow();
    }
}

void Game::run() {
    while (this->IsRunning())
    {
        this->getInput();
        this->Update();
        this->LateUpdate();
        this->Draw();
        this->CalculateDeltaTime();
//        this->isClose();
    }
}

void Game::updateEvents() {

}





