#include "Camera.h"
#include "../Managers/GLManager.h"

#include <cmath>

Camera::Camera ( )
{
    // Posición inicial
    position = glm::vec3 ( 0.0f , 2.0f , 4.5f );

    // Dirección inicial
    front = glm::vec3 ( 0.0f , 0.0f , -1.0f );

    // Up global
    worldUp = glm::vec3 ( 0.0f , 1.0f , 0.0f );

    // Rotación inicial estilo FPS
    yaw = -90.0f;
    pitch = 0.0f;

    // Configuración del ratón
    mouseSensitivity = 0.05f;
    firstMouse = true;
    lastMousePosition = glm::vec2 ( WIDTH / 2.0f , HEIGHT / 2.0f );

    // Movimiento
    movementSpeed = 5.0f;

    // Proyección
    fov = 45.0f;
    aspectRatio = 16.0f / 9.0f;
    nearPlane = 0.1f;
    farPlane = 100.0f;

    UpdateCameraVectors ( );
}

glm::mat4 Camera::GetViewMatrix ( ) const
{
    return glm::lookAt ( position , position + front , up );
}

glm::mat4 Camera::GetProjectionMatrix ( ) const
{
    return glm::perspective ( glm::radians ( fov ) , aspectRatio , nearPlane , farPlane );
}

void Camera::Update ( float dt )
{
    UpdateMouseLook ( dt );
}

void Camera::UpdateMouseLook ( float dt )
{
    glm::vec2 mousePosition = GLManager::Instance ( ).GetMousePosition ( );

    // Vector desde el centro de la pantalla hasta el ratón
    glm::vec2 mouseDirection = mousePosition - SCREEN_CENTER;

    // Zona muerta para que no rote si el ratón está casi en el centro
    float deadZone = 75.0f;

    if ( glm::length ( mouseDirection ) < deadZone )
    {
        return;
    }

    //Normalizamos la direccion
    float normalizedX = mouseDirection.x / ( WIDTH / 2.0f );
    float normalizedY = mouseDirection.y / ( HEIGHT / 2.0f );

    // Velocidad de rotación en grados por segundo
    float rotationSpeed = 80.0f;

    yaw += normalizedX * rotationSpeed * dt;
    pitch -= normalizedY * rotationSpeed * dt;

    // Limitamos el pitch para evitar que la cámara dé la vuelta
    if ( pitch > 89.0f )
    {
        pitch = 89.0f;
    }

    if ( pitch < -89.0f )
    {
        pitch = -89.0f;
    }

    UpdateCameraVectors ( );
}
void Camera::UpdateCameraVectors ( )
{
    glm::vec3 direction;

    direction.x = cos ( glm::radians ( yaw ) ) * cos ( glm::radians ( pitch ) );
    direction.y = sin ( glm::radians ( pitch ) );
    direction.z = sin ( glm::radians ( yaw ) ) * cos ( glm::radians ( pitch ) );

    front = glm::normalize ( direction );

    right = glm::normalize ( glm::cross ( front , worldUp ) );
    up = glm::normalize ( glm::cross ( right , front ) );
}

void Camera::MoveForward ( float dt )
{
    //Restringimos la Y para que no se mueva hacia arriba o abajo al mirar hacia arriba o abajo
    glm::vec3 moveDirection = glm::vec3 ( front.x , 0.0f , front.z );

    if ( glm::length ( moveDirection ) > 0.0001f )
    {
        moveDirection = glm::normalize ( moveDirection );
        position += moveDirection * movementSpeed * dt;
    }
}
void Camera::MoveBackward ( float dt )
{

    glm::vec3 moveDirection = glm::vec3 ( front.x , 0.0f , front.z );

    if ( glm::length ( moveDirection ) > 0.0001f )
    {
        moveDirection = glm::normalize ( moveDirection );
        position -= moveDirection * movementSpeed * dt;
    }
}

void Camera::MoveRight ( float dt )
{
    position += right * movementSpeed * dt;
}

void Camera::MoveLeft ( float dt )
{
    position -= right * movementSpeed * dt;
}

void Camera::SetPosition ( const glm::vec3 & newPosition )
{
    position = newPosition;
}

void Camera::SetAspectRatio ( float newAspectRatio )
{
    aspectRatio = newAspectRatio;
}

void Camera::SetFOV ( float newFov )
{
    fov = newFov;
}

void Camera::SetMovementSpeed ( float newSpeed )
{
    movementSpeed = newSpeed;
}

void Camera::SetMouseSensitivity ( float newSensitivity )
{
    mouseSensitivity = newSensitivity;
}

glm::vec3 Camera::GetPosition ( ) const
{
    return position;
}

glm::vec3 Camera::GetFront ( ) const
{
    return front;
}

glm::vec3 Camera::GetRight ( ) const
{
    return right;
}

glm::vec3 Camera::GetUp ( ) const
{
    return up;
}

float Camera::GetFOV ( ) const
{
    return fov;
}