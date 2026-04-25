#include "Game.h"
#include "../Models/Cube.h"
#include "../Models/Orthoedro.h"
#include "../Models/Pyramid.h"

Game::Game ( ) { }

Game::~Game ( )
{
    for ( auto obj : gameObjects )
        delete obj;
}
void Game::Start ( )
{
    gameObjects.push_back ( new Cube ( ) );
    gameObjects.push_back ( new Orthoedro ( ) );
    gameObjects.push_back ( new Pyramid ( ) );
}
void Game::Update ( float dt )
{
    for ( GameObject* obj : gameObjects )
    {
        if ( obj->IsActive ( ) )
            obj->Update ( dt );
    }
}
void Game::Render ( )
{
    for ( GameObject* obj : gameObjects )
    {
        //Si el objeto no esta activo no se dibuja
        if ( !obj->IsActive ( ) )
            continue;

        //Enviamos la matriz de modelo al shader
        glm::mat4 model = obj->GetModelMatrix ( );

        //Obtenemos la ubicación de la variable uniforme "model" en el shader y le enviamos la matriz de modelo
        glUniformMatrix4fv (
            glGetUniformLocation ( shaderPrograms [ 0 ].GetID ( ) , "model" ) ,
            1 ,
            GL_FALSE ,
            glm::value_ptr ( model )
        );

        //Dibujamos la figura
        obj->figure->Draw ( );
    }
}