#include "GameObject.h"

GameObject::GameObject(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale) : position(pos), rotation(rot), scale(scale), m_modelMat(glm::translate(glm::mat4(1.0f), pos)) {
	setModelMat();
}

GameObject::~GameObject() {
	for (Component* c : m_components) delete c;
}

void GameObject::move(glm::vec3 movement) {
	position += glm::mat3(getForwardMatrix()) * movement;
	setModelMat();
}

void GameObject::setPosition(glm::vec3 position) {
	this->position = position;
	setModelMat();
}

void GameObject::rotate(glm::vec3 rotation) {
	this->rotation += rotation;
	setModelMat();
}

void GameObject::rotateX(float x) {
	rotation.x += x;
	setModelMat();
}

void GameObject::rotateY(float y) {
	rotation.y += y;
}

void GameObject::rotateZ(float z) {
	rotation.z += z;
}

void GameObject::setRotation(glm::vec3 rotation) {
	this->rotation = rotation;
	setModelMat();
}

Component * GameObject::addComponent(Component * component) {
	m_components.push_back(component);
	component->setParentGameObject(this);
	component->init();
	component->start();
	return component;
}

void GameObject::setModelMat() {
	m_modelMat = glm::scale(glm::mat4(1.0f), scale);
	m_modelMat = glm::translate(m_modelMat, position);
	m_modelMat = glm::rotate(m_modelMat, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	m_modelMat = glm::rotate(m_modelMat, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	m_modelMat = glm::rotate(m_modelMat, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
}

glm::mat4 GameObject::getForwardMatrix() {
	glm::mat4 movementMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(-rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	movementMatrix = glm::rotate(movementMatrix, glm::radians(-rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	movementMatrix = glm::rotate(movementMatrix, glm::radians(-rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	return movementMatrix;
}
