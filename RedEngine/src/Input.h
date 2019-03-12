#pragma once
#define KEYS_MAX 1024
#define MOUSE_BUTTONS_MAX 32

class Input {
private:
	static Input* INSTANCE;

	bool m_keys[KEYS_MAX] = { false };
	bool m_keysLast[KEYS_MAX] = { false };
	bool m_mouseKeys[MOUSE_BUTTONS_MAX] = { false };
	bool m_mouseKeysLast[MOUSE_BUTTONS_MAX] = { false };
	double m_xpos = 0, m_ypos = 0, m_lastXpos = 0, m_lastYpos = 0;
	bool m_isCursorEnabled, m_hasMovedMouse = false;

	Input();
public:
	~Input();

	static Input* instantiate();

	inline static bool getKeyDown(int key) { return INSTANCE->m_keys[key]; }
	inline static bool getKey(int key) { return (INSTANCE->m_keys[key] && !INSTANCE->m_keysLast[key]); }
	static void getMousePos(double& xpos, double& ypos);
	static void getMouseDelta(double& xpos, double& ypos);
	static void setCusorEnabled(bool isEnabled);
	static inline bool getCursorEnabled() { return INSTANCE->m_isCursorEnabled; }

	static void processKeyInput(int key, int scancode, int action, int mods);
	static void processMouseMovement(double xpos, double ypos);
	
	void updateInput();
};