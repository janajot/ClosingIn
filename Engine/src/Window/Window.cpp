//
// Created by Let'sBlend on 04/03/2024.
//

#include "Window.h"
#include "glfw/glfw3.h"

#include "Events/Event.h"

void Window::StartUp(std::string&& name, int&& width, int&& height)
{
    data.name = std::move(name);
    data.width = width;
    data.height = height;

    if(!glfwInit())
        return; // <- Assertions please Daddy, assert me harder

    window = glfwCreateWindow(width, height, data.name.c_str(), nullptr, nullptr);

    if(!window)
    {
        glfwTerminate();
        return; // <- Die Assertions Bruuuuddaaaaa
    }

    glfwMakeContextCurrent(window);
    glfwSetWindowUserPointer(window, &data);
    SetVSync(data.vsync);

    glfwSetWindowCloseCallback(window, [](GLFWwindow* callback)
    {
        Event::FireEvent(EventType::WindowClose);
    });
    glfwSetWindowSizeCallback(window, [](GLFWwindow* callback, int width, int height)
    {
        auto* pData = (WindowData*)glfwGetWindowUserPointer(callback);
        pData->width = width;
        pData->height = height;

        EventContext e{};
        e.uint16[0] = width;
        e.uint16[1] = height;
        Event::FireEvent(EventType::WindowResize, e);
    });
    glfwSetWindowPosCallback(window, [](GLFWwindow* callback, int xpos, int ypos)
    {
        auto* pData = (WindowData*)glfwGetWindowUserPointer(callback);
        pData->posX = xpos;
        pData->posY = ypos;

        EventContext e{};
        e.uint16[0] = xpos;
        e.uint16[1] = ypos;
        Event::FireEvent(EventType::WindowMoved, e);
    });
    glfwSetWindowFocusCallback(window, [](GLFWwindow* callback, int focused)
    {
        auto* pData = (WindowData*)glfwGetWindowUserPointer(callback);
        pData->focused = focused;

        EventContext e{};
        e.int8[0] = (int8_t)focused;
        Event::FireEvent(EventType::WindowFocus, e);
    });
    glfwSetCharCallback(window, [](GLFWwindow* window, unsigned int codepoint)
    {
        EventContext e{};
        e.uint32[0] = codepoint;
        Event::FireEvent(EventType::TextInput, e);
    });
    glfwSetKeyCallback(window, [](GLFWwindow* callback, int key, int scancode, int action, int mods)
    {
        EventContext e{};

        switch(action)
        {
            case GLFW_PRESS:
                e.int8[0] = (int8_t)key;
                Event::FireEvent(EventType::KeyPressed, e);
                break;
            case GLFW_RELEASE:
                e.int8[0] = (int8_t)key;
                Event::FireEvent(EventType::KeyReleased, e);
                break;
            case GLFW_REPEAT:
                e.int8[0] = (int8_t)key;
                Event::FireEvent(EventType::KeyPressed, e);
                break;
        }
    });
    glfwSetMouseButtonCallback(window, [](GLFWwindow* callback, int button, int action, int mods)
    {
        EventContext e{};

        switch (action)
        {
            case GLFW_PRESS:
                e.int8[0] = (int8_t)button;
                Event::FireEvent(EventType::KeyPressed, e);
                break;
            case GLFW_RELEASE:
                e.int8[0] = (int8_t)button;
                Event::FireEvent(EventType::KeyReleased, e);
                break;
            case GLFW_REPEAT:
                e.int8[0] = (int8_t)button;
                Event::FireEvent(EventType::KeyPressed, e);
                break;
        }
    });
    glfwSetCursorPosCallback(window, [](GLFWwindow* callback, double xpos, double ypos)
    {
        EventContext e{};
        e.float32[0] = (float)xpos;
        e.float32[1] = (float)ypos;
        Event::FireEvent(EventType::MouseMoved, e);
    });
    glfwSetScrollCallback(window, [](GLFWwindow* callback, double xoffset, double yoffset)
    {
        EventContext e{};
        e.float32[0] = (float)xoffset;
        e.float32[1] = (float)yoffset;
        Event::FireEvent(EventType::MouseScrolled, e);
    });
}

void Window::ShutDown()
{
    glfwTerminate();
}

void Window::UpdateEvents()
{
    glfwPollEvents();
}

void Window::Update()
{
    glfwSwapBuffers(window);
}

void Window::SetVSync(const bool& enabled)
{
    glfwSwapInterval(enabled);
}

bool Window::IsVSync()
{
    return data.vsync;
}

void Window::SetSize(const uint16_t& width, const uint16_t& height)
{
    data.width = width;
    data.height = height;
}

void Window::SetFocus(const bool &focused)
{
    data.focused = focused;
}

GLFWwindow *Window::GetWindow()
{
    return window;
}
