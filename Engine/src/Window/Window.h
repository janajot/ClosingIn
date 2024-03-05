//
// Created by Let'sBlend on 04/03/2024.
//

#ifndef CLOSING_WINDOW_H
#define CLOSING_WINDOW_H

class GLFWwindow;

class Window
{
public:
    Window() = default;
    ~Window() = default;

    void StartUp(std::string&& name, int&& width, int&& height);
    void ShutDown();

    void Update();
    void VSync(bool enabled);
    bool IsVSync();

private:
    std::string name = "No Name";
    uint16_t width = 640;
    uint16_t height = 480;
    bool vsync = true;

    GLFWwindow* window;
};


#endif //CLOSING_WINDOW_H