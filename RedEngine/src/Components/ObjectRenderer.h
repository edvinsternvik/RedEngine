#pragma once
#include "../Component.h"
#include "../Model.h"

class ObjectRenderer : public Component {
private:
	Model* m_model;
	glm::mat4 m_modelMat;
public:
	ObjectRenderer(Model* model) : m_model(model), m_modelMat(glm::mat4(1.0f)) {}
	~ObjectRenderer() {}

	virtual void init() override;

	void setModelMat(glm::vec3& pos, glm::vec3& rot, glm::vec3& scale);
	inline Model* const getModel() const { return m_model; }
	inline glm::mat4* const getModelMat() { return &m_modelMat; };
};