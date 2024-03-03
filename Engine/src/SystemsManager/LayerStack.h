//
// Created by Let'sBlend on 28/02/2024.
//

#ifndef CLOSING_LAYERSTACK_H
#define CLOSING_LAYERSTACK_H

class Layer;

class LayerStack
{
public:
    void PushLayer(Layer* layer);
    void PopLayer(Layer* layer);
    void PopAll();

    inline std::vector<Layer*>::iterator begin() { return layerPtrs.begin(); }
    inline std::vector<Layer*>::iterator end() { return layerPtrs.end(); }
    inline bool empty() { return layerPtrs.empty(); }

private:
    std::vector<Layer*> layerPtrs;
};


#endif //CLOSING_LAYERSTACK_H
