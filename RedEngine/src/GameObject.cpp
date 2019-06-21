#include "GameObject.h"
#include "Debug.h"

GameObject::GameObject(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale) {
	Transform* t = new Transform(pos, rot, scale);

	transform = t;
	addComponent(t);
}

GameObject::~GameObject() {
	for (Component* c : m_components) delete c;
}

Component * GameObject::addComponent(Component * component) {
	m_components.push_back(component);
	component->gameObject = this;
	component->init();
	component->start();
	return component;
}