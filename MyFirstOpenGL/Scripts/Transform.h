#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>

class Transform
{
#define AXIS_X glm::vec3 ( 1.f, 0.f, 0.f )
#define AXIS_Y glm::vec3 ( 0.f, 1.f, 0.f )
#define AXIS_Z glm::vec3 ( 0.f, 0.f, 1.f )

public:
    glm::vec3 position = glm::vec3 ( 0.f );
    glm::vec3 rotation = glm::vec3 ( 0.f );
    glm::vec3 scale = glm::vec3 ( 0.f );

};

