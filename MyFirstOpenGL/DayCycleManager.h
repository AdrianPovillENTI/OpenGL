#pragma once
#include "Scripts/ModelObject.h"

class DayCycleManager {

public:
	DayCycleManager();

	void Update(float dt);
	void SetMoon(ModelObject* _moon);
	void SetSun(ModelObject* _sun);
	glm::vec3 GetSunlighDirection();
	float GetLightIntensity();
	float GetDayTime();

private:
	
	float dayTime = 0;
	ModelObject* sun;
	ModelObject* moon;
	glm::vec3 rotationCenter = glm::vec3(0.f, 0.f, 0.f);
	glm::vec3 sunlightDirection = glm::vec3(0.f);

	float angle = glm::radians(90.f);
	float rotationSpeed;
	float radius = 30.f;
	float cycleTime = 20.f; // segons
	float lightIntensity = 1.f;
};