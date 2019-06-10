#pragma once
#include <vector>
#include <glm/glm.hpp>
#include "Components/Transform.h"

class GameObject {
public:
	const Transform* transform;
protected:
	std::vector<Component*> m_components;
public:
	GameObject(glm::vec3 pos, glm::vec3 rot, glm::vec3 size);
	~GameObject();

	Component* addComponent(Component* component);
	inline std::vector<Component*>* getComponentList() { return &m_components; }
};