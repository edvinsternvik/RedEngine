#include "Collider.h"
#include <Scene.h>

Collider::Collider(glm::vec3 offset, glm::vec3 rotation, glm::vec3 scale) : offset(offset), rotation(rotation), scale(scale) {
}

Collider::~Collider() {
}

void Collider::init() {
	gameObject->scene->m_colliders.push_back(this);
}

bool Collider::calculateCollision() {
	return false;
}
