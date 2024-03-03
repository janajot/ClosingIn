//
// Created by Let'sBlend on 27/02/2024.
//

#ifndef APPLICATION_ENGINE_H
#define APPLICATION_ENGINE_H

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

    static void PushScene(const std::string& name);
    static void PopScene(const std::string& name);
    static void SwitchScene(const std::string& name);

    static void PushLayer(const std::string& scene, Layer* layer);
    static void PopLayer(const std::string& scene, Layer* layer);

    inline static bool run = true;
private:
    void StartUpScene();
    void ShutDownScene();

    inline static std::shared_ptr<Scene> activeScene = nullptr;
    inline static SceneStack* sceneStack;

    inline static Engine* s_Instance = nullptr;
};


#endif //APPLICATION_ENGINE_H
