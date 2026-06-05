#pragma once
#include "Scripts/ModelObject.h"
#include "Scripts/Textures.h"
#include <vector>
#include <string>
#include <glm.hpp>
#include "Scripts/Transform.h"

class InstancesSpawner {

public: 
	InstancesSpawner() = default;

	void SpawnObjects(std::string type_1, Textures type_1_tex, std::string type_2, Textures type_2_tex, std::string type_3, Textures type_3_tex);

private: 

	std::vector<glm::vec3> spawnPoints =
	{
		glm::vec3(100.f, 100.f, 0.f),
		glm::vec3(150.f, 100.f, 0.f),
		glm::vec3(200.f, 100.f, 0.f),

		glm::vec3(120.f, 150.f, 0.f),
		glm::vec3(170.f, 150.f, 0.f),
		glm::vec3(220.f, 150.f, 0.f),

		glm::vec3(-100.f, -100.f, 0.f),
		glm::vec3(-150.f, -100.f, 0.f),
		glm::vec3(-200.f, -100.f, 0.f),

		glm::vec3(-120.f, -100.f, 0.f),
		glm::vec3(-170.f, -100.f, 0.f),
		glm::vec3(-220.f, -100.f, 0.f),
	};

	ModelObject* SpawnObject(std::string type, Textures tex, int index);
	glm::vec3 RandomRotation();
	glm::vec3 RandomScale();
};