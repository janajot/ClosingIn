//
// Created by Let'sBlend on 11/03/2024.
//

#ifndef CLOSINGIN_OPENGLRENDERERAPI_H
#define CLOSINGIN_OPENGLRENDERERAPI_H

class GLFWwindow;

class OpenGLRendererAPI
{
public:
    void StartUp();
    void SetViewport(uint16 posX, uint16 posY, uint16 width, uint16 height);

    void ClearColor(const Math::vec4& color);
    void Clear();
};


#endif //CLOSINGIN_OPENGLRENDERERAPI_H
