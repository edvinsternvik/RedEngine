#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#define KEYS_MAX 1024
#define MOUSE_BUTTONS_MAX 32

class Window {
private:
	static Window* INSTANCE;
	GLFWwindow* m_window;
	int m_width, m_height;

	bool m_keys[KEYS_MAX];
	bool m_keysLast[KEYS_MAX];
	bool m_mouseKeys[MOUSE_BUTTONS_MAX];
	bool m_mouseKeysLast[MOUSE_BUTTONS_MAX];
	double m_xpos, m_ypos, m_lastXpos, m_lastYpos;
	bool m_isCursorEnabled;
	Window(int width, int height, const char* title);
public:
	~Window();

	static Window* instantiate(int width, int height, const char* title);
	static Window* const getInstance() { return INSTANCE; }

	inline GLFWwindow* getWindow() const { return m_window; }
	inline int getWidth() const { return m_width; }
	inline int getHeight() const { return m_height; }

	inline bool getKeyDown(int key) const { return m_keys[key]; }
	inline bool getKey(int key) const { return (m_keys[key] && !m_keysLast[key]); }
	void getMousePos(double& xpos, double& ypos);
	void getMouseDelta(double& xpos, double& ypos);
	void setCusorEnabled(bool isEnabled);
	void enableVSync(bool enabled);
	inline bool getCursorEnabled() const { return m_isCursorEnabled; }
	friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	friend void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);
	
	friend class RedEngine;
private:
	void updateInput();
};