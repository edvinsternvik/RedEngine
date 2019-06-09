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

void Camera::setViewMat(glm::vec3& pos, glm::vec3& rot) {
	m_viewMat = glm::rotate(glm::mat4(1.0f), glm::radians(rot.y), glm::vec3(0.0f, 1.0f, 0.0f));
	m_viewMat = glm::rotate(m_viewMat, glm::radians(rot.x), glm::vec3(1.0f, 0.0f, 0.0f));
	m_viewMat = glm::rotate(m_viewMat, glm::radians(rot.z), glm::vec3(0.0f, 0.0f, 1.0f));
	m_viewMat = glm::translate(m_viewMat, -pos);
}
