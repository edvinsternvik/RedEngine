#pragma once
#include "GameObjectManager.h"
#include "Shader.h"
#include "Camera.h"

class Renderer {
private:
	Camera* m_camera;
	GameObjectManager* m_gameObjectManager;
	Shader* m_shader;
public:
	Renderer(Camera* camera, GameObjectManager* gameObjectManager, Shader* shader);
	~Renderer();

	void renderFrame();
private:
	void renderGameObject(ObjectRenderer* objectRenderer);
	void updateLightPositions();
};