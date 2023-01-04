#ifndef SceneSplashScreen_hpp
#define SceneSplashScreen_hpp


#include <SFML/Graphics.hpp>
#include "WorkingDirectory.hpp"
#include <unordered_map>
#include "SceneStateMachine.hpp"
#include "ResourceAllocator.hpp"

class SceneSplashScreen : public Scene
{
public:
    SceneSplashScreen(WorkingDirectory& workingDir, SceneStateMachine& sceneManager, Window& window, ResourceAllocator<sf::Texture>& textureAllocator);

    void onCreate() override;
    void onDestroy() override;
    
    void onActivate() override;
    
    // Stores the id of the scene that we will transition to.
    void setSwitchToScene(unsigned int id);

    void Update(const float& deltaTime) override;
    void Draw(Window& window) override;
    
private:
    sf::Texture splashTexture;
    sf::Sprite splashSprite;
    
    WorkingDirectory& workingDir;
    SceneStateMachine& sceneManager;
    Window& window;
    
    // We want to show this scene for a set amount of time
    float showForSeconds;
	
    // How long the scene has currently been visible.
    float currentSeconds;

    // The state we want to transition to when this scenes time expires.
    unsigned int switchToState;

    ResourceAllocator<sf::Texture>& textureAllocator;
};

#endif