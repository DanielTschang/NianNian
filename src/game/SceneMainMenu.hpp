//
// Created by danchang11 on 2022/12/12.
//

#ifndef NIANNIAN_SCENEMAINMENU_HPP
#define NIANNIAN_SCENEMAINMENU_HPP

#include <SFML/Graphics.hpp>
#include "WorkingDirectory.hpp"
#include "SceneStateMachine.hpp"
#include "Input.hpp"
#include "Window.hpp"

class WorkingDirectory;

class SceneMainMenu : public Scene{
public:
    SceneMainMenu();
    SceneMainMenu(WorkingDirectory& workingDir, SceneStateMachine& sceneManager, Window& window);
    void onCreate() override;
    void onDestroy() override;

    void processInput() override;
    void Update(float deltaTime) override;
    void Draw(Window& window) override;
    void LateUpdate(float deltaTime) override;
private:
    WorkingDirectory& workingDir;
    Window& window;
    Input input;
    sf::RectangleShape background;
    SceneStateMachine sceneManager;
};

#endif //NIANNIAN_SCENEMAINMENU_HPP
