#include "Renderer.h"

Renderer::Renderer(Camera * camera, GameObjectManager * gameObjectManager, Shader * shader) : m_camera(camera), m_gameObjectManager(gameObjectManager), m_shader(shader) {

}

Renderer::~Renderer() {
}

void Renderer::renderFrame() {
	m_shader->setUniformMat4f(m_shader->getProjectionUniformLocation(), &(*m_camera->getProjectionMat())[0][0]);
	m_shader->setUniformMat4f(m_shader->getViewUniformLocation(), &(*m_camera->getViewMat())[0][0]);

	for (GameObject* go : *m_gameObjectManager->getGameObjectList()) {
		renderGameObject(go);
	}
}

void Renderer::renderGameObject(GameObject* gameObject) {
	m_shader->setUniformMat4f(m_shader->getModelUniformLocation(), &(*gameObject->getModelMat())[0][0]);

	glDebug(glDrawElements(GL_TRIANGLES, gameObject->getModel()->getIndexCount(), GL_UNSIGNED_INT, nullptr));
}
