#pragma once
#include <glm/glm.hpp>
#include <vector>
#include "GameObject.h"
#include "Model.h"

class GameObjectManager {
private:
	std::vector<GameObject*> m_gameObjectList;
public:
	GameObjectManager();
	~GameObjectManager();

	GameObject* createGameObject(glm::vec3 pos, glm::vec3 rot);
	GameObject* createGameObject(glm::vec3 pos, glm::vec3 rot, Model* model);
	inline const std::vector<GameObject*>* getGameObjectList() const { return &m_gameObjectList; };
};