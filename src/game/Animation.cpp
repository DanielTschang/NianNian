#include "Animation.hpp"

Animation::Animation() :  frames(0), currentFrameIndex(0),currentFrameTime(0.f)
{

}


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



void Animation::SetLooped(bool looped)
{
    isLooped = looped;
}

bool Animation::IsLooped() const
{
    return isLooped;
}

void Animation::AddFrameAction(unsigned int frame, AnimationAction action)
{
    if (frame < frames.size())
    {
        auto actionKey = actions.find(frame);

        if (actionKey == actions.end())
        {
            framesWithActions.SetBit(frame);
            actions.insert(std::make_pair(frame, std::vector<AnimationAction>{action}));
        }
        else
        {
            actionKey->second.emplace_back(action);
        }
    }
}