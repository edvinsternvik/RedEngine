#pragma once
#include "Component.h"

class Rigidbody : public Component {
public:
    glm::vec3 velocity;
    float gravityScale, drag;
public:
    Rigidbody();

    virtual void init() override;

    void applyForce(glm::vec3 force);
};
