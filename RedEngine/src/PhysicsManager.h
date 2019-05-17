#pragma once

class PhysicsManager {
public:
	static PhysicsManager* INSTANCE;
	float gravity = 9.82f;
public:
	PhysicsManager();
	~PhysicsManager();

	static PhysicsManager* Instantiate();
}; 