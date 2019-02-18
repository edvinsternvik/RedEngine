#include "Window.h"
#include "Debug.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void cursor_pos_callback(GLFWwindow * window, double xpos, double ypos);

Window* Window::INSTANCE = nullptr;

Window::Window(int width, int height, const char * title, bool enableCursor) : m_width(width), m_height(height) {

	Window::INSTANCE = this;

	if (!glfwInit()) gameEngineDebug("GLFW COULD NOT BE INITIALIZED");

	m_window = glfwCreateWindow(width, height, title, NULL, NULL);

	if (!m_window) {
		glfwTerminate();
	}

	glfwSetKeyCallback(m_window, key_callback);
	glfwSetCursorPosCallback(m_window, cursor_pos_callback);

	setCusorEnabled(enableCursor);
	m_isCursorEnabled = enableCursor;

	glfwMakeContextCurrent(m_window);
}

Window::~Window() {
	glfwTerminate();
}

void Window::getMousePos(double & xpos, double & ypos) {
	xpos = m_xpos;
	ypos = m_ypos;
}

void Window::getMouseDelta(double & xpos, double & ypos) {
	xpos = m_xpos - m_lastXpos;
	ypos = m_ypos - m_lastYpos;
}

void Window::setCusorEnabled(bool isEnabled) {
	int flag = isEnabled ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_DISABLED;
	glfwSetInputMode(m_window, GLFW_CURSOR, flag);
	m_isCursorEnabled = isEnabled;
}

void Window::enableVSync(bool enabled) {
	glfwSwapInterval((int)enabled);
}

void Window::updateInput() {
	m_lastXpos = m_xpos;
	m_lastYpos = m_ypos;

	std::copy(std::begin(m_keys), std::end(m_keys), std::begin(m_keysLast));
}

void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods) {
	if (window == Window::INSTANCE->getWindow()) {
		if (key > -1 && key < KEYS_MAX) {
			Window::INSTANCE->m_keys[key] = action != GLFW_RELEASE;
		}
	}
}

void cursor_pos_callback(GLFWwindow * window, double xpos, double ypos) {
	if (window == Window::INSTANCE->getWindow()) {
		Window::INSTANCE->m_xpos = xpos;
		Window::INSTANCE->m_ypos = ypos;
	}
}
