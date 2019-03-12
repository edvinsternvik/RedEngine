#pragma once
#include <GLFW/glfw3.h>
#include "Input.h"

class Window {
public:
	static Window* INSTANCE;

private:
	GLFWwindow* m_window;
	int m_width, m_height;
public:
	Window(int width, int height, const char* title);
	~Window();

	inline GLFWwindow* getWindow() const { return m_window; }
	inline int getWidth() const { return m_width; }
	inline int getHeight() const { return m_height; }

	void enableVSync(bool enabled);

	friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	friend void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);
};