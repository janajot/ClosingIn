//
// Created by Let'sBlend on 27/02/2024.
//

#include "Engine.h"

#include "SystemsManager/Layer.h"
#include "SystemsManager/LayerStack.h"
#include "SystemsManager/Scene.h"
#include "SystemsManager/SceneStack.h"

#include "Events/Event.h"
#include "Events/Input.h"

Engine::Engine()
{
    s_Instance = this;
}

Engine::~Engine()
{

}

void Engine::Run()
{
    // Testing Event System
    /////////////////////////////////////////////////////////////////
    Event::StartUp();
    Input::StartUp();
    sceneStack = new SceneStack;

    OnStartUp();
    StartUpScene();

    while (run)
    {
        std::string str;
        std::getline(std::cin, str);
        if(str == "Fire")
            Event::FireEvent(EventType::KeyPressed, nullptr);

        for(Layer* layer : activeScene->layerStack)
            layer->OnUpdate();
    }
    /////////////////////////////////////////////////////////////////
    OnShutDown();
    ShutDownScene();

    delete sceneStack;
    Input::ShutDown();
    Event::ShutDown();
}

void Engine::PushScene(std::string&& name)
{
    sceneStack->PushScene(std::move(name));
}

void Engine::PopScene(std::string&& name)
{
    sceneStack->PopScene(std::move(name));
}

void Engine::SwitchScene(const std::string& name)
{
    for(const std::shared_ptr<Scene>& scene : sceneStack->scenePtrs)
    {
        if(scene->name == name)
            activeScene = scene;
    }

    if(activeScene->layerStack.empty())
        std::cout << "[WARN]: No layer was pushed to active scene!" << std::endl;
}

void Engine::PushLayer(std::string&& scene, Layer *layer)
{
    std::shared_ptr<Scene> getScene = sceneStack->GetScene(std::move(scene));
    getScene->layerStack.PushLayer(layer);
}

void Engine::PopLayer(std::string&& scene, Layer *layer)
{
    std::shared_ptr<Scene> getScene = sceneStack->GetScene(std::move(scene));
    getScene->layerStack.PopLayer(layer);
}

void Engine::StartUpScene()
{
    if(sceneStack->scenePtrs.empty())
        std::cout << "[ERROR]: No scene was pushed!" << std::endl; // We need assertions

    activeScene = sceneStack->scenePtrs[0];

    if(activeScene->layerStack.empty())
        std::cout << "[WARNING]: No layer was pushed to active scene!" << std::endl;
}

void Engine::ShutDownScene()
{
    sceneStack->PopAll();
}

