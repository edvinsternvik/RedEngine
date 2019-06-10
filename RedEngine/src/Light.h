#pragma once
#include "GameObject.h"

class Light : public GameObject {
public:
	float brightness;
public:
	Light(glm::vec3 pos, float brightness);
	~Light();
};

