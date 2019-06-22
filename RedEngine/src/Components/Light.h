#pragma once
#include "Component.h"

class Light : public Component {
public:
	float brightness;
public:
	Light(float brightness);
	~Light();

	virtual void init() override;
};

