#pragma once
#include "Component.h"

class Collider : public Component {
public:
	glm::vec3 offset, rotation, scale;
	
public:
	Collider(glm::vec3 offset, glm::vec3 rotation, glm::vec3 scale);
	~Collider();

	virtual void init() override;

	virtual bool calculateCollision();
};