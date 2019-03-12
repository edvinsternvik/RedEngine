#pragma once
#include <Component.h>

class CameraScript : public Component {
public:
	virtual void update() override {
		float walkingSpeed = Time::getDeltaTime() * 2.0f;
		if (Input::getKeyDown(GLFW_KEY_W)) getParentGameObject()->move(glm::vec3(0.0f, 0.0f, -walkingSpeed));
		if (Input::getKeyDown(GLFW_KEY_S)) getParentGameObject()->move(glm::vec3(0.0f, 0.0f, walkingSpeed));
		if (Input::getKeyDown(GLFW_KEY_A)) getParentGameObject()->move(glm::vec3(-walkingSpeed, 0.0f, 0.0f));
		if (Input::getKeyDown(GLFW_KEY_D)) getParentGameObject()->move(glm::vec3(walkingSpeed, 0.0f, 0.0f));
		if (Input::getKeyDown(GLFW_KEY_Q)) getParentGameObject()->move(glm::vec3(0.0f, -walkingSpeed, 0.0f));
		if (Input::getKeyDown(GLFW_KEY_E)) getParentGameObject()->move(glm::vec3(0.0f, walkingSpeed, 0.0f));

		if (!Input::getCursorEnabled()) {
			double xpos, ypos;
			Input::getMouseDelta(xpos, ypos);
			getParentGameObject()->rotate(glm::vec3(0.0f, xpos * 0.03f, 0.0f));
		}
	}
};