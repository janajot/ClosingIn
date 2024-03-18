//
// Created by Let'sBlend on 12/03/2024.
//

#include "OpenGLShaders.h"
#include "glad/glad.h"

/////////////////////////////////////////////////////////////////////
// Vertex & Pixel Shader
/////////////////////////////////////////////////////////////////////

OpenGLShader::OpenGLShader()
{
    OpenGLVertexShader vShader;
    OpenGLPixelShader pShader;

    shaderProgramID = glCreateProgram();

    glAttachShader(shaderProgramID, vShader.GetID());
    glAttachShader(shaderProgramID, pShader.GetID());
    glLinkProgram(shaderProgramID);

    int success;
    char programLog[512];
    glGetProgramiv(shaderProgramID, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(shaderProgramID, 512, nullptr, programLog);
        std::cout << "[ERROR]: Shader did not compile: " << programLog << std::endl;
    }
}

OpenGLShader::~OpenGLShader()
{
    glDeleteProgram(shaderProgramID);
}

void OpenGLShader::Bind()
{
    glUseProgram(shaderProgramID);
}

void OpenGLShader::UnBind()
{
    glUseProgram(0);
}

uint32 OpenGLShader::GetID()
{
    return shaderProgramID;
}

/////////////////////////////////////////////////////////////////////
// Vertex Shader
/////////////////////////////////////////////////////////////////////

OpenGLVertexShader::OpenGLVertexShader()
{
    const char *vertexShaderSource = "#version 330 core\n"
                                     "layout (location = 0) in vec3 aPos;\n"
                                     "void main()\n"
                                     "{\n"
                                     "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                     "}\0";

    vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShaderID, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShaderID);

    int success;
    char shaderLog[512];
    glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertexShaderID, 512, nullptr, shaderLog);
        std::cout << "[ERROR]: Shader did not compile: " << shaderLog << std::endl;
    }
}

OpenGLVertexShader::~OpenGLVertexShader()
{
    glDeleteShader(vertexShaderID);
}

uint32 OpenGLVertexShader::GetID()
{
    return vertexShaderID;
}

/////////////////////////////////////////////////////////////////////
// Pixel Shader
/////////////////////////////////////////////////////////////////////

OpenGLPixelShader::OpenGLPixelShader()
{
    const char *pixelShaderSource = "#version 330 core\n"
                                     "out vec4 FragColor;\n"
                                     "void main()\n"
                                     "{\n"
                                     "FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                     "}\0";

    pixelShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(pixelShaderID, 1, &pixelShaderSource, nullptr);
    glCompileShader(pixelShaderID);

    int success;
    char shaderLog[512];
    glGetShaderiv(pixelShaderID, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(pixelShaderID, 512, nullptr, shaderLog);
        std::cout << "[ERROR]: Shader did not compile: " << shaderLog << std::endl;
    }
}

OpenGLPixelShader::~OpenGLPixelShader()
{
    glDeleteShader(pixelShaderID);
}

uint32 OpenGLPixelShader::GetID()
{
    return pixelShaderID;
}

