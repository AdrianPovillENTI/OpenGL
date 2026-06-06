#include "DayCycleManager.h"

DayCycleManager::DayCycleManager()
{
	moon = nullptr;
	sun = nullptr;

	rotationSpeed = glm::two_pi<float>() / cycleTime;	// línea donada per ChatGPT amb el promt de la fórmula del moviment circular 
														//per a que faci el moviment en els segons desitjats
}

void DayCycleManager::Update(float dt)
{

	dayTime = std::fmod(dayTime + dt * 0.05f, 1.0f); // Així el valor serà de 0 a < 1 i durarà 20s

	// Fórmula donada per ChatGPT amb el prompt: Quina es la fórmula per a que un objecte faci un moviment circular uniforme sobre el pla X Y?

	angle -= rotationSpeed * dt;

	angle = std::fmod(angle, glm::two_pi<float>()); 

	if (angle < 0.0f)
	{
		angle += glm::two_pi<float>();
	}

	float x, y, z;

	x = rotationCenter.x + cos(angle) * radius;
	y = rotationCenter.y + sin(angle) * radius;
	z = rotationCenter.z;
	
	sun->SetPosition(glm::vec3(x, y, z));
	moon->SetPosition(glm::vec3(-x, -y, z));

	sunlightDirection = glm::normalize(rotationCenter - sun->GetTransform().position);

	if (sun->GetTransform().position.y < rotationCenter.y)
	{
		lightIntensity = 0.f;
	}
	else
	{
		lightIntensity = 1.f;
	}
}

void DayCycleManager::SetMoon(ModelObject* _moon)
{
	moon = _moon;
}

void DayCycleManager::SetSun(ModelObject* _sun)
{
	sun = _sun;
}

glm::vec3 DayCycleManager::GetSunlighDirection()
{
	return sunlightDirection;
}

float DayCycleManager::GetLightIntensity()
{
	return lightIntensity;
}

float DayCycleManager::GetDayTime()
{
	return dayTime;
}
