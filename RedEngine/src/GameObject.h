#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Model.h"
#include <iostream>

class GameObject {
protected:
	glm::vec3 m_position;
	glm::vec3 m_rotation;
	Model* m_model;
	glm::mat4 m_modelMat;
public:
	GameObject(glm::vec3 pos, glm::vec3 rot);
	GameObject(glm::vec3 pos, glm::vec3 rot, Model* model);
	~GameObject();

	void move(glm::vec3 movement);
	void setPosition(glm::vec3 position);
	void rotate(glm::vec3 rotation);
	void setRotation(glm::vec3 rotation);
	inline glm::vec3* const getPosition() { return &m_position; };
	inline glm::vec3* const getRotation() { return &m_rotation; }; 
	inline glm::mat4* const getModelMat() { return &m_modelMat; }; 
	inline Model* const getModel() { return m_model; };
protected:
	virtual void setModelMat();
};