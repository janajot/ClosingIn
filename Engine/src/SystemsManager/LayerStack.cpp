//
// Created by Let'sBlend on 28/02/2024.
//

#include "LayerStack.h"
#include "Layer.h"

void LayerStack::PushLayer(Layer *layer)
{
    layer->OnStartUp();
    layerPtrs.emplace_back(layer);
}

void LayerStack::PopLayer(Layer *layer)
{
    layer->OnShutDown();
    auto id = std::find(layerPtrs.begin(), layerPtrs.end(), layer);

    delete layer;
    layerPtrs.erase(id);
}

void LayerStack::PopAll()
{
    for(Layer* layer : layerPtrs)
    {
        layer->OnShutDown();
        delete layer;
    }

    layerPtrs.clear();
}
