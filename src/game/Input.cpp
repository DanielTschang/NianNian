#include "Input.hpp"

void Input::Update()
{
    lastFrameKeys.SetMask(thisFrameKeys); //Set lastFramesKeys bits to what is currently stored in thisFramesKeys bits.

    thisFrameKeys.SetBit((int)KEY::LEFT,
                        (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || 
	                    (sf::Keyboard::isKeyPressed(sf::Keyboard::A)));
    
    thisFrameKeys.SetBit((int)KEY::RIGHT,
                        (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || 
            	        (sf::Keyboard::isKeyPressed(sf::Keyboard::D)));
    
    thisFrameKeys.SetBit((int)KEY::UP,
                        (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || 
		         (sf::Keyboard::isKeyPressed(sf::Keyboard::W)));
  
    thisFrameKeys.SetBit((int)KEY::DOWN,
                        (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || 
		                (sf::Keyboard::isKeyPressed(sf::Keyboard::S)));

    thisFrameKeys.SetBit((int)KEY::ESC,
                         (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)));

    thisFrameKeys.SetBit((int)KEY::SHIFT,
                         (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)));

    thisFrameKeys.SetBit((int)KEY::CTL,
                         (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)));


}

bool Input::IsKeyPressed(KEY keycode)
{
    return thisFrameKeys.GetBit(int(keycode));
}

// return true if the key is just pressed
bool Input::IsKeyDown(KEY keycode)
{
    bool lastFrame = lastFrameKeys.GetBit((int)keycode);
    bool thisFrame = thisFrameKeys.GetBit((int)keycode);
    
    return thisFrame && !lastFrame;
}

// Returns true if the key was just released (i.e. registered as 
// pressed last frame but not the current frame).
bool Input::IsKeyUp(KEY keycode)
{
    bool lastFrame = lastFrameKeys.GetBit((int)keycode);
    bool thisFrame = thisFrameKeys.GetBit((int)keycode);
    
    return !thisFrame && lastFrame;
}