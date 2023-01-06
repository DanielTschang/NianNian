#include "SceneMainMenu.hpp"

SceneMainMenu::SceneMainMenu
(WorkingDirectory& workingDir, Window& window, SceneStateMachine& sceneManager)
        : Scene(window, sceneManager),workingDir(workingDir) {
    this->initButtons();
    this->background.setSize(static_cast<sf::Vector2f>(window.getSize()));
    this->background.setFillColor(sf::Color::Blue);
}
//SceneStateMachine* sceneManager
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

void SceneMainMenu::updateButtons() {
    for(auto it = this->buttonMap.begin(); it!=buttonMap.end(); it++)
    {
        it->second->Update(this->mousePosView);
    }
}


void SceneMainMenu::Update(const float &deltaTime)
{
    this->updateMousePosition(window);
    this->updateButtons();

    if(this->buttonMap["End_Game_button"]->isPressed())
        this->closeScene();
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

    buttonMap["new_game_button"] = new Button(100.f,100.f,150.f,50.f, "New Game", &this->Font,
                            sf::Color(70,70,70,200), sf::Color(150,150,150,255),
                            sf::Color(20,20,20,200)
                );
    buttonMap["settings_button"] = new Button(100.f,180.f,150.f,50.f, "Settings", &this->Font,
                                              sf::Color(70,70,70,200), sf::Color(150,150,150,255),
                                              sf::Color(20,20,20,200)
    );
    buttonMap["End_Game_button"] = new Button(100.f,250.f,150.f,50.f, "End Game", &this->Font,
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




