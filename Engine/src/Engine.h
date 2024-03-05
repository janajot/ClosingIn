//
// Created by Let'sBlend on 27/02/2024.
//

#ifndef APPLICATION_ENGINE_H
#define APPLICATION_ENGINE_H

class Listener;

class SceneStack;
class Scene;
class Layer;

class Engine
{
public:
    Engine();
    virtual ~Engine();

    virtual void OnStartUp() {};
    virtual void OnShutDown() {};

    void Run();

    static void PushScene(std::string&& name);
    static void PopScene(std::string&& name);
    static void SwitchScene(const std::string& name);

    // Pushes a layer and calls the OnStartUp function from the layer
    static void PushLayer(std::string&& scene, Layer* layer);
    // Pops a layer and calls the OnShutDown function from the layer
    static void PopLayer(std::string&& scene, Layer* layer);

private:
    void CloseApplication(Listener listener);

    void StartUpScene();
    void ShutDownScene();

    inline static std::shared_ptr<Scene> activeScene = nullptr;
    inline static SceneStack* sceneStack;

    inline static bool run = true;

    inline static Engine* s_Instance = nullptr;
};


#endif //APPLICATION_ENGINE_H
