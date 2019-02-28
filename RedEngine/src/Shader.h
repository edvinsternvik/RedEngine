#pragma once
#include <GL/glew.h>
#include "Debug.h"

class Shader {
private:
	unsigned int m_programID;
	int m_projectionUniformLocation;
	int m_modelUniformLocation;
	int m_viewUniformLocation;
	int m_lightPosUniformLocation;
	int m_lightCountUniformLocation;
	int m_textureUniformLocation;
public:
	Shader();
	~Shader();

	void useShader();
	void setUniform1i(int uniformLocation, int value);
	void setUniformMat4f(int uniformLocation, float* mat4);
	void setUniformVec3f(int uniformLocation, float* vec3);
	void setUniformVec3fArray(int uniformLocation, float* arrayPointer, unsigned int vec3Count);
	int getUniformLocation(const char* uniformName);
	inline int const getProjectionUniformLocation() const { return m_projectionUniformLocation; }
	inline int const getModelUniformLocation() const { return m_modelUniformLocation; }
	inline int const getViewUniformLocation() const { return m_viewUniformLocation; }
	inline int const getLightPosUniformLocation() const { return m_lightPosUniformLocation; }
	inline int const getLightCountUniformLocation() const { return m_lightCountUniformLocation; }
private:
	unsigned int compileShader(GLenum shaderType, const char* shaderSource);
	unsigned int createShaderProgram(unsigned int vertexShaderID, unsigned int fragmentShaderID);
	void parseShader(const char* shaderSource, std::string* vertexShaderSource, std::string* fragmentShaderSource);
	void checkForShaderError(unsigned int shaderID);
	void checkForProgramError(unsigned int programID);
};