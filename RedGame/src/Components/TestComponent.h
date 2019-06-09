#pragma once
#include "Component.h"

class TestComponent : public Component {
private:

public:
	virtual void update() override {
		// getParentGameObject()->rotate(glm::vec3(Time::getDeltaTime() * 10.0f, Time::getDeltaTime() * 10.0f, 0.0f));
	}
};
