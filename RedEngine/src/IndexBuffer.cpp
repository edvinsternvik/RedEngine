#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(unsigned int * indexData, unsigned int dataSize) {
	glDebug(glGenBuffers(1, &m_bufferID));
	glDebug(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferID));
	glDebug(glBufferData(GL_ELEMENT_ARRAY_BUFFER, dataSize, indexData, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer() {
}

void IndexBuffer::bind() {
	glDebug(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferID));
}
