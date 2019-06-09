#pragma once
#include "Component.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform : public Component {
public:
    glm::vec3 position, rotation, scale;
protected:
    
public:
    Transform(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale);
    ~Transform();

    void move(glm::vec3 movement);
	void setPosition(glm::vec3 position);
	void rotate(glm::vec3 rotation);
	void rotateX(float x);
	void rotateY(float y);
	void rotateZ(float z);
	void setRotation(glm::vec3 rotation);

protected:
	glm::mat4 getForwardMatrix();
};