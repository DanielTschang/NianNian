#include "Game.hpp"

void Game::initWindow() {
    this->window = new Window();
}

void Game::initVariables() {
    this->sceneManager = new SceneStateMachine();
    this->textureAllocator = new ResourceAllocator<sf::Texture>();
}


void Game::initState()
{
    // This creates a pointer to a scenes.
    SceneSplashScreen *splashScreen = new SceneSplashScreen(workingDir, *this->textureAllocator, *this->window, *this->sceneManager);
    SceneMainMenu *MainMenuScene = new SceneMainMenu(workingDir,  *this->window, *this->sceneManager);
    SceneGame *gameScene = new SceneGame(workingDir, *textureAllocator, *this->window, *this->sceneManager);


    //add all scenes to sceneManager
    sceneManager->Add(splashScreen, AllScenes::Splash); // get the id of splash scene
    sceneManager->Add(MainMenuScene, AllScenes::MainMenu);
    sceneManager->Add(gameScene, AllScenes::GameSceneLevelOne);

    //we tell the splash screen which scene to switch after finished loading
    splashScreen->setSwitchToScene(AllScenes::MainMenu);
    //switch to splash screen via sceneManager
    this->sceneManager->switchTo(AllScenes::Splash);
}

Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->CalculateDeltaTime();
    this->initState();
}

Game::~Game() {
    delete this->window;
    delete this->sceneManager;
    delete this->textureAllocator;
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
        this->isClose();
    }
}

void Game::updateEvents() {

}





