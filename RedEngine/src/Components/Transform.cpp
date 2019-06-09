#include "Transform.h"

Transform::Transform(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale) : position(pos), rotation(rot), scale(scale) {
}

void Transform::move(glm::vec3 movement) {
	position += glm::mat3(getForwardMatrix()) * movement;
}

void Transform::setPosition(glm::vec3 position) {
	this->position = position;
}

void Transform::rotate(glm::vec3 rotation) {
	this->rotation += rotation;
}

void Transform::rotateX(float x) {
	rotation.x += x;
}

void Transform::rotateY(float y) {
	rotation.y += y;
}

void Transform::rotateZ(float z) {
	rotation.z += z;
}

void Transform::setRotation(glm::vec3 rotation) {
	this->rotation = rotation;
}

glm::mat4 Transform::getForwardMatrix() {
	glm::mat4 movementMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(-rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	movementMatrix = glm::rotate(movementMatrix, glm::radians(-rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	movementMatrix = glm::rotate(movementMatrix, glm::radians(-rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	return movementMatrix;
}