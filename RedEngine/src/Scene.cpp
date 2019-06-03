#include "Scene.h"

Scene::Scene() {
}

Scene::~Scene() {
    for(GameObject* go : m_gameObjects) {
        delete go;
    }
}

void Scene::updateObjects() {
    for(GameObject* gameObject : m_gameObjects) {
        for(Component* component : *gameObject->getComponentList()) {
            component->update();
        }
    }
}

void Scene::renderScene(Renderer* renderer) {
    renderer->updateCamera(m_camera);
    renderer->updateLightPositions(&m_lights);

    for(ObjectRenderer* objRenderer : m_objectRenderers) {
        renderer->renderGameObject(objRenderer);
    }
}

GameObject* Scene::createGameObject(glm::vec3 position) {
    m_gameObjects.push_back(new GameObject(position, glm::vec3(0.0), glm::vec3(1.0)));
    return m_gameObjects.back();
}
GameObject* Scene::createGameObject(glm::vec3 position, glm::vec3 rotation) {
    m_gameObjects.push_back(new GameObject(position, rotation, glm::vec3(1.0)));
    return m_gameObjects.back();
}

GameObject* Scene::createGameObject(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) {
    m_gameObjects.push_back(new GameObject(position, rotation, scale));
    return m_gameObjects.back();
}

GameObject* Scene::createGameObject(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, Model* model) {
    m_gameObjects.push_back(new GameObject(position, rotation, scale));

    ObjectRenderer* objRenderer = new ObjectRenderer(model);
    m_gameObjects.back()->addComponent(objRenderer);
    m_objectRenderers.push_back(objRenderer);

    return m_gameObjects.back();
}

Light* Scene::createLight(glm::vec3 pos) {
	m_lights.push_back(new Light(pos));
    m_gameObjects.push_back(m_lights.back());
	return m_lights.back();
}

Camera* Scene::createCamera(glm::vec3 pos, glm::vec3 rot, CameraType cameraType, glm::vec2 windowSize) {
	Camera* camera = new Camera(pos, rot, cameraType, windowSize);
	m_gameObjects.push_back(camera);
    m_camera = camera;
	return camera;
}