#pragma once

#include <SFML/Graphics.hpp>

#include "SceneStateMachine.h"
#include "WorkingDirectory.h"

class SceneSplashScreen : public Scene
{
public:
    SceneSplashScreen(WorkingDirectory& workingDir, 
		SceneStateMachine& sceneStateMachine, Window& window);

    void onCreate() override;
    void onDestroy() override;
    
    void onActivate() override;
    
    // Stores the id of the scene that we will transition to.
    void setSwitchToScene(unsigned int id);

    void Update(float deltaTime) override;
    void Draw(Window& window) override;
    
private:
    sf::Texture splashTexture;
    sf::Sprite splashSprite;
    
    WorkingDirectory& workingDir;
    SceneStateMachine& sceneStateMachine;
    Window& window;
    
    // We want to show this scene for a set amount of time
    float showForSeconds;
	
    // How long the scene has currently been visible.
    float currentSeconds;

    // The state we want to transition to when this scenes time expires.
    unsigned int switchToState;
};