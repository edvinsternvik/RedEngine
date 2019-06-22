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
    renderer->updateCamera(getCamera());
    renderer->updateLightPositions(&m_lights);

    for(ObjectRenderer* objRenderer : m_objectRenderers) {
        renderer->renderGameObject(objRenderer);
    }
}

GameObject* Scene::createGameObject(glm::vec3 position) {
	return createGameObject(position, glm::vec3(0.0f), glm::vec3(1.0f));
}
GameObject* Scene::createGameObject(glm::vec3 position, glm::vec3 rotation) {
	return createGameObject(position, rotation, glm::vec3(1.0f));
}

GameObject* Scene::createGameObject(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) {
	GameObject* go = new GameObject(position, rotation, scale);
	go->scene = this;
	m_gameObjects.push_back(go);
	return go;
}

GameObject* Scene::createGameObject(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, Model* model) {
	GameObject* go = createGameObject(position, rotation, scale);

	go->addComponent(new ObjectRenderer(model));

    return go;
}

Light* Scene::createLight(glm::vec3 pos, float strength) {
    GameObject* lightObject = createGameObject(pos);
    Component* light = lightObject->addComponent(new Light(strength));

	return (Light*)light;
}

Camera* Scene::createCamera(glm::vec3 pos, glm::vec3 rot, CameraType cameraType, glm::vec2 windowSize) {
	Camera* camera = new Camera(pos, rot, cameraType, windowSize);
	m_gameObjects.push_back(camera);
    m_camera = camera;
	return camera;
}