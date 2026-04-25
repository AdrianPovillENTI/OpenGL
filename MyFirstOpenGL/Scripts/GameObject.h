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
    float rotationSpeed;
    float angle;
public:
    Figure * figure;

public:
    GameObject ( );
    virtual ~GameObject ( ) = default;

    virtual void Start ( ) { }
    virtual void Update ( float dt ) { }
    virtual void Draw ( GLuint program ) { }

    Transform & GetTransform ( );
    bool IsActive ( ) const;
    void SetActive ( bool state );

    void CreateModelMatrix()

};