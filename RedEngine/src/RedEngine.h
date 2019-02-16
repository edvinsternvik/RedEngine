#pragma once
#include <GL/glew.h>

#include "Window.h"
#include "Shader.h"
#include "GameObjectManager.h"
#include "Renderer.h"
#include "Camera.h"
#include "Time.h"
#include "Texture.h"

class RedEngine {
private:
	Window* m_window;
	Camera* m_camera;
	Shader* m_shader;
	GameObjectManager* m_gameObjectManager;
	Renderer* m_renderer;
	Time* m_time;
public:
	RedEngine();
	~RedEngine();

	void init(int width, int height, const char* title, bool enableCursor);
	virtual void start() = 0;
	virtual void update() = 0;
	inline Window* const getWindow() const { return m_window; }
	inline Camera* const getCamera() const { return m_camera; }
	inline Shader* const getShader() const { return m_shader; }
	inline Time* const getTime() const { return m_time;  }
	inline GameObjectManager* const getGameObjectManager() const { return m_gameObjectManager; }
	inline Renderer* const getRenderer() const { return m_renderer; }
private:
	void loop();
};