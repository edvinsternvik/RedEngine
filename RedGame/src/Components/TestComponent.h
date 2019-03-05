#pragma once
#include <Component.h>

class TestComponent : public Component {
private:

public:
	
	virtual void update() override {
		//getParentGameObject()->move(glm::vec3(0.0f, 0.0f, getTime));
	}
};