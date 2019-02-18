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
	m_renderList.push_back(m_gameObjectList.back());
	return m_gameObjectList.back();
}

Light * GameObjectManager::createLight(glm::vec3 pos) {
	m_lightList.push_back(new Light(pos));
	return m_lightList.back();
}

Light * GameObjectManager::createLight(glm::vec3 pos, Model * model) {
	m_lightList.push_back(new Light(pos, model));
	return m_lightList.back();
}
