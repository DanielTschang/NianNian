#include "SceneSplashScreen.hpp"

SceneSplashScreen::SceneSplashScreen(WorkingDirectory &workingDir, ResourceAllocator<sf::Texture> &textureAllocator,
                                     Window &window, SceneStateMachine &sceneManager):
                                     Scene(window, sceneManager), workingDir(workingDir), switchToState(AllScenes::Empty), currentSeconds(0.f), showForSeconds(3.f), textureAllocator(textureAllocator)
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

void SceneSplashScreen::setSwitchToScene(AllScenes::e_Scenes SceneName)
{
    // Stores the id of the scene that we will transition to.
    switchToState = SceneName;
}

void SceneSplashScreen::Update(const float& deltaTime)
{
    currentSeconds += deltaTime;
    
    if(currentSeconds >= showForSeconds) 
    {
  	// Switch states.
        this->sceneManager.switchTo(switchToState);
    }
}

void SceneSplashScreen::Draw(Window& window)
{
    window.Draw(splashSprite);
}

void SceneSplashScreen::closeScene() {

}

