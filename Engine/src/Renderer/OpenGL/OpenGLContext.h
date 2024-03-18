//
// Created by Let'sBlend on 11/03/2024.
//

#ifndef CLOSINGIN_OPENGLCONTEXT_H
#define CLOSINGIN_OPENGLCONTEXT_H

class GLFWwindow;

class OpenGLContext
{
public:
    void StartUp(GLFWwindow* window);
    void SwapBuffers();

private:
    GLFWwindow* m_Window;
};


#endif //CLOSINGIN_OPENGLCONTEXT_H
