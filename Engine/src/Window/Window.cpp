//
// Created by Let'sBlend on 04/03/2024.
//

#include "Window.h"
#include "GLFW/glfw3.h"

void Window::StartUp(std::string&& name, int&& width, int&& height)
{
    this->name = std::move(name);
    this->width = width;
    this->height = height;

    if(!glfwInit())
        return; // <- Assertions please Daddy, assert me harder

    window = glfwCreateWindow(width, height, this->name.c_str(), nullptr, nullptr);

    if(!window)
    {
        glfwTerminate();
        return; // <- Die Assertions Bruuuuddaaaaa
    }

    glfwMakeContextCurrent(window);
}

void Window::ShutDown()
{
    glfwTerminate();
}

void Window::Update()
{
    glfwPollEvents();
    glfwSwapBuffers(window);
}

void Window::VSync(bool enabled)
{
    if(enabled)
        glfwSwapInterval(1);
    else
        glfwSwapInterval(0);
}

bool Window::IsVSync()
{
    return vsync;
}
