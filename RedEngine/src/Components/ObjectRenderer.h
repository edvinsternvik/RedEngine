#pragma once
#include "../Component.h"
#include "../Model.h"

class ObjectRenderer : public Component {
private:
	Model* m_model;
public:
	ObjectRenderer(Model* model) : m_model(model) {}
	~ObjectRenderer() {}

	inline Model* const getModel() const { return m_model; }
};