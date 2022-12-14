#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include "glad.h"

class Camera
{
public:
    Camera();

public:
    void Set3DView();
    void Update();

private:
    glm::mat4 m_view;
    glm::mat4 m_proj;

    glm::vec3 m_position;
    glm::vec3 m_direction;
    glm::vec3 m_up;
};

#endif