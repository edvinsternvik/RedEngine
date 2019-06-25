#include "PhysicsEngine.h"
#include "GameObject.h"
#include "Time.h"
#include <iostream>

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

	for (int i = 0; i < colliders.size(); ++i) {
		for (int j = i + 1; j < colliders.size(); j++) {
			if (colliders[i]->AABB(colliders[j])) {

				if (colliders[i]->isCollidingWith(colliders[j], colliders[i]->getColliderType())) {
					std::cout << "Collision" << std::endl;
				}

			}
		}
	}
}
