#include "Cube.h"
#include "../Managers/TimeManager.h"
#include <cmath>

Cube::Cube (glm::vec3 _pos) : GameObject(_pos, glm::vec3(1.0f), glm::vec3(0.0f))
{
    figure = FigureFactory::CreateCube();
    rotationSpeed = 50.0f;
    movementSpeed = 0.1f;
}

void Cube::Update ( float dt )
{
    if (transform.position.y <= -0.5f || transform.position.y >= 0.5f)
        movementSpeed *= -1;
    transform.position += glm::vec3(0.0f, movementSpeed * dt, 0.0f);

    transform.rotation.y += rotationSpeed * dt; // canviamos el transform para pasarselo al generator
}

void Cube::Draw(GLuint program)
{
    GameObject::Draw(program);

    glUniformMatrix4fv(
        glGetUniformLocation(program, "model"),
        1,
        GL_FALSE,
        glm::value_ptr(figure->model)
    );

    figure->Draw();
}
