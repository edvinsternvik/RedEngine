#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "GameObject.h"

class Camera : public GameObject {
private:
	glm::mat4 m_projectionMat;
public:
	Camera(glm::vec3 pos, glm::vec3 rot);
	~Camera();


	inline glm::mat4* const getProjectionMat() { return &m_projectionMat; };
	inline glm::mat4* const getViewMat() { return &m_modelMat; };
protected:
	void setModelMat() override;
};