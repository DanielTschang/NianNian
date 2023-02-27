#include "C_Sprite.hpp"
#include "Component.hpp"

C_Sprite::C_Sprite(Object* owner) :
        Component(owner),
        currentTextureID(-1)// Set current texture id to -1
{}

void C_Sprite::SetTextureAllocator(ResourceAllocator<sf::Texture>* allocator)
{
    this->allocator = allocator;
}
void C_Sprite::Load(int id)
{
    // Check it's not already our current texture.
    if(id >= 0 && id != currentTextureID)
    {
        currentTextureID = id;
        std::shared_ptr<sf::Texture> texture = allocator->Get(id);
        sprite.setTexture(*texture);
    }
}
void C_Sprite::Load(const std::string& filePath)
{
    if(allocator)
    {
        int textureID = allocator->Add(filePath);

        // Check its not already our current texture.
        if(textureID >= 0 && textureID != currentTextureID)
        {
            currentTextureID = textureID;
            std::shared_ptr<sf::Texture> texture = allocator->Get(textureID);
            sprite.setTexture(*texture);
        }
    }
}
void C_Sprite::Draw(Window& window)
{
    window.Draw(sprite);
}

void C_Sprite::LateUpdate(const float& deltatime)
{
    sprite.setPosition(owner->position->GetPosition());
}

void C_Sprite::SetTextureRect(int x, int y, int width, int height)
{
    sprite.setTextureRect(sf::IntRect(x, y, width, height));
}

void C_Sprite::SetTextureRect(const sf::IntRect& rect)
{
    sprite.setTextureRect(rect);
}

void C_Sprite::SetScale(float x, float y)
{
    sprite.setScale(x, y);
}

sf::Vector2f C_Sprite::getSize() {
    sf::Vector2f size;
    size.x = sprite.getGlobalBounds().width;
    size.y = sprite.getGlobalBounds().height;
    std::cout << size.x << std::endl;
    std::cout << size.y << std::endl;
    return size;
}
