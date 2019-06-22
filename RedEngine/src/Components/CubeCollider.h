#pragma once
#include "Collider.h"

class CubeCollider : public Collider {
public:
    CubeCollider(glm::vec3 offset, glm::vec3 size, glm::vec3 rotation);
    ~CubeCollider();

    virtual void start() override;
	virtual void update() override;
};