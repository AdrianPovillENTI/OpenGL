#include "Pyramid.h"
#include "../Managers/TimeManager.h"
#include <cmath>

Pyramid::Pyramid ( )
{
    transform.position = glm::vec3 ( 1.5f , 0.0f , 0.0f );
    transform.scale = glm::vec3 ( 1.0f );
    figure = nullptr;
}

void Pyramid::Update ( float dt )
{
    float t = TimeManager::Instance ( ).GetTime ( );

    //Movimiento vertical
    transform.position.y = sin ( t ) * 0.5f;

    //Rotación en X e Y
    transform.rotation.x += 40.0f * dt;
    transform.rotation.y += 40.0f * dt;
}
int Pyramid::GetColorState ( )
{
    float t = TimeManager::Instance ( ).GetTime ( );

    return ( int ) ( t / 2.0f ) % 3;
}