#pragma once

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

class Camera
{
private:
    // Posición de la cámara en el mundo
    glm::vec3 position;

    // Dirección hacia donde mira la cámara
    glm::vec3 front;

    // Vector hacia arriba global
    glm::vec3 worldUp;

    // Vector hacia arriba real de la cámara
    glm::vec3 up;

    // Vector derecha de la cámara
    glm::vec3 right;

    // Rotación horizontal
    float yaw;

    // Rotación vertical
    float pitch;

    // Sensibilidad del ratón
    float mouseSensitivity;

    // Velocidad de movimiento
    float movementSpeed;

    // Para evitar salto brusco al iniciar el ratón
    bool firstMouse;
    glm::vec2 lastMousePosition;

    // Proyección
    float fov;
    float aspectRatio;
    float nearPlane;
    float farPlane;

public:
    Camera ( );

    // Matrices
    glm::mat4 GetViewMatrix ( ) const;
    glm::mat4 GetProjectionMatrix ( ) const;

    // Update
    void Update ( float dt );

    // Movimiento
    void MoveForward ( float dt );
    void MoveBackward ( float dt );
    void MoveRight ( float dt );
    void MoveLeft ( float dt );

    // Ratón
    void UpdateMouseLook ( float dt);

    // Setters
    void SetPosition ( const glm::vec3 & newPosition );
    void SetAspectRatio ( float newAspectRatio );
    void SetFOV ( float newFov );
    void SetMovementSpeed ( float newSpeed );
    void SetMouseSensitivity ( float newSensitivity );

    // Getters
    glm::vec3 GetPosition ( ) const;
    glm::vec3 GetFront ( ) const;
    glm::vec3 GetRight ( ) const;
    glm::vec3 GetUp ( ) const;
    float GetFOV ( ) const;

private:
    // Actualiza los vectores de la camara
    void UpdateCameraVectors ( );
};