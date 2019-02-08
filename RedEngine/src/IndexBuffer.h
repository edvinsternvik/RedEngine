#pragma once
#include <GL/glew.h>
#include "Debug.h"

class IndexBuffer {
private:
	unsigned int m_bufferID;
public:
	IndexBuffer(unsigned int* indexData, unsigned int dataSize);
	~IndexBuffer();

	void bind();
};