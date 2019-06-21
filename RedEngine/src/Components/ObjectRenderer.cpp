#include "Components/ObjectRenderer.h"
#include <glm/gtc/matrix_transform.hpp>
#include "Scene.h"


void ObjectRenderer::init() {
	gameObject->scene->m_objectRenderers.push_back(this);
}

void ObjectRenderer::setModelMat(glm::vec3& position, glm::vec3& rotation, glm::vec3& scale) {
	m_modelMat = glm::translate(glm::mat4(1.0f), position);
	m_modelMat = glm::rotate(m_modelMat, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	m_modelMat = glm::rotate(m_modelMat, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	m_modelMat = glm::rotate(m_modelMat, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	m_modelMat = glm::scale(m_modelMat, scale);
}