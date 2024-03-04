//
// Created by Let'sBlend on 28/02/2024.
//

#include "SceneStack.h"

#include "Scene.h"
#include "LayerStack.h"

void SceneStack::PushScene(std::string&& name)
{
    scenePtrs.emplace_back(new Scene(std::move(name)));
}

void SceneStack::PopScene(std::string&& name)
{
    std::shared_ptr<Scene> scene = GetScene(std::move(name));
    scene->layerStack.PopAll();

    auto id = std::find(scenePtrs.begin(), scenePtrs.end(), scene);
    scenePtrs.erase(id);
}

void SceneStack::PopAll()
{
    for(const std::shared_ptr<Scene>& scene : scenePtrs)
    {
        scene->layerStack.PopAll();
    }
    scenePtrs.clear();
}

std::shared_ptr<Scene> SceneStack::GetScene(std::string&& name)
{
    for(int i = scenePtrs.size() - 1; i >= 0; i--)
    {
        if(scenePtrs[i]->name == name)
        {
            return scenePtrs[i];
        }
    }
    std::cout << "[ERROR]: Scene doesn't exist!" << std::endl; // Change to assertion
    return nullptr;
}
