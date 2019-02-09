#include "Camera.h"

Camera::Camera(glm::vec3 pos, glm::vec3 rot, CameraType cameraType, glm::vec2& windowSize) : GameObject(pos, rot), m_cameraType(cameraType) {
	float aspectRatio = windowSize.x / windowSize.y;

	if (m_cameraType == CameraType::Perspective) {
		m_projectionMat = glm::perspective(glm::radians(90.0f), aspectRatio, 0.1f, 100.0f);
	}
	else if (m_cameraType == CameraType::Orthographic) {
		m_projectionMat = glm::ortho(-5.0f * aspectRatio, 5.0f * aspectRatio, -5.0f, 5.0f, -0.1f, 100.0f);
	}

}

Camera::~Camera() {
}

void Camera::setModelMat() {
	m_modelMat = glm::translate(glm::mat4(1.0f), -m_position);
}
