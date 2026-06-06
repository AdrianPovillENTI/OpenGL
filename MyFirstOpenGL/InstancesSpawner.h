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
	std::vector<ModelObject*> SpawnObjects(std::string type_1, Textures type_1_tex, std::string type_2, Textures type_2_tex, std::string type_3, Textures type_3_tex);

private: 

	std::vector<glm::vec3> spawnPoints =
	{
		glm::vec3(2.f, 0.f, 2.f),
		glm::vec3(-2.f, 0.f, 6.f),
		glm::vec3(0.f, 0.f, 8.f),

		glm::vec3(2.f, 0.f, 0.f),
		glm::vec3(-2.f, 0.f, 0.f),
		glm::vec3(0.f, 0.f, 0.f),

		glm::vec3(-5.f, 0.f, -5.f),
		glm::vec3(1.f, 0.f, -3.f),
		glm::vec3(4.f, 0.f, -1.f),

		glm::vec3(-7.f, 0.f, 2.f),
		glm::vec3(-1.f, 0.f, -2.f),
		glm::vec3(10.f, 0.f, 0.f),

		glm::vec3(-3.f, 0.f, 2.f),
		glm::vec3(3.f, 0.f, -3.f),
		glm::vec3(-6.f, 0.f, 3.f),
	};

	ModelObject* SpawnObject(std::string type, Textures tex, int index);
	glm::vec3 RandomRotation();
	glm::vec3 RandomScale();
};