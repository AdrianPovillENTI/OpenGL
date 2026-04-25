#include "Orthoedro.h"
#include "../Managers/TimeManager.h"
#include <cmath>

Orthoedro::Orthoedro ( )
{
    transform.position = glm::vec3 ( 0.0f , 0.0f , 0.0f );
    transform.scale = glm::vec3 ( 1.5f , 1.0f , 0.5f );
    figure = nullptr;
}

void Orthoedro::Update ( float dt )
{
    float t = TimeManager::Instance ( ).GetTime ( );

    //Rotación en eje Z
    transform.rotation.z += 50.0f * dt;

    //Escalado animado por el tiempo de forma sinusoidal
    float s = abs ( sin ( t ) );

    transform.scale = glm::vec3 ( 1.0f + s , 1.0f + s , 1.0f + s );
}