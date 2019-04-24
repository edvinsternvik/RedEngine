#pragma once
#include <vector>
#include <string>
#include "VertexArrayObject.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

class Cubemap {
private:
	unsigned int m_textureID;
	std::vector<float> m_vertexData;
	std::vector<unsigned int> m_indexData;
	VertexArrayObject* m_vao;
	VertexBuffer* m_vbo;
	IndexBuffer* m_ibo;
public:
	Cubemap(std::vector<std::string> imagePaths);
	~Cubemap();

	void bind();
private:
	void genCubemapTextures(std::vector<std::string>& imagePaths);
};