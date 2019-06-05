#include "Camera.h"

Camera::Camera(glm::vec3 pos, glm::vec3 rot, CameraType cameraType, glm::vec2 windowSize) : GameObject(pos, rot, glm::vec3(1.0f)), m_cameraType(cameraType) {
	float aspectRatio = windowSize.x / windowSize.y;

	if (m_cameraType == CameraType::Perspective) {
		m_projectionMat = glm::perspective(glm::radians(90.0f), aspectRatio, 0.1f, 100.0f);
	}
	else if (m_cameraType == CameraType::Orthographic) {
		m_projectionMat = glm::ortho(-10.0f * aspectRatio, 10.0f * aspectRatio, -10.0f, 10.0f, -0.1f, 100.0f);
	}
}

Camera::~Camera() {
}

void Camera::setModelMat() {
	m_modelMat = glm::rotate(glm::mat4(1.0f), glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	m_modelMat = glm::rotate(m_modelMat, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	m_modelMat = glm::rotate(m_modelMat, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	m_modelMat = glm::translate(m_modelMat, -position);
}
