#include "PhysicsEngine.h"
#include "GameObject.h"
#include "Time.h"

PhysicsEngine::PhysicsEngine() {
}

PhysicsEngine::~PhysicsEngine() {
}

void PhysicsEngine::updateRigidbodies(std::vector<Rigidbody*>& rigidbodies, std::vector<Collider*>& colliders) {
	float deltaTime = Time::getDeltaTime();

	for(Rigidbody* rb : rigidbodies) {
		rb->velocity += glm::vec3(0, 1, 0) * gravity * rb->gravityScale * deltaTime;
		rb->velocity -= rb->velocity * rb->drag * deltaTime;

		rb->gameObject->transform->move(rb->velocity * deltaTime);
	}
}
