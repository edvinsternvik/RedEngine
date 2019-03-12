#include "Input.h"
#include <vector>
#include "Window.h"
#include <iostream>

Input* Input::INSTANCE = nullptr;

Input::Input() {
	Input::INSTANCE = this;

	setCusorEnabled(true);
	m_isCursorEnabled = true;
}

Input::~Input() {
}

Input * Input::instantiate() {
	if (INSTANCE == nullptr) {
		INSTANCE = new Input;
	}

	return INSTANCE;
}

void Input::getMousePos(double & xpos, double & ypos) {
	xpos = INSTANCE->m_xpos;
	ypos = INSTANCE->m_ypos;
}

void Input::getMouseDelta(double & xpos, double & ypos) {
	xpos = INSTANCE->m_xpos - INSTANCE->m_lastXpos;
	ypos = INSTANCE->m_ypos - INSTANCE->m_lastYpos;
}

void Input::setCusorEnabled(bool isEnabled) {
	int flag = isEnabled ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_DISABLED;
	glfwSetInputMode(Window::INSTANCE->getWindow(), GLFW_CURSOR, flag);
	INSTANCE->m_isCursorEnabled = isEnabled;
}

void Input::processKeyInput(int key, int scancode, int action, int mods) {
	INSTANCE->m_keys[key] = action != GLFW_RELEASE;
}

void Input::processMouseMovement(double xpos, double ypos) {
	INSTANCE->m_xpos = xpos;
	INSTANCE->m_ypos = ypos;
}

void Input::updateInput() {
	m_lastXpos = m_xpos;
	m_lastYpos = m_ypos;

	std::copy(std::begin(m_keys), std::end(m_keys), std::begin(m_keysLast));
}