#include "Texture.h"
#include "Debug.h"
#include <stb_image/stb_image.h>


Texture::Texture(std::string filePath) : m_textureID(0), m_localBuffer(nullptr), m_width(0), m_height(0), m_bpp(0), m_textureType(TextureType::Diffuse), m_filterMode(FilterMode::Linear) {
	init(filePath);
}

Texture::Texture(std::string filePath, TextureType textureType) : m_textureID(0), m_localBuffer(nullptr), m_width(0), m_height(0), m_bpp(0), m_textureType(textureType), m_filterMode(FilterMode::Linear) {
	init(filePath);
}

Texture::Texture(std::string filePath, TextureType textureType, FilterMode filterMode) : m_textureID(0), m_localBuffer(nullptr), m_width(0), m_height(0), m_bpp(0), m_textureType(textureType), m_filterMode(filterMode) {
	init(filePath);
}

Texture::~Texture() {
	glDebug(glDeleteTextures(1, &m_textureID));
}

void Texture::bind() {
	glDebug(glActiveTexture(GL_TEXTURE0 + m_textureType))
	glDebug(glBindTexture(GL_TEXTURE_2D, m_textureID));
}

void Texture::unbind() {
	glDebug(glActiveTexture(GL_TEXTURE0 + m_textureType))
	glDebug(glBindTexture(GL_TEXTURE_2D, 0));
}

void Texture::init(std::string& filePath) {
	stbi_set_flip_vertically_on_load(1);
	m_localBuffer = stbi_load(filePath.c_str(), &m_width, &m_height, &m_bpp, 4);

	glDebug(glGenTextures(1, &m_textureID));
	glDebug(glBindTexture(GL_TEXTURE_2D, m_textureID));

	glDebug(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_filterMode));
	glDebug(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_filterMode));
	glDebug(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	glDebug(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

	glDebug(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_localBuffer));

	if (m_localBuffer) {
		stbi_image_free(m_localBuffer);
	}
}
