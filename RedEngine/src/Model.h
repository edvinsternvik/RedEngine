#pragma once
#include <vector>
#include "VertexArrayObject.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "ObjReader.h"

class Model {
private:
	objReader::modelData m_modelData;
	unsigned int m_indicies;
	VertexArrayObject* m_vao;
	VertexBuffer* m_vbo;
	IndexBuffer* m_ibo;
public:
	Model();
	~Model();

	inline unsigned int getIndexCount() { return m_indicies; }
};