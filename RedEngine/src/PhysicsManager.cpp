#include "PhysicsManager.h"

PhysicsManager* PhysicsManager::INSTANCE = nullptr;

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
