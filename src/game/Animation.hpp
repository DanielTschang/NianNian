//
// Created by danchang11 on 2022/12/16.
//

#ifndef NIANNIAN_ANIMATION_HPP
#define NIANNIAN_ANIMATION_HPP

#include <vector>

enum class FacingDirection
{
    None,
    Left,
    Right
};


struct FrameData
{
    int id; // Texture id (retrieved from our texture allocator).
    int x; // x position of sprite in the texture.
    int y; // y position of sprite in the texture.
    int width; // Width of sprite.
    int height; // Height of sprite.
    float displayTimeSeconds; // How long to display the frame.
};

class Animation
{
public:
    Animation();
    Animation(FacingDirection direction);
    void AddFrame(int textureID, int x, int y,
                  int width, int height, float frameTime);

    const FrameData* GetCurrentFrame() const;

    bool UpdateFrame(float deltaTime);

    void Reset();

    void SetDirection(FacingDirection dir);
    FacingDirection GetDirection() const;

private:
    FacingDirection direction;
    void IncrementFrame();

    // Stores all frames for our animation.
    std::vector<FrameData> frames;

    // Current frame.
    int currentFrameIndex;

    // We use this to decide when to transition to the next frame.
    float currentFrameTime;
};

#endif //NIANNIAN_ANIMATION_HPP
