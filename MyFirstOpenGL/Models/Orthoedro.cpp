#include "Orthoedro.h"
#include "../Managers/TimeManager.h"
#include <cmath>

Orthoedro::Orthoedro ( )
{
    angle = 0.0f;
    rotationSpeed = 0.1f;
    transform.position = glm::vec3 ( 0.0f , 0.0f , 0.0f );
    transform.scale = glm::vec3 ( 1.5f , 1.0f , 0.5f );
    figure = nullptr;
}

void Orthoedro::Update ( float dt )
{
    float t = TimeManager::Instance ( ).GetTime ( );

    angle += rotationSpeed * dt;

    //Escalado animado por el tiempo de forma sinusoidal
    // He comentado esto porque tiene que desescalarse hasta ser un cubo y después de vuelta, 
    // pero si funciona tal cual descomentalo -> float s = abs ( sin ( t ) ); 
    // PD: aplicale el scaleSpeed y sí o sí tienes que usar el generateScaleMatrix

    if (transform.scale.y <= 0.5f) // si la escala es la natural (la de un cubo) la velocidad de escalado serà positiva
        scaleSpeed = abs(scaleSpeed);
    else if (transform.scale.y >= 1.0f) // si la escala es la del ortoedro inicial (1.5) la velocidad se vuelve negativa
        scaleSpeed *= -1;

    transform.scale = glm::vec3 ( 1.0f, 1.0f + scaleSpeed * dt, 1.0f);

    angle += rotationSpeed * dt;

    //Rotación en Z
    figure->model = matrixGen.GenerateRotationMatrix(AXIS_Z, angle);
    // escalado en Y
    figure->model = matrixGen.GenerateScaleMatrix(transform.scale);
}

void Orthoedro::Draw(GLuint program)
{
    glUniform1f(glGetUniformLocation(program, "windowHeight"),  GLManager::Instance().GetHeight());
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
