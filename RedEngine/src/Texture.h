#pragma once
#include <string>


class Texture {
private:
	unsigned int m_textureID;
	unsigned char* m_localBuffer;
	int m_width, m_height, m_bpp;
public:
	Texture(std::string filePath);
	~Texture();

	void bind(unsigned int slot);
	void unbind();
	inline int getWidth() const { return m_width; }
	inline int getHeight() const { return m_height; }
};

