#include "Window.h"
#include "Debug.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);

Window* Window::INSTANCE = nullptr;

Window::Window(int width, int height, const char * title) : m_width(width), m_height(height) {
	if (!glfwInit()) gameEngineDebug("GLFW COULD NOT BE INITIALIZED");

	m_window = glfwCreateWindow(width, height, title, NULL, NULL);

	Window::INSTANCE = this;

	if (!m_window) {
		glfwTerminate();
	}

	glfwSetKeyCallback(m_window, key_callback);
	glfwSetCursorPosCallback(m_window, cursor_pos_callback);

	glfwMakeContextCurrent(m_window);
}

Window::~Window() {
	glfwTerminate();
}

void Window::enableVSync(bool enabled) {
	glfwSwapInterval((int)enabled);
}

void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods) {
	if (window == Window::INSTANCE->getWindow()) {
		if (key > -1 && key < KEYS_MAX) {
			Input::processKeyInput(key, scancode, action, mods);
		}
	}
}

void cursor_pos_callback(GLFWwindow * window, double xpos, double ypos) {
	if (window == Window::INSTANCE->getWindow()) {
		Input::processMouseMovement(xpos, ypos);
	}
}
