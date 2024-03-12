//
// Created by Let'sBlend on 28/02/2024.
//

#include "SceneStack.h"

#include "Scene.h"
#include "LayerStack.h"

void SceneStack::PushScene(const std::string& name)
{
    scenePtrs.emplace_back(new Scene(name));
}

void SceneStack::PopScene(const std::string& name)
{
    Ref<Scene> scene = GetScene(name);
    scene->layerStack.PopAll();

    auto id = std::find(scenePtrs.begin(), scenePtrs.end(), scene);
    scenePtrs.erase(id);
}

void SceneStack::PopAll()
{
    for(const Ref<Scene>& scene : scenePtrs)
    {
        scene->layerStack.PopAll();
    }
    scenePtrs.clear();
}

Ref<Scene> SceneStack::GetScene(const std::string& name)
{
    for(int i = (int)scenePtrs.size() - 1; i >= 0; i--)
    {
        if(scenePtrs[i]->name == name)
        {
            return scenePtrs[i];
        }
    }
    std::cout << "[ERROR]: Scene doesn't exist!" << std::endl; // Change to assertion
    return nullptr;
}

Ref<Scene> SceneStack::GetScene(const int& index)
{
    if(index < scenePtrs.size())
        return scenePtrs[index];

    std::cout << "[ERROR]: Scene doesn't exist!" << std::endl; // Change to assertion
    return nullptr;
}

bool SceneStack::Exists(const std::string& name)
{
    for(int i = 0; i < (int)scenePtrs.size(); i++)
    {
        if(scenePtrs[i]->name == name)
        {
            return true;
        }
    }

    return false;
}

void SceneStack::Erase(const std::string &name)
{
    Ref<Scene> scene = GetScene(name);

    auto it = std::find(scenePtrs.begin(), scenePtrs.end(), scene);
    scenePtrs.erase(it);
}
