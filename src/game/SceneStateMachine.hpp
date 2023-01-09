#ifndef SceneStateMachine_hpp
#define SceneStateMachine_hpp

#include "Scene.hpp"
#include <memory>
#include <iostream>
#include <unordered_map>


#include "Window.hpp"
#include "AllScenes.hpp"

class SceneStateMachine
{
public:
    SceneStateMachine();
    ~SceneStateMachine();

    // will call the correspond methods of the active scene.
    void processInput();
    void Update(const float& deltaTime);
    void LateUpdate(const float& deltaTime);
    void Draw(Window& window);

    // Adds a scene to the state machine and returns the id of that scene.
    void Add(Scene *scene);

    // Transitions to scene with specified id.
    void switchTo(AllScenes::e_Scenes id);

    // Removes scene from state machine.
    void Remove(AllScenes::e_Scenes id);
    bool isEmpty();

private:
    // Stores all the scenes associated with this state machine.
    std::unordered_map<AllScenes::e_Scenes, Scene*> scenes;

    // Stores a reference to the current scene. Used when drawing/updating.
    Scene *curScene;

    // Stores our current scene id. This is incremented whenever a scene is added.
    unsigned int insertedSceneID;
};


#endif