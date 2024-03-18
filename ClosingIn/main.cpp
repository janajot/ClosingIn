//
// Created by Let'sBlend on 27/02/2024.
//

#include "EngineInit.h"
#include "Level-GreenHill/GameLayer.h"

class Application : public Engine
{
public:
    void OnStartUp() override
    {
        PushScene("GreenHill");
        PushLayer("GreenHill", CreateRef<GameLayer>());
        std::cout << "Initialized application sub system" << std::endl;
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
