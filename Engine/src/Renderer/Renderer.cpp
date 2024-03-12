//
// Created by Let'sBlend on 11/03/2024.
//

#include "Renderer.h"
#include "Events/Event.h"

#include "glad/glad.h"

#include "OpenGL/OpenGLVertexArray.h"
#include "OpenGL/OpenGLBuffers.h"
#include "OpenGL/OpenGLShaders.h"

void Renderer::OnAttach()
{
    glAPI.StartUp();
    Event::RegisterEvent(EventType::WindowResize, this, &Renderer::OnWindowResize);

    // Temporary
    float vertices[] = {
            0.5f,  0.5f, 0.0f,  // top right
            0.5f, -0.5f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f,  // bottom left
            -0.5f,  0.5f, 0.0f   // top left
    };
    unsigned int indices[] = {  // note that we start from 0!
            0, 1, 3,   // first triangle
            1, 2, 3    // second triangle
    };

    vA.Bind();

    OpenGLVertexBuffer vB(vertices, sizeof(vertices));
    OpenGLIndexBuffer iB(indices, sizeof(indices));

    vA.AddVertexBuffer();
    vA.UnBind();
}

void Renderer::OnDetach()
{
    Event::UnregisterEvent(EventType::WindowResize, this, &Renderer::OnWindowResize);
}

void Renderer::OnUpdate()
{
    glAPI.ClearColor(Math::vec4(.6f, .6f, .8f, 1));
    glAPI.Clear();

    // Scene Rendering
    // Temporary
    sh.Bind();
    vA.Bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    vA.UnBind();
    sh.UnBind();

    // Scene Debug Rendering

    // UI Rendering

    // UI Debug Rendering
}

void Renderer::OnWindowResize(Listener& listener)
{
    std::cout << "Window resized " << listener.metaData.ui16[0] << " " << listener.metaData.ui16[1] << std::endl;
    glAPI.SetViewport(0, 0, listener.metaData.ui16[0], listener.metaData.ui16[1]);
}
