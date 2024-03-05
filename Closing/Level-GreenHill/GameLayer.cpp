//
// Created by Let'sBlend on 29/02/2024.
//

#include "GameLayer.h"
#include "EngineAPI.h"

void CloseApplication(Listener& listener);

void GameLayer::OnStartUp()
{
    std::cout << "Initialized gamelayer sub system" << std::endl;
}

void GameLayer::OnShutDown()
{
    std::cout << "Shut downed gamelayer sub system" << std::endl;
}

void GameLayer::OnUpdate()
{
    std::cout << "updating gamelayer sub system" << std::endl;
}