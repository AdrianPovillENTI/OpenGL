#include "Cube.h"
#include "../Managers/TimeManager.h"
#include <cmath>

Cube::Cube ( )
{
    transform.position = glm::vec3 ( -1.5f , 0.0f , 0.0f );
    transform.scale = glm::vec3 ( 1.0f );
    figure = nullptr;
}

void Cube::Update ( float dt )
{
    float t = TimeManager::Instance ( ).GetTime ( );

    //Movimiento vertical
    transform.position.y = sin ( t ) * 0.5f;

    //Rotación en eje Y
    transform.rotation.y += 50.0f * dt;
}