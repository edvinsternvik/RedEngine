#include "GameObjectManager.h"

GameObjectManager::GameObjectManager() {
}

GameObjectManager::~GameObjectManager() {
	for (GameObject* go : m_gameObjectList) {
		delete go;
	}
}

GameObject * GameObjectManager::createGameObject(glm::vec3 pos, glm::vec3 rot) {
	m_gameObjectList.push_back(new GameObject(pos, rot));
	return m_gameObjectList.back();
}

GameObject * GameObjectManager::createGameObject(glm::vec3 pos, glm::vec3 rot, Model * model) {
	m_gameObjectList.push_back(new GameObject(pos, rot, model));
	return m_gameObjectList.back();
}
