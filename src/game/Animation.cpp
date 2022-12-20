//
// Created by danchang11 on 2022/12/16.
//

#include "Animation.hpp"

Animation::Animation() : frames(0), currentFrameIndex(0),currentFrameTime(0.f)
{

}
Animation::Animation(FacingDirection direction) : frames(0), currentFrameIndex(0), currentFrameTime(0.f), direction(direction) { }


void Animation::AddFrame(int textureID, int x, int y,
                         int width, int height, float frameTime)
{
    FrameData data;
    data.id = textureID;
    data.x = x;
    data.y = y;
    data.width = width;
    data.height = height;
    data.displayTimeSeconds = frameTime;

    frames.push_back(data);
}

const FrameData* Animation::GetCurrentFrame() const
{
    if(!frames.empty())
    {
        return &frames[currentFrameIndex];
    }

    return nullptr;
}

bool Animation::UpdateFrame(float deltaTime)
{
    if(!frames.empty())
    {
        currentFrameTime += deltaTime;

        if(currentFrameTime >= frames[currentFrameIndex].displayTimeSeconds)
        {
            currentFrameTime = 0.f;
            IncrementFrame();
            return true;
        }
    }

    return false;
}

void Animation::IncrementFrame()
{
    currentFrameIndex = (currentFrameIndex + 1) % frames.size();
}

void Animation::Reset()
{
    currentFrameIndex = 0;
    currentFrameTime = 0.f;
}

void Animation::SetDirection(FacingDirection dir)
{
    if(direction != dir)
    {
        direction = dir;
        for(auto& f : frames)
        {
            f.x += f.width; // 1
            f.width *= -1;
        }
    }
}

FacingDirection Animation::GetDirection() const
{
    return direction;
}
