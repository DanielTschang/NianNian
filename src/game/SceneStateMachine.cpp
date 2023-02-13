#include "SceneStateMachine.hpp"

SceneStateMachine::SceneStateMachine() : scenes(0), curScene(0) { }

SceneStateMachine::~SceneStateMachine() {

    for (auto it = this->scenes.begin(); it != this->scenes.end(); it++)
    {
        delete it->second;
    }
    scenes.clear();
}

void SceneStateMachine::processInput()
{
    if(curScene)
    {
        curScene->processInput();
    }
}

void SceneStateMachine::Update(const float& deltaTime)
{

    if(curScene)    
    {
        curScene->Update(deltaTime);
    }
}

void SceneStateMachine::LateUpdate(const float& deltaTime)
{
    if(curScene)
    {
        curScene->LateUpdate(deltaTime);
    }
    if(curScene->isClose)
    {
        this->scenes.clear();
    }
}

void SceneStateMachine::Draw(Window& window)
{
    if(curScene)
    {
        curScene->Draw(window);
    }
}


void SceneStateMachine::Add(Scene *scene, AllScenes::e_Scenes SceneName)
{
    auto inserted = scenes.insert(std::make_pair(SceneName, scene));

    inserted.first->second->onCreate();

}

void SceneStateMachine::Remove(AllScenes::e_Scenes SceneName)
{
    auto it = scenes.find(SceneName);
    if(it != scenes.end()) //not found
    {
        if(curScene == it->second)
        {
     	    // If the scene we are removing is the current scene, 
            // we also want to set that to a null pointer so the scene 
      	    // is no longer updated.
            curScene = nullptr;
        }
        
        // We make sure to call the OnDestroy method 
        // of the scene we are removing.
        it->second->onDestroy();
        
        scenes.erase(it);
    }
}

void SceneStateMachine::switchTo(AllScenes::e_Scenes SceneName)
{
    auto it = scenes.find(SceneName);
    if(it != scenes.end())
    {
        if(curScene)
        {
      	    // If we have a current scene, we call its onDeactivate method.
            curScene->onDeactivate(); 
        }
        
        // Setting the current scene ensures that it is updated and drawn.
        curScene = it->second; 
        
        curScene->onActivate();
    }
}

bool SceneStateMachine::isEmpty() {
    if(this->curScene == nullptr) return true;
    return false;
}


