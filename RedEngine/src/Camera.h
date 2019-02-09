#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "GameObject.h"

enum CameraType {
	Perspective, Orthographic
};

class Camera : public GameObject {
private:
	glm::mat4 m_projectionMat;
	CameraType m_cameraType;
public:
	Camera(glm::vec3 pos, glm::vec3 rot, CameraType cameraType, glm::vec2& windowSize);
	~Camera();


	inline glm::mat4* const getProjectionMat() { return &m_projectionMat; };
	inline glm::mat4* const getViewMat() { return &m_modelMat; };
protected:
	void setModelMat() override;
};