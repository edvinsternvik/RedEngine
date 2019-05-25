#include "Rigidbody.h"
#include "Time.h"

void Rigidbody::start() {
	m_object = getParentGameObject();
	velocity = glm::vec3(0.0f);
}

void Rigidbody::update() {
}