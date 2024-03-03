//
// Created by Let'sBlend on 27/02/2024.
//

#include "EngineAPI.h"
#include "EntryPoint.h"
#include "Level-GreenHill/GameLayer.h"

class Application : public Engine
{
public:
    void OnStartUp() override
    {
        std::cout << "Initialized application sub system" << std::endl;
        PushScene("GreenHill");
        PushLayer("GreenHill", new GameLayer);
    }

    void OnShutDown() override
    {
        std::cout << "Shut downed application sub system" << std::endl;
    }
};

Engine* CreateApplication()
{
    return new Application;
}
