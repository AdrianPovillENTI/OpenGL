#pragma once
#include "glm.hpp"
#include "Transform.h"

class Player
{
	Transform transform;
public:
	const Transform GetTransform () const;
};

