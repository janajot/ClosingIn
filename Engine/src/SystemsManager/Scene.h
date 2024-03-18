//
// Created by Let'sBlend on 28/02/2024.
//

#ifndef CLOSING_SCENE_H
#define CLOSING_SCENE_H

#include "LayerStack.h"

class Scene
{
public:
    Scene(const std::string& name) : name(name) {}
    ~Scene() = default;

    std::string name = "None";
    LayerStack layerStack;
};


#endif //CLOSING_SCENE_H
