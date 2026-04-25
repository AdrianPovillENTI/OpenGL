#pragma once
#include <glm.hpp>
#include <gtc/type_ptr.hpp>
#include <gtc/matrix_transform.hpp>
class MatrixGenerator
{
public:
    MatrixGenerator ( ) = default;
    ~MatrixGenerator ( ) = default;
    glm::mat4 GenerateTranslationMatrix ( glm::vec3 position );
    glm::mat4 GenerateRotationMatrix ( glm::vec3 rotation, float angle );
    glm::mat4 GenerateScaleMatrix ( glm::vec3 scale );
};

