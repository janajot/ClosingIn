//
// Created by Let'sBlend on 12/03/2024.
//

#ifndef CLOSINGIN_OPENGLVERTEXARRAY_H
#define CLOSINGIN_OPENGLVERTEXARRAY_H


class OpenGLVertexArray
{
public:
    OpenGLVertexArray();
    ~OpenGLVertexArray();

    void AddVertexBuffer();

    void Bind();
    void UnBind();
    uint32 GetID();

private:
    uint32 vertexArrayID;
};


#endif //CLOSINGIN_OPENGLVERTEXARRAY_H
