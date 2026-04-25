#include "Cube.h"
#include "../Managers/TimeManager.h"
#include <cmath>

Cube::Cube ( )
{
    angle = 0.0f;
    rotationSpeed = 0.1f;
    transform.position = glm::vec3 ( -1.5f , 0.0f , 0.0f );
    transform.scale = glm::vec3 ( 1.0f );
    figure = nullptr;
}

void Cube::Update ( float dt )
{
    float t = TimeManager::Instance ( ).GetTime ( ); //No sé muy bien para qué esto

    // canviamos el transform para pasarselo al generator
    transform.position += glm::vec3(0.0f, movementSpeed * dt , 0.0f); 
    angle += rotationSpeed * dt; // Con solo el angulo nos tendria que servir para rotar.

    // canviem la matriu model de la figura que després li passarem al vertex shader
    figure->model = matrixGen.GenerateTranslationMatrix(transform.position); 
    figure->model = matrixGen.GenerateRotationMatrix(AXIS_Y, angle); // 
}

void Cube::Draw(GLuint program)
{
    // Passem als shaders els valors

    //Fragment shader
    glUniform1f(glGetUniformLocation(program, "windowHeight"), 0 /* Poner aquí el screen height */);
    glUniform1i(glGetUniformLocation(program, "figureType"), 0); // 0 o 1 depenent de com volem que es pinti (logica al fragmentshader)
    glUniform1f(glGetUniformLocation(program, "time"), 0 /* Poner aquí el tiempo */);

    // Vertex shader 
    glUniformMatrix4fv(
        glGetUniformLocation(program, "transform"),
        1,
        GL_FALSE,
        glm::value_ptr(figure->model)
    );

    // carreguem el vao de la figura
    glBindVertexArray(figure->vao);
    // definim el dibuix i li passem el numero de vertex que té la figura
    glDrawArrays(GL_TRIANGLES, 0, sizeof(figure->vertices));
}
