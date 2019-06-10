#include "Renderer.h"

Renderer::Renderer(Shader* shader) : m_shader(shader) {
}

Renderer::~Renderer() {
}

void Renderer::updateCamera(Camera* camera) {
	camera->setViewMat((glm::vec3&)camera->transform->position, (glm::vec3&)camera->transform->rotation);

	m_shader->setUniformMat4f(m_shader->getProjectionUniformLocation(), &(*camera->getProjectionMat())[0][0]);
	m_shader->setUniformMat4f(m_shader->getViewUniformLocation(), &(*camera->getViewMat())[0][0]);
	m_shader->setUniformVec3f(m_shader->getCameraPosUniformLocation(), &((Transform*)(camera->transform))->position[0]);
}

void Renderer::renderGameObject(ObjectRenderer* objectRenderer) {
	objectRenderer->getModel()->bind();
	objectRenderer->getModel()->getTexture()->bind(0);
	objectRenderer->getModel()->getSpecular()->bind(1);

	const Transform* objTransform = objectRenderer->gameObject->transform;
	objectRenderer->setModelMat((glm::vec3&)objTransform->position, (glm::vec3&)objTransform->rotation, (glm::vec3&)objTransform->scale);
	m_shader->setUniformMat4f(m_shader->getModelUniformLocation(), &(*objectRenderer->getModelMat())[0][0]);

	glDebug(glDrawElements(GL_TRIANGLES, objectRenderer->getModel()->getIndexCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::updateLightPositions(std::vector<Light*>* lights) {
	glm::vec3 lightPositionList[32];
	float brightnessList[32];

	for(int i = 0; i < lights->size(); ++i) {
		lightPositionList[i] = (*lights)[i]->transform->position;
		brightnessList[i] = (*lights)[i]->brightness;
	}

	m_shader->setUniform1i(m_shader->getLightCountUniformLocation(), lights->size());
	m_shader->setUniformVec3f(m_shader->getLightPosUniformLocation(), &((lightPositionList[0])[0]));
	m_shader->setUniform1f(m_shader->getLightBrightnessUniformLocation(), brightnessList[0]);
}
