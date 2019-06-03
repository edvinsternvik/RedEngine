#include "Renderer.h"

Renderer::Renderer(Shader* shader) : m_shader(shader) {
}

Renderer::~Renderer() {
}

void Renderer::updateCamera(Camera* camera) {
	m_shader->setUniformMat4f(m_shader->getProjectionUniformLocation(), &(*camera->getProjectionMat())[0][0]);
	m_shader->setUniformMat4f(m_shader->getViewUniformLocation(), &(*camera->getViewMat())[0][0]);
	m_shader->setUniformVec3f(m_shader->getCameraPosUniformLocation(), &(*camera->getPosition())[0]);
}

void Renderer::renderGameObject(ObjectRenderer* objectRenderer) {
	objectRenderer->getModel()->bind();
	objectRenderer->getModel()->getTexture()->bind(0);
	objectRenderer->getModel()->getSpecular()->bind(1);
	m_shader->setUniformMat4f(m_shader->getModelUniformLocation(), &(*objectRenderer->getParentGameObject()->getModelMat())[0][0]);

	glDebug(glDrawElements(GL_TRIANGLES, objectRenderer->getModel()->getIndexCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::updateLightPositions(std::vector<Light*>* lights) {
	std::vector<glm::vec3> lightPositionList;

	for(Light* light : *lights) {
		lightPositionList.push_back(*(light->getPosition()));
	}

	if (lightPositionList.size() == 0) lightPositionList.push_back(glm::vec3(0.0f));

	m_shader->setUniform1i(m_shader->getLightCountUniformLocation(), lightPositionList.size());
	m_shader->setUniformVec3f(m_shader->getLightPosUniformLocation(), &((lightPositionList[0])[0]));
}
