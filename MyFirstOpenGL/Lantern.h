#pragma once
#include <glm.hpp>
#include <cmath>

class Lantern {
public:
	Lantern() = default;
	bool activate = false;

private:
	float innerAngle;
	float outerAngle;

	float innerCutoff = cos(glm::radians(innerAngle));
	float innerCutoff = cos(glm::radians(outerAngle));

	float intensity;
	float lightDistance;
};