#pragma once

class PhysicsManager {
public:
	float gravity = 9.82f;
public:
	PhysicsManager();
	~PhysicsManager();

	void calculateCollisions();
}; 