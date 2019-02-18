#pragma once
#include <vector>
#include "VertexArrayObject.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "ObjReader.h"
#include "Texture.h"

class Model {
private:
	objReader::modelData m_modelData;
	unsigned int m_indicies;
	VertexArrayObject* m_vao;
	VertexBuffer* m_vbo;
	IndexBuffer* m_ibo;
	Texture* m_texture;
public:
	Model(const char* modelPath, Texture* texture);
	~Model();

	void bind();
	inline unsigned int getIndexCount() const { return m_indicies; }
	inline Texture* getTexture() const { return m_texture; }
};