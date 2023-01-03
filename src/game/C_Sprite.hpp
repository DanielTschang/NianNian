#ifndef C_Sprite_hpp
#define C_Sprite_hpp

#include "Component.hpp"
#include "Object.hpp"
#include "ResourceAllocator.hpp"

class C_Sprite : public Component
{
public:
    C_Sprite(Object* owner);

    void SetTextureAllocator(ResourceAllocator<sf::Texture>* allocator);
    // Loads a sprite from file.
    void Load(int id);
    void Load(const std::string& filePath);

    // We override the draw method so we can draw our sprite.
    void Draw(Window& window) override;

    void LateUpdate(float deltatime) override;
    void SetTextureRect(int x, int y, int width, int height);
    void SetTextureRect(const sf::IntRect& rect);
    void SetScale(float x, float y);

private:
        ResourceAllocator<sf::Texture>* allocator;
        sf::Texture texture;
        sf::Sprite sprite;
        int currentTextureID; // We’ll now keep track of our currently set texture.
};

#endif