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
	return new ModelObject(type, tex, spawnPoints[index], RandomScale(), RandomRotation());
}

glm::vec3 InstancesSpawner::RandomRotation()
{
	glm::vec3 rot = glm::vec3(0.f, rand() % 360, 0.f);
	return rot;
}

glm::vec3 InstancesSpawner::RandomScale()
{

	float _scale = 0.8f + ((float)rand() / RAND_MAX) * (1.1f - 0.8f);

	glm::vec3 scale = glm::vec3(_scale, _scale, _scale);
	return scale;
}
