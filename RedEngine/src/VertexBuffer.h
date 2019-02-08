#pragma once
#include <GL/glew.h>
#include "Debug.h"

class VertexBuffer {
private:
	unsigned int m_bufferID;
public:
	VertexBuffer(float* vertexData, unsigned int dataSize);
	~VertexBuffer();

	void addVertexAttribute(int id, int elements, int stride, int offset);
	void bind();
};