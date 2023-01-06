#ifndef NIANNIAN_SCENEMAINMENU_HPP
#define NIANNIAN_SCENEMAINMENU_HPP

#include <SFML/Graphics.hpp>
#include "WorkingDirectory.hpp"
#include "SceneStateMachine.hpp"
#include "Input.hpp"
#include "Window.hpp"
#include "Button.hpp"
#include "Button.hpp"
#include "map"
#include <iostream>


class SceneMainMenu : public Scene{
private:
    sf::RectangleShape background;
    sf::Font Font;

    std::map<std::string, Button*> buttonMap;
public:
    SceneMainMenu();
    SceneMainMenu(WorkingDirectory& workingDir, SceneStateMachine& sceneManager, Window& window);
    ~SceneMainMenu();
    //init
    void initFonts();
    void initButtons();

    //functions
    void onCreate() override;
    void onDestroy() override;

    void processInput() override;
    void Update(const float &deltaTime) override;
    void Draw(Window& window) override;
    void closeScene() override;
    void drawButtons();
    void updateButtons();
private:
    WorkingDirectory& workingDir;
    SceneStateMachine sceneManager;
};

#endif //NIANNIAN_SCENEMAINMENU_HPP
