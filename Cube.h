#ifndef CUBE_H
#define CUBE_H

#include <glm/glm.hpp>
#include "glad.h"
#include "Buffer.h"
#include "Texture.h"

class Cube
{
public:
    Cube();
    ~Cube();

    void Update();
    void Render();


    GLfloat defaultVertices[108] = {
        
        // Front
        // Triangle 1
        0.5f, 0.5f, -0.5f, // Right, Up
        -0.5f, 0.5f, -0.5f, // Left, Up
        -0.5f, -0.5f, -0.5f, // Left, Down
        // Triangle 2
        0.5f, -0.5f, -0.5f, // Right, Down
        0.5f,  0.5f, -0.5f, // Right, Up
        -0.5f, -0.5f, -0.5f, // Left, Down

        // Back
        // Triangle 1
        -0.5f, 0.5f, -1.5f, // Right, Up
        0.5f, 0.5f, -1.5f, // Left, Up
        0.5f, -0.5f, -1.5f, // Left, Down
        // Triangle 2
        -0.5f, 0.5f, -1.5f, // Right, Up
        0.5f, -0.5f, -1.5f, // Left, Down
        -0.5f, -0.5f, -1.5f, // Right, Down

        // Left
        // Triangle 1
        -0.5f, 0.5f, -0.5f, // Right, Up
        -0.5f, 0.5f, -1.5f, // Left, Up
        -0.5f, -0.5f, -0.5f, // Left, Down
        // Triangle 2
        -0.5f, -0.5f, -0.5f, // Right, Down
        -0.5f, 0.5f, -1.5f, // Left, Up
        -0.5f, -0.5f, -1.5f, // Left, Down

        // Right
        // Triangle 1
        0.5f, 0.5f, -1.5f, // Right, Up
        0.5f, 0.5f, -0.5f, // Left, Up
        0.5f, -0.5f, -1.5f, // Right, Down
        // Triangle 2
        0.5f, -0.5f, -0.5f, // Left, Down
        0.5f, -0.5f, -1.5f, // Right, Down
        0.5f, 0.5f, -0.5f, // Left, Up

        // Top
        // Triangle 1
        0.5f, 0.5f, -1.5f, // Right, Up
        -0.5f, 0.5f,  -1.5f, // Left, Up
        -0.5f, 0.5f, -0.5f, // Left, Down
        // Triangle 2
        0.5f, 0.5f, -1.5f, // Right, Up
        -0.5f, 0.5f, -0.5f, // Left, Down
        0.5f, 0.5f, -0.5f, // Right, Down

        // Bottom
        // Triangle 1
        0.5f, -0.5f, -0.5f, // Right, Up
        -0.5f, -0.5f,  -0.5f, // Left, Up
        -0.5f, -0.5f, -1.5f, // Left, Down
        // Triangle 2
        0.5f, -0.5f, -0.5f, // Right, Up
        -0.5f, -0.5f, -1.5f, // Left, Down
        0.5f, -0.5f, -1.5f // Right, Down
    };

    GLfloat defaultColors[108] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 1.0f,

        0.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f,

        1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 1.0f,

        0.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f,

        1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 1.0f,

        0.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f,

        1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 1.0f,

        0.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f,

        1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 1.0f,

        0.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f,

        1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 1.0f,

        0.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f
    };

    GLfloat defaultUVs[108] = {
        0.0f, 1.0f,
        1.0f, 1.0f,
        0.0f, 0.0f,
        
        0.0f, 0.0f,
        1.0f, 1.0f,
        1.0f, 0.0f,

        0.0f, 1.0f,
        1.0f, 1.0f,
        0.0f, 0.0f,
        
        0.0f, 0.0f,
        1.0f, 1.0f,
        1.0f, 0.0f,

        0.0f, 1.0f,
        1.0f, 1.0f,
        0.0f, 0.0f,
        
        0.0f, 0.0f,
        1.0f, 1.0f,
        1.0f, 0.0f,

        0.0f, 1.0f,
        1.0f, 1.0f,
        0.0f, 0.0f,
        
        0.0f, 0.0f,
        1.0f, 1.0f,
        1.0f, 0.0f,

        0.0f, 1.0f,
        1.0f, 1.0f,
        0.0f, 0.0f,
        
        0.0f, 0.0f,
        1.0f, 1.0f,
        1.0f, 0.0f,

        0.0f, 1.0f,
        1.0f, 1.0f,
        0.0f, 0.0f,
        
        0.0f, 0.0f,
        1.0f, 1.0f,
        1.0f, 0.0f
    };


private:
    Buffer m_buffer;
    Texture m_texture;
    glm::mat4 m_model;

    glm::vec3 m_position;
};

#endif
