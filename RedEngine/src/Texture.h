#pragma once
#include <string>
#include <GL/glew.h>

enum FilterMode {
	Linear = GL_LINEAR, Nearest = GL_NEAREST
};

class Texture {
private:
	unsigned int m_textureID;
	unsigned char* m_localBuffer;
	int m_width, m_height, m_bpp;
	FilterMode m_filterMode;
public:
	Texture(std::string filePath);
	Texture(std::string filePath, FilterMode filterMode);
	~Texture();

	void bind(unsigned int slot);
	void unbind();
	inline int getWidth() const { return m_width; }
	inline int getHeight() const { return m_height; }
private:
	void init(std::string& filePath);
};

