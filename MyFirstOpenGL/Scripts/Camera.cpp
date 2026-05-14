#include "Camera.h"
#include <glm.hpp>
#include <algorithm>

// Constructor con valores por defecto
Camera::Camera ( )
{
    position = glm::vec3 ( 0.0f , 4.0f , 8.0f );
    target = glm::vec3 ( 0.0f , 0.0f , 0.0f );
    up = glm::vec3 ( 0.0f , 1.0f , 0.0f );

    fov = 45.0f;
    aspectRatio = 16.0f / 9.0f;
    nearPlane = 0.1f;
    farPlane = 100.0f;

    orbitAngle = 0.0f;
    orbitRadius = 8.0f;
    orbitHeight = 4.0f;
    orbitSpeed = 1.0f;
    orbitCenter = glm::vec3 ( 0.0f );

    mode = CameraMode::Orbit;

    dollyTimer = 0.0f;
    dollyDuration = 2.0f;
    dollyStartPos = glm::vec3 ( 0.0f );
    dollyEndPos = glm::vec3 ( 0.0f );
    dollyStartFov = 45.0f;
    dollyEndFov = 70.0f;
    dollyTarget = glm::vec3 ( 0.0f );
}

glm::mat4 Camera::GetViewMatrix ( ) const
{
    return glm::lookAt ( position , target , up );
}

glm::mat4 Camera::GetProjectionMatrix ( ) const
{
    return glm::perspective ( glm::radians ( fov ) , aspectRatio , nearPlane , farPlane );
}

void Camera::SetAspectRatio ( float aspect )
{
    aspectRatio = aspect;
}

void Camera::SetPosition ( const glm::vec3 & newPosition )
{
    position = newPosition;
}

void Camera::SetTarget ( const glm::vec3 & newTarget )
{
    target = newTarget;
}

void Camera::SetFOV ( float newFov )
{
    fov = newFov;
}

glm::vec3 Camera::GetPosition ( ) const
{
    return position;
}

glm::vec3 Camera::GetTarget ( ) const
{
    return target;
}

float Camera::GetFOV ( ) const
{
    return fov;
}

CameraMode Camera::GetMode ( ) const
{
    return mode;
}

void Camera::SetOrbitCenter ( const glm::vec3 & center )
{
    orbitCenter = center;
}

void Camera::SetOrbitRadius ( float radius )
{
    orbitRadius = radius;
}

void Camera::SetOrbitHeight ( float height )
{
    orbitHeight = height;
}

void Camera::SetOrbitSpeed ( float speed )
{
    orbitSpeed = speed;
}

void Camera::ActivateOrbit ( )
{
    mode = CameraMode::Orbit;
}

void Camera::ActivateWideShot ( const glm::vec3 & subjectPosition )
{
    // Plano general
    mode = CameraMode::WideShot;

    target = subjectPosition + glm::vec3 ( 0.0f , 1.2f , 0.0f );
    position = target + glm::vec3 ( 0.0f , 2.0f , 6.0f );

    // FOV amplio para ver bien el cuerpo completo
    fov = 45.0f;
}

void Camera::ActivateDetailShot ( const glm::vec3 & subjectPosition )
{
    // Plano detalle
    mode = CameraMode::DetailShot;

    target = subjectPosition + glm::vec3 ( 0.0f , 1.3f , 0.0f );
    position = target + glm::vec3 ( 1.3f , 1.6f , 3.5f );

    // FOV más cerrado para sensación de detalle
    fov = 25.0f;
}

void Camera::ActivateDollyZoom ( const glm::vec3 & subjectPosition )
{
    mode = CameraMode::DollyZoom;

    dollyTarget = subjectPosition + glm::vec3 ( 0.0f , 1.2f , 0.0f );
    target = dollyTarget;

    // Empezamos más lejos con FOV pequeño
    dollyStartPos = dollyTarget + glm::vec3 ( 0.0f , 1.0f , 6.0f );
    dollyEndPos = dollyTarget + glm::vec3 ( 0.0f , 1.0f , 2.0f );

    dollyStartFov = 25.0f;
    dollyEndFov = 70.0f;

    dollyTimer = 0.0f;

    position = dollyStartPos;
    fov = dollyStartFov;
}

void Camera::Update ( float dt )
{
    switch ( mode )
    {
        case CameraMode::Orbit:
            UpdateOrbit ( dt );
            break;

        case CameraMode::WideShot:
            // Plano fijo: no hace nada por frame
            break;

        case CameraMode::DetailShot:
            // Plano fijo: no hace nada por frame
            break;

        case CameraMode::DollyZoom:
            UpdateDollyZoom ( dt );
            break;
    }
}

void Camera::UpdateOrbit ( float dt )
{
    orbitAngle += dt * orbitSpeed;

    position.x = orbitCenter.x + cos ( orbitAngle ) * orbitRadius;
    position.z = orbitCenter.z + sin ( orbitAngle ) * orbitRadius;
    position.y = orbitCenter.y + orbitHeight;

    target = orbitCenter;
}

void Camera::UpdateDollyZoom ( float dt )
{
    dollyTimer += dt;

    float t = dollyTimer / dollyDuration;
    t = t < 0.0f ? 0.0f : t > 1.0 ? 1.0f : t;
    // Interpolación lineal de posición y FOV
    position = glm::mix ( dollyStartPos , dollyEndPos , t );
    fov = glm::mix ( dollyStartFov , dollyEndFov , t );
    target = dollyTarget;

    // Cuando termina, vuelve a órbita
    if ( t >= 1.0f )
    {
        ActivateOrbit ( );
    }
}