#pragma once
#include <glm\glm.hpp>
#include <vector>
#include "Light.h"
#include "Model.h"
#include "Components/ObjectRenderer.h"

class GameObjectManager {
private:
	std::vector<GameObject*> m_gameObjectList;
	std::vector<ObjectRenderer*> m_renderList;
	std::vector<Light*> m_lightList;
public:
	GameObjectManager();
	~GameObjectManager();

	GameObject* createGameObject(glm::vec3 pos, glm::vec3 rot);
	GameObject* createGameObject(glm::vec3 pos, glm::vec3 size, glm::vec3 rot, Model* model);
	Light* createLight(glm::vec3 pos);
	Light* createLight(glm::vec3 pos, Model* model);
	inline const std::vector<GameObject*>* getGameObjectList() const { return &m_gameObjectList; };
	inline const std::vector<ObjectRenderer*>* getObjectRendererList() const { return &m_renderList; };
	inline const std::vector<Light*>* getLightList() const { return &m_lightList; }
};