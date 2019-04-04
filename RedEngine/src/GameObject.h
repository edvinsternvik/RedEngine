#pragma once
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Component.h"
#include "Model.h"

class Component;

class GameObject {
protected:
	glm::vec3 m_position, m_rotation, m_scale;
	std::vector<Component*> m_components;
	glm::mat4 m_modelMat;
public:
	GameObject(glm::vec3 pos, glm::vec3 rot, glm::vec3 size);
	~GameObject();

	void move(glm::vec3 movement);
	void setPosition(glm::vec3 position);
	void rotate(glm::vec3 rotation);
	void rotateX(float x);
	void rotateY(float y);
	void rotateZ(float z);
	void setRotation(glm::vec3 rotation);
	Component* addComponent(Component* component);
	inline std::vector<Component*>* getComponentList() { return &m_components; }
	inline glm::vec3* const getPosition() { return &m_position; };
	inline glm::vec3* const getScale() { return &m_scale; };
	inline glm::vec3* const getRotation() { return &m_rotation; }; 
	inline glm::mat4* const getModelMat() { return &m_modelMat; }; 
protected:
	virtual void setModelMat();
	glm::mat4 getForwardMatrix();
};