#include "Cubemap.h"
#include "Debug.h"
#include <GL\glew.h>
#include <stb_image\stb_image.h>


Cubemap::Cubemap(std::vector<std::string> imagePaths) : 
	m_vertexData({
		1.0f, 1.0f -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, -1.0f, 1.0f,
		-1.0f, 1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, -1.0f, 1.0f }), 
	m_indexData({
		5, 3, 1,
		3, 8, 4,
		7, 6, 8,
		2, 8, 6,
		1, 4, 2,
		5, 2, 6,
		5, 7, 3,
		3, 7, 8,
		7, 5, 6,
		2, 4, 8,
		1, 3, 4,
		5, 1, 2}) {

	genCubemapTextures(imagePaths);

	m_vao = new VertexArrayObject();
	m_vbo = new VertexBuffer(&m_vertexData[0], sizeof(float) * m_vertexData.size());
	m_vbo->addVertexAttribute(0, 3, sizeof(float) * 3, 0);
	m_ibo = new IndexBuffer(&m_indexData[0], sizeof(unsigned int) * m_indexData.size());
}

Cubemap::~Cubemap() {
	delete m_vao;
	delete m_vbo;
	delete m_ibo;
}

void Cubemap::bind() {
}

void Cubemap::genCubemapTextures(std::vector<std::string>& imagePaths) {
	glDebug(glGenBuffers(1, &m_textureID));
	glDebug(glBindBuffer(GL_TEXTURE_CUBE_MAP, m_textureID));

	int width, height, bpp;
	for (int i = 0; i < 6 && i < imagePaths.size(); ++i) {
		unsigned char* data = stbi_load(imagePaths[i].c_str(), &width, &height, &bpp, 0);
		if (data) {
			glDebug(glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data));
		}
		else {
			gameEngineDebug("Could not get texture data from file: " + imagePaths[i]);
		}
		stbi_image_free(data);
	}
	glDebug(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	glDebug(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	glDebug(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	glDebug(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
	glDebug(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE));
}
