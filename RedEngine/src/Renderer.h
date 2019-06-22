#pragma once
#include "Shader.h"
#include "Camera.h"
#include "Components/Light.h"
#include "Components/ObjectRenderer.h"

class Renderer {
private:
	Shader* m_shader;
public:
	Renderer(Shader* shader);
	~Renderer();

	void updateCamera(Camera* camera);
	void updateLightPositions(std::vector<Light*>* lights);
	void renderGameObject(ObjectRenderer* objectRenderer);
private:
};