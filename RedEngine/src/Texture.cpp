#include "Texture.h"
#include "Debug.h"
#include <GL/glew.h>
#include <stb_image/stb_image.h>

Texture::Texture(std::string filePath) : m_textureID(0), m_localBuffer(nullptr), m_width(0), m_height(0), m_bpp(0) {
	stbi_set_flip_vertically_on_load(1);
	m_localBuffer = stbi_load(filePath.c_str(), &m_width, &m_height, &m_bpp, 4);

	glDebug(glGenTextures(1, &m_textureID));
	glDebug(glBindTexture(GL_TEXTURE_2D, m_textureID));

	glDebug(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	glDebug(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	glDebug(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	glDebug(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

	glDebug(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_localBuffer));

	//glDebug(glBindTexture(GL_TEXTURE_2D, 0));

	if (m_localBuffer) {
		stbi_image_free(m_localBuffer);
	}
}

Texture::~Texture() {
	glDebug(glDeleteTextures(1, &m_textureID));
}

void Texture::bind(unsigned int slot) {
	glDebug(glActiveTexture(GL_TEXTURE0 + slot))
	glDebug(glBindTexture(GL_TEXTURE_2D, m_textureID));
}

void Texture::unbind() {
	glDebug(glBindTexture(GL_TEXTURE_2D, 0));
}
