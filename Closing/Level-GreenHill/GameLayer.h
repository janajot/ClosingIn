//
// Created by Let'sBlend on 29/02/2024.
//

#ifndef CLOSING_GAMELAYER_H
#define CLOSING_GAMELAYER_H

#include "SystemsManager/Layer.h"

class GameLayer : public Layer
{
    void OnStartUp() override;
    void OnShutDown() override;

    void OnUpdate() override;
};


#endif //CLOSING_GAMELAYER_H
