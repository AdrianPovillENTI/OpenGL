#include "Orthoedro.h"
#include "../Managers/TimeManager.h"
#include <cmath>

Orthoedro::Orthoedro ( ) : GameObject(glm::vec3(0.0f), glm::vec3(1.0f, 1.5f, 1.0f), glm::vec3(0.0))
{
    figure = FigureFactory::CreateOrthoedro();
    rotationSpeed = 50.0f;
    scaleSpeed = 0.5f;
}

void Orthoedro::Update ( float dt )
{
    transform.scale.y += scaleSpeed * dt;

    if (transform.scale.y >= 1.5f)
    {
        transform.scale.y = 1.5f;
        scaleSpeed = -fabs(scaleSpeed);
    }
    else if (transform.scale.y <= 1.0f)
    {
        transform.scale.y = 1.0f;
        scaleSpeed = fabs(scaleSpeed);
    }

    transform.rotation.z += rotationSpeed * dt;
}

void Orthoedro::Draw(GLuint program)
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
