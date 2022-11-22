#include "Quad.h"
#include "Shader.h"

Quad::Quad()
{
    GLfloat vertices[] = {
        -0.5f,  0.5f, 0.0f, // Left, Up
         0.5f,  0.5f, 0.0f, // Right, Up
        -0.5f, -0.5f, 0.0f, // Left, Down
        -0.5f, -0.5f, 0.0f, // Left, Down
         0.5f,  0.5f, 0.0f, // Right, Up
         0.5f, -0.5f, 0.0f // Right, Down
    };

    GLfloat colors[] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 1.0f,
        0.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f
    };

    m_buffer.CreateBuffer(6);
    m_buffer.FillVBO(Buffer::VERTEX_BUFFER, vertices, sizeof(vertices), Buffer::SINGLE);
    m_buffer.FillVBO(Buffer::COLOR_BUFFER, colors, sizeof(colors), Buffer::SINGLE);

    m_buffer.LinkBuffer("vertexIn", Buffer::VERTEX_BUFFER, Buffer::XYZ, Buffer::FLOAT);
    m_buffer.LinkBuffer("colorIn", Buffer::COLOR_BUFFER, Buffer::RGB, Buffer::FLOAT);
}

Quad::~Quad()
{
    m_buffer.DestroyBuffer();
}

void Quad::Render()
{
    m_buffer.Render(Buffer::TRIANGLES);
}


