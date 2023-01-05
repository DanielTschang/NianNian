#ifndef NIANNIAN_SCENEMAINMENU_HPP
#define NIANNIAN_SCENEMAINMENU_HPP

#include <SFML/Graphics.hpp>
#include "WorkingDirectory.hpp"
#include "SceneStateMachine.hpp"
#include "Input.hpp"
#include "Window.hpp"
#include "Button.hpp"


class SceneMainMenu : public Scene{
private:
    sf::RectangleShape background;
    sf::Font Font;
public:
    SceneMainMenu();
    SceneMainMenu(WorkingDirectory& workingDir, SceneStateMachine& sceneManager, Window& window);

    //init
    void initFonts();

    //functions
    void onCreate() override;
    void onDestroy() override;

    void processInput() override;
    void Update(const float &deltaTime, Window& window) override;
    void Draw(Window& window) override;
    void LateUpdate(const float &deltaTime) override;
    void closeScene() override;
private:
    WorkingDirectory& workingDir;
    SceneStateMachine sceneManager;
};

#endif //NIANNIAN_SCENEMAINMENU_HPP
