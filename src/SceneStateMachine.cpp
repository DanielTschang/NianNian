
#include "SceneStateMachine.h"

SceneStateMachine::SceneStateMachine() : scenes(0), curScene(0) { }

void SceneStateMachine::processInput()
{
    if(curScene)
    {
        curScene->processInput();
    }
}

void SceneStateMachine::Update(float deltaTime)
{
    if(curScene)    
    {
        curScene->Update(deltaTime);
    }
}

void SceneStateMachine::lateUpdate(float deltaTime)
{
    if(curScene)
    {
        curScene->lateUpdate(deltaTime);
    }
}

void SceneStateMachine::Draw(Window& window)
{
    if(curScene)
    {
        curScene->Draw(window);
    }
}


unsigned int SceneStateMachine::Add(std::shared_ptr<Scene> scene)
{
    auto inserted = scenes.insert(std::make_pair(insertedSceneID, scene));
    
    // insertedSceneID++;

    inserted.first->second->onCreate(); //inserted.first point to the scene that you just inseted, inserted.second is a boolean, if insert is successed, it will be true
    
    // return insertedSceneID - 1;
    return insertedSceneID++;
}

void SceneStateMachine::Remove(unsigned int id)
{
    auto it = scenes.find(id);
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

void SceneStateMachine::switchTo(unsigned int id)
{
    auto it = scenes.find(id);
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