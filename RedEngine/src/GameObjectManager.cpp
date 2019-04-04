#include "GameObjectManager.h"

GameObjectManager::GameObjectManager() {
}

GameObjectManager::~GameObjectManager() {
	for (GameObject* go : m_gameObjectList) {
		delete go;
	}
}

GameObject * GameObjectManager::createGameObject(glm::vec3 pos, glm::vec3 rot) {
	m_gameObjectList.push_back(new GameObject(pos, rot, glm::vec3(1.0f)));
	return m_gameObjectList.back();
}

GameObject * GameObjectManager::createGameObject(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale, Model * model) {
	GameObject* newGameObject = new GameObject(pos, rot, scale);
	m_gameObjectList.push_back(newGameObject);

	ObjectRenderer* newObjectRenderer = new ObjectRenderer(model);
	newGameObject->addComponent(newObjectRenderer);
	m_renderList.push_back(newObjectRenderer);

	return newGameObject;
}

Light * GameObjectManager::createLight(glm::vec3 pos) {
	m_lightList.push_back(new Light(pos));
	return m_lightList.back();
}

Camera * GameObjectManager::createCamera(glm::vec3 pos, glm::vec3 rot, CameraType cameraType, glm::vec2 windowSize) {
	Camera* camera = new Camera(pos, rot, cameraType, windowSize);
	m_gameObjectList.push_back(camera);
	return camera;
}
