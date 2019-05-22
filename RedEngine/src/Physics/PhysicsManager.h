#pragma once

class PhysicsManager {
public:
	static PhysicsManager* INSTANCE;
	static float gravity;
public:
	PhysicsManager();
	~PhysicsManager();

	static PhysicsManager* Instantiate();
}; 