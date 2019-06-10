#pragma once
#include <GL/glew.h>

#include "Window.h"
#include "Shader.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "Time.h"
#include "Input.h"

class RedEngine {
private:
	Window* m_window;
	Shader* m_shader;
	Renderer* m_renderer;
	SceneManager* m_sceneManager;
	Time* m_time;
	Input* m_input;

public:
	RedEngine();
	~RedEngine();

	void init(int width, int height, const char* title);
	virtual void start() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	inline Window* const getWindow() const { return m_window; }
	inline Shader* const getShader() const { return m_shader; }
	inline Time* const getTime() const { return m_time;  }
	inline SceneManager* const getSceneManager() const { return m_sceneManager; }
	inline Renderer* const getRenderer() const { return m_renderer; }
private:
	void loop();
};