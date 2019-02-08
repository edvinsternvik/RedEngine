#pragma once
#include <GL/glew.h>
#include "Debug.h"

class VertexArrayObject {
private:
	unsigned int m_vaoID;
public:
	VertexArrayObject();
	~VertexArrayObject();

	void bind();
};