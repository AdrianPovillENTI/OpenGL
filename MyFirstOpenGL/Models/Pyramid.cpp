#include "Pyramid.h"
#include "../Managers/TimeManager.h"
#include <cmath>

Pyramid::Pyramid(glm::vec3 _pos) : GameObject(_pos, glm::vec3(1.0f), glm::vec3(0.0f))
{
    figure = FigureFactory::CreatePyramid();
    movementSpeed = 0.1f;
    rotationSpeed = 50.0f;
}

void Pyramid::Update ( float dt )
{
    if (transform.position.y <= -0.5f || transform.position.y >= 0.5f)
        movementSpeed *= -1;

    transform.position.y += movementSpeed * dt;
    transform.rotation.x += rotationSpeed * dt;
    transform.rotation.y += rotationSpeed * dt;
}

void Pyramid::Draw(GLuint program)
{
    GameObject::Draw(program);

    glUniform1i(glGetUniformLocation(program, "figureType"), 1);


    glUniformMatrix4fv(
        glGetUniformLocation(program, "model"),
        1,
        GL_FALSE,
        glm::value_ptr(figure->model)
    );

    figure->Draw();
}

