#pragma once
#include <vector>
#include "Components/CubeCollider.h"

class PhysicsEngine {
private:
	
public:
	PhysicsEngine();
	~PhysicsEngine();

	void updateRigidbodies(std::vector<Collider*> colliders);
};