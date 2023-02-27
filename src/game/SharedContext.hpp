//
// Created by danchang11 on 2023/2/27.
//

#ifndef NIANNIAN_SHAREDCONTEXT_HPP
#define NIANNIAN_SHAREDCONTEXT_HPP

#include "Input.hpp"
#include "WorkingDirectory.hpp"
#include "ResourceAllocator.hpp"
#include "Window.hpp"

class ObjectCollection;

struct SharedContext
{
    Input* input;
    ObjectCollection* objects;
    WorkingDirectory* workingDir;
    ResourceAllocator<sf::Texture>* textureAllocator;
    Window* window;

    ResourceAllocator<sf::Font>* fontAllocator;
};

#endif //NIANNIAN_SHAREDCONTEXT_HPP
