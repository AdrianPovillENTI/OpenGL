#include "MatrixGenerator.h"

glm::mat4 MatrixGenerator::GenerateTranslationMatrix ( glm::vec3 position )
{
    return glm::translate ( glm::mat4 ( 1.f ), position );
}
glm::mat4 MatrixGenerator::GenerateRotationMatrix ( glm::vec3 rotation, float angle )
{
    return glm::rotate ( glm::mat4 ( 1.f ), glm::radians ( angle ), glm::normalize ( rotation ) );
}
glm::mat4 MatrixGenerator::GenerateScaleMatrix ( glm::vec3 scale )
{
    return glm::scale ( glm::mat4 ( 1.f ), scale );
}