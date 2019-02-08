#include "VertexArrayObject.h"

VertexArrayObject::VertexArrayObject() {
	glDebug(glCreateVertexArrays(1, &m_vaoID));
	glDebug(glBindVertexArray(m_vaoID));
}

VertexArrayObject::~VertexArrayObject() {
}

void VertexArrayObject::bind() {
	glDebug(glBindVertexArray(m_vaoID));
}
