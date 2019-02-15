#pragma once
#include <GLFW/glfw3.h>

#define KEYS_MAX 1024
#define MOUSE_BUTTONS_MAX 32

class Window {
public:
	static Window* INSTANCE;
private:
	GLFWwindow* m_window;
	int m_width, m_height;

	bool m_keys[KEYS_MAX];
	bool m_mouseKeys[MOUSE_BUTTONS_MAX];
	double m_xpos, m_ypos, m_lastXpos, m_lastYpos;
public:
	Window(int width, int height, const char* title, bool enableCursor);
	~Window();

	inline GLFWwindow* getWindow() const { return m_window; }
	inline int getWidth() const { return m_width; }
	inline int getHeight() const { return m_height; }

	inline bool getKey(int key) const { return m_keys[key]; }
	void getMousePos(double& xpos, double& ypos);
	void getMouseDelta(double& xpos, double& ypos);
	void setCusorEnabled(bool isEnabled);
	friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	friend void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);
};