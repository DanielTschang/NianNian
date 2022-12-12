#include "SceneSplashScreen.hpp"

SceneSplashScreen::SceneSplashScreen(WorkingDirectory& workingDir, SceneStateMachine& sceneManager, Window& window)
: sceneManager(sceneManager), workingDir(workingDir),
window(window), switchToState(0), currentSeconds(0.f), 
showForSeconds(3.f) // We’ll show this splash screen for 3 seconds.
{}

void SceneSplashScreen::onCreate() 
{
    // We’ll initialise our splash screen image here.
    splashTexture.loadFromFile(workingDir.Get() + "test.png");
    splashSprite.setTexture(splashTexture);
    
    sf::FloatRect spriteSize = splashSprite.getLocalBounds();
	
    // Set the origin of the sprite to the centre of the image:
    splashSprite.setOrigin(spriteSize.width * 0.5f, spriteSize.height * 0.5f); 
    splashSprite.setScale(0.5f, 0.5f);
    
    sf::Vector2u windowCentre = window.getCentre();
	
    // Positions sprite in centre of screen:
    splashSprite.setPosition(windowCentre.x, windowCentre.y);
}

void SceneSplashScreen::onActivate()
{
    // Resets the currentSeconds count whenever the scene is activated.
    currentSeconds = 0.f; 
}

void SceneSplashScreen::onDestroy() { }

void SceneSplashScreen::setSwitchToScene(unsigned int id)
{
    // Stores the id of the scene that we will transition to.
    switchToState = id;
}

void SceneSplashScreen::Update(float deltaTime)
{
    currentSeconds += deltaTime;
    
    if(currentSeconds >= showForSeconds) 
    {
  	// Switch states.
        sceneManager.switchTo(switchToState);
    }
}

void SceneSplashScreen::Draw(Window& window)
{
    window.Draw(splashSprite);
}