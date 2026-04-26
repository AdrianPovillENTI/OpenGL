#pragma once
#include "Transform.h"
#include "Figure.h"
#include "MatrixGenerator.h"
#include "FigureFactory.h"
#include "../managers/GLManager.h"
#include "../managers/TimeManager.h"

class GameObject
{
protected:
    Transform transform;
    MatrixGenerator matrixGen;
    bool active;
    float rotationSpeed;

public:
    Figure * figure;

public:
    GameObject(glm::vec3 _pos, glm::vec3 _scale, glm::vec3 _rotation);
    virtual ~GameObject ( ) = default;

    virtual void Update ( float dt ) { }
    virtual void Draw(GLuint program);

    Transform & GetTransform ( );
    bool IsActive ( ) const;
    void SetActive ( bool state );

    void CreateModelMatrix ( ); 
};