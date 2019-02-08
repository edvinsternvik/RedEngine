#include "GameObject.h"

GameObject::GameObject(glm::vec3 pos, glm::vec3 rot) : m_position(pos), m_rotation(rot), m_model(nullptr), m_modelMat(glm::translate(glm::mat4(1.0f), pos)) {
	setModelMat();
}

GameObject::GameObject(glm::vec3 pos, glm::vec3 rot, Model* model) : m_position(pos), m_rotation(rot), m_model(model), m_modelMat(glm::translate(glm::mat4(1.0f), pos)) {
	setModelMat();
}

GameObject::~GameObject() {	
}

void GameObject::move(glm::vec3 movement) {
	m_position += movement;
	setModelMat();
}

void GameObject::setPosition(glm::vec3 position) {
	m_position = position;
	setModelMat();
}

void GameObject::rotate(glm::vec3 rotation) {
	m_rotation += rotation;
	setModelMat();
}

void GameObject::setRotation(glm::vec3 rotation) {
	m_rotation = rotation;
	setModelMat();
}

void GameObject::setModelMat() {
	m_modelMat = glm::translate(glm::mat4(1.0f), m_position);
	m_modelMat = glm::rotate(m_modelMat, glm::radians(m_rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	m_modelMat = glm::rotate(m_modelMat, glm::radians(m_rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	m_modelMat = glm::rotate(m_modelMat, glm::radians(m_rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
}
