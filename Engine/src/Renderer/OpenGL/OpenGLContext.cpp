//
// Created by Let'sBlend on 11/03/2024.
//

#include "OpenGLContext.h"
#include "glad/glad.h"
#include "glfw/glfw3.h"

void OpenGLContext::StartUp(GLFWwindow* window)
{
    m_Window = window;
    int result = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress); // TODO: Assertion here
}

void OpenGLContext::SwapBuffers()
{
    glfwSwapBuffers(m_Window);
}