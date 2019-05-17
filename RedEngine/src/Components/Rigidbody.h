#pragma once
#include <Component.h>

class Rigidbody : public Component {
private:
	GameObject* m_object;
public:
	virtual void start() override;
	virtual void update() override;
};