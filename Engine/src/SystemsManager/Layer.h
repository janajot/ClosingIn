//
// Created by Let'sBlend on 28/02/2024.
//

#ifndef CLOSING_LAYER_H
#define CLOSING_LAYER_H


class Layer
{
public:
    virtual ~Layer() {}

    virtual void OnAttach() {};
    virtual void OnDetach() {};
    virtual void OnUpdate() {};

protected:
    Layer() {}
};


#endif //CLOSING_LAYER_H
