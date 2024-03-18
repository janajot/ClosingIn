//
// Created by Let'sBlend on 12/03/2024.
//

#ifndef CLOSINGIN_OPENGLSHADERS_H
#define CLOSINGIN_OPENGLSHADERS_H

class OpenGLShader
{
public:
    OpenGLShader();
    ~OpenGLShader();

    void Bind();
    void UnBind();
    uint32 GetID();

private:
    uint32 shaderProgramID;
};

class OpenGLVertexShader
{
public:
    OpenGLVertexShader();
    ~OpenGLVertexShader();

    uint32 GetID();

private:
    uint32 vertexShaderID;
};

class OpenGLPixelShader
{
public:
    OpenGLPixelShader();
    ~OpenGLPixelShader();

    uint32 GetID();

private:
    uint32 pixelShaderID;
};


#endif //CLOSINGIN_OPENGLSHADERS_H
