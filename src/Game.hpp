#pragma once

#include <SFML/Graphics.hpp>
// #include "WorkingDictorry.hpp"
#include "Window.hpp"
#include <iostream>

class Game
{
public:
    void Update();
    void LateUpdate();
    void Draw();
    bool IsRunning() const;
private:
    Window window;
};
