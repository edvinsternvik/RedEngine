#include "CubeCollider.h"
#include <glm/gtc/matrix_transform.hpp>

#include <GameObject.h>

#include <iostream>

CubeCollider::CubeCollider(glm::vec3 offset, glm::vec3 rotation, glm::vec3 scale) : Collider(offset, rotation, scale), rotationMatrix(glm::mat4(1)) {
	setRotationMatrix();
	setInvertedRotationMatrix();
}

CubeCollider::~CubeCollider() {
}

void CubeCollider::start() {
}

void CubeCollider::update() {
}

bool CubeCollider::cubeCollision(CubeCollider* other) {
	bool test1 = calculateCubeCollision(other);

	if (test1) {

		bool test2 = other->calculateCubeCollision(this);

		if (test2) return true;
	}

	return false;
}

bool CubeCollider::sphereCollision(SphereCollider* other) {
	return false;
}

bool CubeCollider::calculateCubeCollision(CubeCollider* other) {
	glm::vec3 thisPos = gameObject->transform->position + offset;
	glm::vec3 otherPos = other->gameObject->transform->position + other->offset - thisPos;

	glm::vec3 thisMin = -*getScale(), thisMax = *getScale();
	glm::vec3 otherMin(0), otherMax(0);

	for (int i = 0; i < 8; ++i) {
		glm::vec3 otherVert = other->vertecies[i] * *other->getScale();

		otherVert = glm::mat3(other->rotationMatrix) * otherVert;
		otherVert += otherPos; //global position

		otherVert = glm::mat3(invertedRotationMatrix) * otherVert;

		if (i == 0 || otherVert.x < otherMin.x) otherMin.x = otherVert.x;
		if (i == 0 || otherVert.x > otherMax.x) otherMax.x = otherVert.x;

		if (i == 0 || otherVert.y < otherMin.y) otherMin.y = otherVert.y;
		if (i == 0 || otherVert.y > otherMax.y) otherMax.y = otherVert.y;

		if (i == 0 || otherVert.z < otherMin.z) otherMin.z = otherVert.z;
		if (i == 0 || otherVert.z > otherMax.z) otherMax.z = otherVert.z;
	}

	if (otherMin.x < thisMax.x && thisMin.x < otherMax.x &&
		otherMin.y < thisMax.y && thisMin.y < otherMax.y &&
		otherMin.z < thisMax.z && thisMin.z < otherMax.z) {

		return true;
	}

	return false;
}

void CubeCollider::setRotationMatrix() {
	rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(rotation.x), glm::vec3(1, 0, 0));
	rotationMatrix = glm::rotate(rotationMatrix, glm::radians(rotation.y), glm::vec3(0, 1, 0));
	rotationMatrix = glm::rotate(rotationMatrix, glm::radians(rotation.z), glm::vec3(0, 0, 1));
}

void CubeCollider::setInvertedRotationMatrix() {
	invertedRotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(-rotation.x), glm::vec3(1, 0, 0));
	invertedRotationMatrix = glm::rotate(invertedRotationMatrix, glm::radians(-rotation.y), glm::vec3(0, 1, 0));
	invertedRotationMatrix = glm::rotate(invertedRotationMatrix, glm::radians(-rotation.z), glm::vec3(0, 0, 1));
}	
