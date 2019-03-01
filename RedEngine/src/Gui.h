#pragma once
#include <GLFW/glfw3.h>

class Gui {
private:

public:
	Gui(GLFWwindow* window);
	~Gui();

	void renderGui();
};