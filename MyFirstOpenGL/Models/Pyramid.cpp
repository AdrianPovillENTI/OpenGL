#include "Pyramid.h"
#include "../Managers/TimeManager.h"
#include <cmath>

Pyramid::Pyramid ( )
{
    angle = 0.0f;
    rotationSpeed = 0.1f;
    transform.position = glm::vec3 ( 1.5f , 0.0f , 0.0f );
    transform.scale = glm::vec3 ( 1.0f );
    figure = nullptr;
}

void Pyramid::Update ( float dt )
{
    float t = TimeManager::Instance ( ).GetTime ( );

    //Movimiento vertical
    transform.position += glm::vec3(0.0f, movementSpeed * dt, 0.0f);
    angle += rotationSpeed * dt;

    figure->model = matrixGen.GenerateTranslationMatrix(transform.position);
    //Rotación en X e Y
    figure->model = matrixGen.GenerateRotationMatrix(AXIS_Y + AXIS_X, angle);
}

void Pyramid::Draw(GLuint program)
{
    glUniform1f(glGetUniformLocation(program, "windowHeight"), 0 /* Poner aquí el screen height */);
    glUniform1i(glGetUniformLocation(program, "figureType"), 1); // o 1
    glUniform1f(glGetUniformLocation(program, "time"), 0 /* Poner aquí el tiempo */);

    glUniformMatrix4fv(
        glGetUniformLocation(program, "transform"),
        1,
        GL_FALSE,
        glm::value_ptr(figure->model)
    );

    glBindVertexArray(figure->vao);
    glDrawArrays(GL_TRIANGLES, 0, sizeof(figure->vertices));
}

