#include "Rigidbody.h"
#include <Scene.h>

Rigidbody::Rigidbody() : velocity(glm::vec3(0.0f)), gravityScale(1.0f), drag(0.0f) {

}

void Rigidbody::init() {
	gameObject->scene->m_rigidbodies.push_back(this);
}

void Rigidbody::applyForce(glm::vec3 force) {
	velocity += force;
}