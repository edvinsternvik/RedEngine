#include "Camera.h"

Camera::Camera(glm::vec3 pos, glm::vec3 rot) : GameObject(pos, rot), m_projectionMat(glm::perspective(90.0f, 1920.0f / 1080.0f, 0.1f, 100.0f)) {
}

Camera::~Camera() {
}

void Camera::setModelMat() {
	m_modelMat = glm::translate(glm::mat4(1.0f), -m_position);
}
