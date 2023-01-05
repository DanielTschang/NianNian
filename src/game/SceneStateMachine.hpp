#ifndef SceneStateMachine_hpp
#define SceneStateMachine_hpp

#include <memory>
#include <iostream>
#include <unordered_map>

#include "Scene.hpp"
#include "Window.hpp"

class SceneStateMachine
{
public:
    SceneStateMachine();
    ~SceneStateMachine();

    // will call the correspond methods of the active scene.
    void processInput();
    void Update(float deltaTime, Window &window);
    void LateUpdate(float deltaTime);
    void Draw(Window& window);

    // Adds a scene to the state machine and returns the id of that scene.
    unsigned int Add(Scene *scene);

    // Transitions to scene with specified id.
    void switchTo(unsigned int id);

    // Removes scene from state machine.
    void Remove(unsigned int id);
    bool isEmpty();

private:
    // Stores all the scenes associated with this state machine.
    std::unordered_map<unsigned int, Scene*> scenes;

    // Stores a reference to the current scene. Used when drawing/updating.
    Scene *curScene;

    // Stores our current scene id. This is incremented whenever a scene is added.
    unsigned int insertedSceneID;
};


#endif