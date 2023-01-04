#ifndef Scene_hpp
#define Scene_hpp

#include "Window.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <map>

class Scene
{
protected:
    bool isClose;
public:
  // Called when scene is created initially . Called once.
  virtual void onCreate() = 0;

  // Called when scene destroyed. Called at most once (if a scene
  // is not removed from the game, this will never be called).
  virtual void onDestroy() = 0;

  // Called whenever a scene is transitioned into. Can be
  // called many times in a typical game cycle.
  virtual void onActivate(){};

  // Called whenever a transition out of a scene occurs.
  // Can be called many times in a typical game cycle.
  virtual void onDeactivate(){};
  // The below functions can be overridden as necessary in our scenes.
  virtual void processInput(){};
  virtual void Update(const float& deltaTime) = 0;
  virtual void LateUpdate(const float& deltaTime){};
  virtual void Draw(Window& window) = 0 ;
  virtual void closeScene() = 0;
};
#endif