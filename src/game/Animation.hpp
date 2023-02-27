#ifndef NIANNIAN_ANIMATION_HPP
#define NIANNIAN_ANIMATION_HPP

#include <vector>
#include <iostream>
#include <functional>
#include <map>
#include "Bitmask.hpp"

enum class FacingDirection
{
    None,
    Left,
    Right,
    Up,
    Down
};

enum class AnimationState
{
    None,
    Idle,
    Walk,
    Attack
};


struct FrameData
{
    int id;
    int x;
    int y;
    int width;
    int height;
    float displayTimeSeconds;
};


using AnimationAction = std::function<void(void)>;

class Animation
{
public:
    Animation();

    void AddFrame(int textureID, int x, int y,
                  int width, int height, float frameTime);

    const FrameData* GetCurrentFrame() const;

    bool UpdateFrame(float deltaTime);

    void Reset();

    void SetLooped(bool looped);
    bool IsLooped() const;

    void AddFrameAction(unsigned int frame, AnimationAction action);

private:
    bool isLooped;
    void IncrementFrame();


    // Stores all frames for our animation.
    std::vector<FrameData> frames;

    // Current frame.
    int currentFrameIndex;

    // We use this to decide when to transition to the next frame.
    float currentFrameTime;

    std::map<int, std::vector<AnimationAction>> actions;

    Bitmask framesWithActions;
};

#endif //NIANNIAN_ANIMATION_HPP
