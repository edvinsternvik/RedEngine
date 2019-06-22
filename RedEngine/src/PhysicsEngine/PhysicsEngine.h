#pragma once
#include <vector>
#include "Components/Collider.h"
#include "Components/CubeCollider.h"
#include "Components/Rigidbody.h"

class PhysicsEngine {
public:
	float gravity = -9.82f;
public:
	PhysicsEngine();
	~PhysicsEngine();

	void updateRigidbodies(std::vector<Rigidbody*>& rigidbodies, std::vector<Collider*>& colliders);
};