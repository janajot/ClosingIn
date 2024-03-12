//
// Created by Let'sBlend on 29/02/2024.
//

#ifndef CLOSING_GAMELAYER_H
#define CLOSING_GAMELAYER_H

#include "SystemsManager/Layer.h"

class Listener;

class GameLayer : public Layer
{
    void OnAttach() override;
    void OnDetach() override;

    void OnUpdate() override;
};


#endif //CLOSING_GAMELAYER_H
