#pragma once

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

// Modos de cámara que usaremos en la práctica
enum class CameraMode
{
    Orbit ,          // cámara orbitando la escena
    WideShot ,       // plano general al troll izquierdo
    DetailShot ,     // plano detalle al troll derecho
    DollyZoom       // dolly zoom al troll central
};

class Camera
{
private:
    // Posición actual de la cámara
    glm::vec3 position;

    // Vector up
    glm::vec3 up;

    // Campo de visión
    float fov;

    // Proyección
    float aspectRatio;
    float nearPlane;
    float farPlane;

    // Datos de órbita
    float orbitAngle;
    float orbitRadius;
    float orbitHeight;
    float orbitSpeed;
    glm::vec3 orbitCenter;

    // Datos del modo actual
    CameraMode mode;

    // Datos para dolly zoom
    float dollyTimer;
    float dollyDuration;

    glm::vec3 dollyStartPos;
    glm::vec3 dollyEndPos;

    float dollyStartFov;
    float dollyEndFov;

    glm::vec3 dollyTarget;

public:
    Camera ( );

    // Matrices
    glm::mat4 GetViewMatrix ( ) const;
    glm::mat4 GetProjectionMatrix ( ) const;

    // Setters generales
    void SetAspectRatio ( float aspect );
    void SetPosition ( const glm::vec3 & newPosition );
    void SetTarget ( const glm::vec3 & newTarget );
    void SetFOV ( float newFov );

    // Getters
    glm::vec3 GetPosition ( ) const;
    glm::vec3 GetTarget ( ) const;
    float GetFOV ( ) const;
    CameraMode GetMode ( ) const;

    // Configuración de la órbita
    void SetOrbitCenter ( const glm::vec3 & center );
    void SetOrbitRadius ( float radius );
    void SetOrbitHeight ( float height );
    void SetOrbitSpeed ( float speed );

    // Activación de modos
    void ActivateOrbit ( );
    void ActivateWideShot ( const glm::vec3 & subjectPosition );
    void ActivateDetailShot ( const glm::vec3 & subjectPosition );
    void ActivateDollyZoom ( const glm::vec3 & subjectPosition );

    // Update general de cámara
    void Update ( float dt );

    void MoveCameraForward(const glm::vec3& newPosition);
private:
    // Helpers internos
    void UpdateOrbit ( float dt );
    void UpdateDollyZoom ( float dt );
};