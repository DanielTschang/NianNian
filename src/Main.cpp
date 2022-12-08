#include "game/Game.hpp"
#include "game/Component.hpp"

int main()
{
    Game game;
    
    while (game.IsRunning())
    {
        game.getInput();
        game.Update();
        game.LateUpdate();
        game.Draw();
        game.CalculateDeltaTime();
    }
    
    return 0;
}
