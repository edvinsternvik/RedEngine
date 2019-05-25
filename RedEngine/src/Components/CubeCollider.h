#pragma once
#include "Component.h"

class CubeCollider : public Component{
public:
    glm::vec3 offset, size, rotation;
public:
    CubeCollider();
    CubeCollider(glm::vec3 offset, glm::vec3 size, glm::vec3 rotation);
    ~CubeCollider();

    virtual void start() override;
	virtual void update() override;
};