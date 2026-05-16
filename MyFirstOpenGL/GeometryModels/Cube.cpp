#include "Cube.h"
#include "../Managers/TimeManager.h"
#include <cmath>
#include <gtc/type_ptr.hpp>

Cube::Cube ( glm::vec3 _pos )
    : GameObject ( _pos , glm::vec3 ( 1.0f ) , glm::vec3 ( 0.0f ) ) ,
    texture ( ) // textura blanca por defecto
{
    figure = FigureFactory::CreateCube ( );

    // Valores base de animación
    rotationSpeed = 50.0f;
    movementSpeed = 0.1f;
}

void Cube::Update ( float dt )
{
    //// Movimiento vertical
    //if ( transform.position.y <= -MOVEMENT_LIMIT || transform.position.y >= MOVEMENT_LIMIT )
    //{
    //    movementSpeed *= -1;
    //}

    //// Desplazamiento vertical
    //transform.position += glm::vec3 ( 0.0f , movementSpeed * dt , 0.0f );

    //// Rotación en Y
    //transform.rotation.y += rotationSpeed * dt;
}

void Cube::Draw ( GLuint program )
{
    GameObject::Draw ( program );

    glUniformMatrix4fv (
        glGetUniformLocation ( program , "model" ) ,
        1 ,
        GL_FALSE ,
        glm::value_ptr ( figure->model )
    );

    // Como el shader multiplica textura * tintColor,
    // si usamos textura blanca y tintColor blanco, el resultado será blanco.
    glUniform3f ( glGetUniformLocation ( program , "tintColor" ) , 1.0f , 1.0f , 1.0f );

    texture.Bind ( 0 );

    // Le decimos al shader que mainTexture debe usar la unidad 0.
    glUniform1i (  glGetUniformLocation ( program , "mainTexture" ) , 0 );

    // Dibujar la figura del cubo
    figure->Draw ( );
}