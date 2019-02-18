#pragma once
#include "GameObject.h"

class Light : public GameObject {
public:
	Light(glm::vec3 pos);
	Light(glm::vec3 pos, Model* model);
	~Light();
};

