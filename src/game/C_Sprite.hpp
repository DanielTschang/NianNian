#ifndef C_Sprite_hpp
#define C_Sprite_hpp

#include "Component.hpp"
#include "Object.hpp"

class C_Sprite : public Component
{
    public:
    	C_Sprite(Object* owner);

        // Loads a sprite from file.
        void Load(const std::string& filePath);  

        // We override the draw method so we can draw our sprite.
        void Draw(Window& window) override; 

        void LateUpdate(float deltatime) override;

    private:
        sf::Texture texture;
        sf::Sprite sprite;
};

#endif