#pragma once
#include <Component.h>

class CameraScript : public Component {
private:

public:
	virtual void update() override {
		/*float walkingSpeed = getTime()->getDeltaTime() * 2.0f;
		if (getWindow()->getKeyDown(GLFW_KEY_W)) getCamera()->move(glm::vec3(0.0f, 0.0f, -walkingSpeed));
		if (getWindow()->getKeyDown(GLFW_KEY_S)) getCamera()->move(glm::vec3(0.0f, 0.0f, walkingSpeed));
		if (getWindow()->getKeyDown(GLFW_KEY_A)) getCamera()->move(glm::vec3(-walkingSpeed, 0.0f, 0.0f));
		if (getWindow()->getKeyDown(GLFW_KEY_D)) getCamera()->move(glm::vec3(walkingSpeed, 0.0f, 0.0f));
		if (getWindow()->getKeyDown(GLFW_KEY_Q)) getCamera()->move(glm::vec3(0.0f, -walkingSpeed, 0.0f));
		if (getWindow()->getKeyDown(GLFW_KEY_E)) getCamera()->move(glm::vec3(0.0f, walkingSpeed, 0.0f));

		if (!getWindow()->getCursorEnabled()) {
			double xpos, ypos;
			getWindow()->getMouseDelta(xpos, ypos);
			getCamera()->rotate(glm::vec3(0.0f, xpos * 0.03f, 0.0f));
		}*/
	}
};