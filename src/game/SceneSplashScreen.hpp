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
    SceneSplashScreen(WorkingDirectory& workingDir, ResourceAllocator<sf::Texture>& textureAllocator, Window& window, SceneStateMachine& sceneManager, Input &input);

    void onCreate() override;
    void onDestroy() override;
    
    void onActivate() override;
    
    // Stores the id of the scene that we will transition to.
    void setSwitchToScene(AllScenes::e_Scenes SceneName);

    void Update(const float& deltaTime) override;
    void Draw(Window& window) override;
    void closeScene() override;
    
private:
    sf::Texture splashTexture;
    sf::Sprite splashSprite;
    
    WorkingDirectory& workingDir;
    
    // We want to show this scene for a set amount of time
    float showForSeconds;
	
    // How long the scene has currently been visible.
    float currentSeconds;

    // The state we want to transition to when this scenes time expires.
    AllScenes::e_Scenes switchToState;

    ResourceAllocator<sf::Texture>& textureAllocator;
};

#endif