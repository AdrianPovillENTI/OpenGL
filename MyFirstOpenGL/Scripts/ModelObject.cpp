#include "ModelObject.h"
#include <gtc/type_ptr.hpp>

ModelObject::ModelObject (
    const Model model ,
    const Textures texture ,
    glm::vec3 position ,
    glm::vec3 scale ,
    glm::vec3 rotation ,
    glm::vec3 tintColor
)
    : GameObject ( position , scale , rotation ) , model ( model ) , texture ( texture ) , tintColor ( tintColor )
{
}
void ModelObject::Draw ( GLuint program )
{
    // Construimos aquí la matriz modelo manualmente.
    glm::mat4 modelMatrix = glm::mat4 ( 1.0f );

    modelMatrix = matrixGen.GenerateTranslationMatrix ( transform.position );
    modelMatrix *= matrixGen.GenerateRotationMatrix ( AXIS_X , transform.rotation.x );
    modelMatrix *= matrixGen.GenerateRotationMatrix ( AXIS_Y , transform.rotation.y );
    modelMatrix *= matrixGen.GenerateRotationMatrix ( AXIS_Z , transform.rotation.z );
    modelMatrix *= matrixGen.GenerateScaleMatrix ( transform.scale );

    // Enviar la matriz model al shader
    glUniformMatrix4fv (
        glGetUniformLocation ( program , "model" ) ,
        1 ,
        GL_FALSE ,
        glm::value_ptr ( modelMatrix )
    );


    // Enviar el color de tinte al fragment shader
    glUniform3fv (
        glGetUniformLocation ( program , "tintColor" ) ,
        1 ,
        glm::value_ptr ( tintColor )
    );
    // Textura en la unidad 0
    texture.Bind ( 0 );
    glUniform1i ( glGetUniformLocation ( program , "mainTexture" ) , 0 );
    // Dibujar el modelo
    model.Render ( );
}