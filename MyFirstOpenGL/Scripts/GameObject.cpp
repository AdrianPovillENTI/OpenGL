#include "GameObject.h"

GameObject::GameObject (glm::vec3 _pos, glm::vec3 _scale, glm::vec3 _rotation)
{
    active = true;

    transform.position = _pos;
    transform.scale = _scale;
    transform.rotation = _rotation;
    rotationSpeed = 1.0f;
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

void GameObject::CreateModelMatrix ( )
{
    glm::mat4 model = glm::mat4 ( 1.0f );

    model = matrixGen.GenerateTranslationMatrix ( transform.position );

    //Rotamos segun el orden del vector primero calcula la X y rota en X si necesita luego la Y y luego la Z
    model *= matrixGen.GenerateRotationMatrix ( AXIS_X , transform.rotation.x );
    model *= matrixGen.GenerateRotationMatrix ( AXIS_Y , transform.rotation.y );
    model *= matrixGen.GenerateRotationMatrix ( AXIS_Z , transform.rotation.z );

    model *= matrixGen.GenerateScaleMatrix ( transform.scale );

    figure->model = model;
}

void GameObject::Draw(GLuint program) 
{
    CreateModelMatrix();

    glUniform1f(glGetUniformLocation(program, "time"), TimeManager::Instance().GetTime());
    glUniform1f(glGetUniformLocation(program, "windowHeight"), HEIGHT);
    glUniform1i(glGetUniformLocation(program, "figureType"), 0);
}