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

	angle += rotationSpeed * dt;

	angle = std::fmod(angle, glm::two_pi<float>()); 

	if (angle < 0.0f)
	{
		angle += glm::two_pi<float>();
	}

	float x, y, z;

	x = rotationCenter.x + cos(angle) * radius;
	y = rotationCenter.y + sin(angle) * radius;
	z = rotationCenter.z;
	
	sun->SetPosition(glm::vec3(-x, -y, z));
	moon->SetPosition(glm::vec3(x, y, z));

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

glm::vec3 DayCycleManager::GetSkyColor()
{
	if (dayTime < 0.1)
	{
		return glm::vec3(0.043f, 0.063f, 0.149f);
	}
	else if(dayTime < 0.2)
	{
		return glm::vec3(0.361f, 0.294f, 0.541f);
	}
	else if (dayTime < 0.3)
	{
		return glm::vec3(0.753f, 0.416f, 0.659f);
	}
	else if (dayTime < 0.4)
	{
		return glm::vec3(0.910f, 0.365f, 0.247f);
	}
	else if (dayTime < 0.6)
	{
		return glm::vec3(0.431f, 0.776f, 1.000f);
	}
	else if (dayTime < 0.7)
	{
		return glm::vec3(0.910f, 0.365f, 0.247f);
	}
	else if (dayTime < 0.8)
	{
		return glm::vec3(0.753f, 0.416f, 0.659f);
	}
	else if (dayTime < 0.9)
	{
		return glm::vec3(0.361f, 0.294f, 0.541f);
	}
	else
	{
		return glm::vec3(0.043f, 0.063f, 0.149f);
	}
}
