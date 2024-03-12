//
// Created by Let'sBlend on 28/02/2024.
//

#ifndef CLOSING_LAYERSTACK_H
#define CLOSING_LAYERSTACK_H

class Layer;

class LayerStack
{
public:
    LayerStack() = default;
    ~LayerStack();


    void PushLayer(const Ref<Layer>& layer);
    void PopLayer(const Ref<Layer>& layer);
    void PopAll();

    inline std::vector<Ref<Layer>>::iterator begin() { return layerPtrs.begin(); }
    inline std::vector<Ref<Layer>>::iterator end() { return layerPtrs.end(); }
    inline bool empty() { return layerPtrs.empty(); }

    // After which index do the layers created by the user start
    int userLayerStartIndex = 0;
    // After which index do the layers created by the user start
    int userLayerEndIndex = 0;
private:
    std::vector<Ref<Layer>> layerPtrs;
};


#endif //CLOSING_LAYERSTACK_H
