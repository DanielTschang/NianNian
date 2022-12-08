#ifndef Input_hpp
#define Input_hpp

#include <SFML/Graphics.hpp>
#include "Bitmask.hpp"

class Input
{    
    public:
        enum class KEY
        {
            NONE = 0,
            LEFT = 1,
            RIGHT = 2,
            UP = 3,
            DOWN = 4,
            ESC = 5
        };


    public:
        bool IsKeyPressed(KEY keycode); // Returns true if the key is pressed.
        bool IsKeyDown(KEY keycode); // Returns true if the key was just pressed.
        bool IsKeyUp(KEY keycode); // Returns true if the key was just released.
        void Update();

    private:
        Bitmask thisFrameKeys;
        Bitmask lastFrameKeys;
};

#endif