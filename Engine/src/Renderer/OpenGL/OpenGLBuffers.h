//
// Created by Let'sBlend on 12/03/2024.
//

#ifndef CLOSINGIN_OPENGLBUFFERS_H
#define CLOSINGIN_OPENGLBUFFERS_H


class OpenGLVertexBuffer
{
public:
    OpenGLVertexBuffer(const void* vertices, uint32 size);
    ~OpenGLVertexBuffer();

    void Bind();
    void UnBind();
    uint32 GetID();

private:
    uint32 vertexBufferID;
};

class OpenGLIndexBuffer
{
public:
    OpenGLIndexBuffer(const void* indices, uint32 size);
    ~OpenGLIndexBuffer();

    void Bind();
    void UnBind();
    uint32 GetID();

private:
    uint32 indexBufferID;
};

// TODO: More Buffer type options...

#endif //CLOSINGIN_OPENGLBUFFERS_H
