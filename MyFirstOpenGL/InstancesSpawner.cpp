#include "InstancesSpawner.h"

std::vector<ModelObject*> InstancesSpawner::SpawnObjects(std::string type_1, Textures type_1_tex, std::string type_2, Textures type_2_tex, std::string type_3, Textures type_3_tex)
{
	std::vector<ModelObject*> objects;

	for (int i = 0; i < spawnPoints.size(); i++)
	{
		int random = rand() % 4;

		switch (random)
		{
		case (0):
			objects.push_back(SpawnObject(type_1, type_1_tex, i));
			break;
		case (1):
			objects.push_back(SpawnObject(type_2, type_2_tex, i));
			break;
		case(2):
			objects.push_back(SpawnObject(type_3, type_3_tex, i));
			break;
		default:
			break;
		}
	}

	return objects;
}

ModelObject* InstancesSpawner::SpawnObject(std::string type, Textures tex, int index)
{
	
	ModelObject* obj = new ModelObject(type, tex, spawnPoints[index], RandomScale(), RandomRotation());
	return obj;
}

glm::vec3 InstancesSpawner::RandomRotation()
{
	glm::vec3 rot = glm::vec3(0.f, 0.f, rand() % 360);
	return rot;
}

glm::vec3 InstancesSpawner::RandomScale()
{
	float x, y, z;

	x = 0.5f + ((float)rand() / RAND_MAX) * (1.5f - 0.5f); // retorna un valor entre 0.5 i 1.5
	y = 0.5f + ((float)rand() / RAND_MAX) * (1.5f - 0.5f); // retorna un valor entre 0.5 i 1.5
	z = 0.5f + ((float)rand() / RAND_MAX) * (1.5f - 0.5f); // retorna un valor entre 0.5 i 1.5

	glm::vec3 scale = glm::vec3(x, y, z);
	return scale;
}
