#pragma once
#include <Component.h>

class Rigidbody : public Component {
public:
	glm::vec3 velocity;
private:
	GameObject* m_object;
public:
	virtual void start() override;
	virtual void update() override;
};