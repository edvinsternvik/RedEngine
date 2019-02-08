#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(float* vertexData, unsigned int dataSize) {
	glDebug(glGenBuffers(1, &m_bufferID));
	glDebug(glBindBuffer(GL_ARRAY_BUFFER, m_bufferID));
	glDebug(glBufferData(GL_ARRAY_BUFFER, dataSize, vertexData, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer() {
}

void VertexBuffer::addVertexAttribute(int id, int elements, int stride, int offset) {
	glDebug(glEnableVertexAttribArray(id));
	glDebug(glVertexAttribPointer(id, elements, GL_FLOAT, GL_FALSE, stride, (const void*)offset));
}

void VertexBuffer::bind() {
	glDebug(glBindBuffer(GL_ARRAY_BUFFER, m_bufferID));
}
