#include "PhysicsManager.h"

PhysicsManager* PhysicsManager::INSTANCE = nullptr;
float PhysicsManager::gravity = 9.82f;

PhysicsManager::PhysicsManager() {
	PhysicsManager::INSTANCE = this;
}

PhysicsManager::~PhysicsManager() {
}

PhysicsManager* PhysicsManager::Instantiate() {
	if (PhysicsManager::INSTANCE == nullptr) {
		PhysicsManager::INSTANCE = new PhysicsManager();
	}

	return PhysicsManager::INSTANCE;
}
