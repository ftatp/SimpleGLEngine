#include <glm/gtc/matrix_transform.hpp>
#include "Cube.h"
#include "Shader.h"
#include "Input.h"

#include <iostream> 

Cube::Cube()
{

    m_buffer.CreateBuffer(36);
    // m_buffer.FillVBO(Buffer::VERTEX_BUFFER, defaultVertices, sizeof(defaultVertices), Buffer::SINGLE);
    // m_buffer.LinkBuffer("vertexIn", Buffer::VERTEX_BUFFER, Buffer::XYZ, Buffer::FLOAT);

    // m_buffer.FillVBO(Buffer::COLOR_BUFFER, defaultColors, sizeof(defaultColors), Buffer::SINGLE);
    // m_buffer.LinkBuffer("colorIn", Buffer::COLOR_BUFFER, Buffer::RGB, Buffer::FLOAT);


    m_buffer.CreateAndLinkVBO(Buffer::VERTEX_BUFFER, defaultVertices, sizeof(defaultVertices), Buffer::SINGLE,
                                "vertexIn", Buffer::XYZ, Buffer::FLOAT);
    m_buffer.CreateAndLinkVBO(Buffer::COLOR_BUFFER, defaultColors, sizeof(defaultColors), Buffer::SINGLE,
                                "colorIn", Buffer::RGB, Buffer::FLOAT);
    m_buffer.CreateAndLinkVBO(Buffer::TEXTURE_BUFFER, defaultUVs, sizeof(defaultUVs), Buffer::SINGLE,
                                "textureIn", Buffer::UV, Buffer::FLOAT);

    m_texture.Load("../Textures/texture.jpg");
    m_position = glm::vec3(0.0f, 0.0f, -1.0f);
}

Cube::~Cube()
{
    m_buffer.DestroyBuffer();
}

void Cube::Update()
{
    if(Input::Instance()->IsKeyPressed())
    {
        char pressedKey = Input::Instance()->GetKeyDown();
        // Direction keys
        if(pressedKey == 'j')
        {
            m_position.x -= 0.01f;
        }
        else if(pressedKey == 'l')
        {
            m_position.x += 0.01f;
        }        
        else if(pressedKey == 'i')
        {
            m_position.z += 0.01f;
        }
        else if(pressedKey == 'k')
        {
            m_position.z -= 0.01f;
        }
        else if(pressedKey == 'u')
        {
            m_position.y += 0.01f;
        }        
        else if(pressedKey == 'o')
        {
            m_position.y -= 0.01f;
        }
    }

    m_model = glm::mat4(1.0f);
    m_model = glm::translate(m_model, m_position);
    //m_model = glm::rotate(m_model, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    //m_model = glm::scale(m_model, glm::vec3(0.5f, 0.5f, 1.0f));
}

void Cube::Render()
{
    //std::cout << m_model. << std::endl;

    Shader::Instance()->SendUniformData("model", m_model);

    m_texture.Bind();
    m_buffer.Render(Buffer::TRIANGLES);
    m_texture.Unbind();
}


