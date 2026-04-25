#include "GameObject.h"

GameObject::GameObject ( )
{
    active = true;

    transform.position = glm::vec3 ( 0.0f );
    transform.rotation = glm::vec3 ( 0.0f );
    transform.scale = glm::vec3 ( 1.0f );
}

Transform & GameObject::GetTransform ( )
{
    return transform;
}

bool GameObject::IsActive ( ) const
{
    return active;
}

void GameObject::SetActive ( bool state )
{
    active = state;
}

glm::mat4 GameObject::GetModelMatrix ( )
{
    glm::mat4 model = glm::mat4 ( 1.0f );

    model = matrixGen.GenerateTranslationMatrix ( transform.position );

    //Rotamos segun el orden del vector primero calcula la X y rota en X si necesita luego la Y y luego la Z
    model *= matrixGen.GenerateRotationMatrix ( AXIS_X , transform.rotation.x );
    model *= matrixGen.GenerateRotationMatrix ( AXIS_Y , transform.rotation.y );
    model *= matrixGen.GenerateRotationMatrix ( AXIS_Z , transform.rotation.z );

    model *= matrixGen.GenerateScaleMatrix ( transform.scale );

    return model;
}