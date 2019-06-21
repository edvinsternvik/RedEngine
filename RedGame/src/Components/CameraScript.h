#pragma once
#include <Component.h>

class CameraScript : public Component {
private:
	float walkingSpeed = 2.0f;
	float runningSpeed = 4.0f;
	Transform* transform;
public:
	virtual void start() override {
		transform = (Transform*)gameObject->transform;
	}

	virtual void update() override {
		float speed = Time::getDeltaTime();
		speed *= Input::getKeyDown(GLFW_KEY_LEFT_SHIFT) ? runningSpeed : walkingSpeed;

		if (Input::getKeyDown(GLFW_KEY_W)) transform->move(glm::vec3(0.0f, 0.0f, -speed));
		if (Input::getKeyDown(GLFW_KEY_S)) transform->move(glm::vec3(0.0f, 0.0f, speed));
		if (Input::getKeyDown(GLFW_KEY_A)) transform->move(glm::vec3(-speed, 0.0f, 0.0f));
		if (Input::getKeyDown(GLFW_KEY_D)) transform->move(glm::vec3(speed, 0.0f, 0.0f));
		if (Input::getKeyDown(GLFW_KEY_Q)) transform->move(glm::vec3(0.0f, -speed, 0.0f));
		if (Input::getKeyDown(GLFW_KEY_E)) transform->move(glm::vec3(0.0f, speed, 0.0f));
		

		if (!Input::getCursorEnabled()) {
			double xpos, ypos;
			Input::getMouseDelta(xpos, ypos);
			transform->rotate(glm::vec3(0.0f, xpos * 0.03f, 0.0f));
		}
	}
};