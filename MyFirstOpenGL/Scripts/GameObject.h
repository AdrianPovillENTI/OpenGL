#pragma once
#include "Transform.h"
#include "Figure.h"
#include "MatrixGenerator.h"

class GameObject
{
protected:
    Transform transform;
    MatrixGenerator matrixGen;
    bool active;
public:
    Figure * figure;

public:
    GameObject ( );
    virtual ~GameObject ( ) = default;

    virtual void Start ( ) { }
    virtual void Update ( float dt ) { }

    Transform & GetTransform ( );
    bool IsActive ( ) const;
    void SetActive ( bool state );

    glm::mat4 GetModelMatrix ( );
};