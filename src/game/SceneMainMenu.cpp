#include "SceneMainMenu.hpp"

SceneMainMenu::SceneMainMenu
(WorkingDirectory& workingDir, Window& window, SceneStateMachine& sceneManager)
        : Scene(window, sceneManager),workingDir(workingDir) {
    this->initVariables();
    this->initButtons();
    this->initBackground();

}

SceneMainMenu::~SceneMainMenu() {
    for(auto it = this->buttonMap.begin(); it!=buttonMap.end(); it++)
    {
        delete it->second;
    }
    buttonMap.clear();
}

void SceneMainMenu::onDestroy()
{

}

void SceneMainMenu::onCreate()
{

}

void SceneMainMenu::processInput()
{
    this->input.Update();
}

void SceneMainMenu::updateButtonsState() {
    for(auto it = this->buttonMap.begin(); it!=buttonMap.end(); it++)
    {
        it->second->Update(this->mousePosView);
    }
}

void SceneMainMenu::triggerButtons()
{
    if(this->buttonMap[e_buttons::gameStart]->isPressed())
        this->sceneManager.switchTo(AllScenes::GameSceneLevelOne);
    if(this->buttonMap[e_buttons::gameEnd]->isPressed())
        this->closeScene();
    if(this->buttonMap[e_buttons::Setting]->isPressed())
        std::cout << "trigger settings button" << std::endl;
}

void SceneMainMenu::Update(const float &deltaTime)
{
    this->updateMousePosition(window);
    this->updateButtonsState();
    this->triggerButtons();
}

void SceneMainMenu::drawButtons() {
    for(auto it = this->buttonMap.begin(); it!=buttonMap.end(); it++)
    {
        it->second->Draw(window);
    }
}

void SceneMainMenu::Draw(Window &window)
{
    window.Draw(this->background);
    this->drawButtons();
}

void SceneMainMenu::closeScene() {
    this->isClose = true;
}

void SceneMainMenu::initButtons() {
    this->initFonts();

    buttonMap[e_buttons::gameStart] = new Button(100.f,100.f,150.f,50.f, "New Game", &this->Font,
                            sf::Color(70,70,70,200), sf::Color(150,150,150,255),
                            sf::Color(20,20,20,200)
                );
    buttonMap[e_buttons::Setting] = new Button(100.f,180.f,150.f,50.f, "Settings", &this->Font,
                                              sf::Color(70,70,70,200), sf::Color(150,150,150,255),
                                              sf::Color(20,20,20,200)
    );
    buttonMap[e_buttons::gameEnd] = new Button(100.f,260.f,150.f,50.f, "End Game", &this->Font,
                                       sf::Color(70,70,70,200), sf::Color(150,150,150,255),
                                       sf::Color(20,20,20,200)
    );

}

void SceneMainMenu::initFonts() {
    if(!this->Font.loadFromFile(WorkingDirectory::GetFonts() + "JosefinSans-Light.ttf"))
    {
        throw "ERROR::MAINMENU:: COULD NOT LOAD FONT!";
    }
}

void SceneMainMenu::initBackground()
{
    this->background.setSize(sf::Vector2f
        (static_cast<float>(this->window.getSize().x),
         static_cast<float>(this->window.getSize().y)));
    if(!this->backgroundTexture.loadFromFile(workingDir.GetResources() + "background/background.jpg"))
        throw "ERROR::MAIN_MENU_SCENE::FAILED_TO_LOAD_BACKGROUND_IMAGE";

    this->background.setTexture(&this->backgroundTexture);

}

void SceneMainMenu::initVariables()
{

}
