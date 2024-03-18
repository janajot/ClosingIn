//
// Created by Let'sBlend on 11/03/2024.
//

#ifndef CLOSINGIN_RENDERER_H
#define CLOSINGIN_RENDERER_H

#include "SystemsManager/Layer.h"

#include "OpenGl/OpenGLRendererAPI.h"
#include "OpenGL/OpenGLVertexArray.h"
#include "OpenGL/OpenGLShaders.h"

class Listener;

class Renderer : public Layer
{
public:
    void OnAttach() override;
    void OnDetach() override;

    void OnUpdate() override;

    void OnWindowResize(Listener& listener);

private:
    OpenGLRendererAPI glAPI;

    // Temporary
    OpenGLVertexArray vA;
    OpenGLShader sh;
};


#endif //CLOSINGIN_RENDERER_H
