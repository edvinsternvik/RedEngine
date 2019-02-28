#include "Shader.h"
#include <fstream>
#include <sstream>

Shader::Shader() {
	std::string vertShaderSource, fragShaderSource;
	parseShader("assets/shaders/StandardShader.shader", &vertShaderSource, &fragShaderSource);

	unsigned int vertexShader = compileShader(GL_VERTEX_SHADER, vertShaderSource.c_str());
	unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragShaderSource.c_str());

	m_programID = createShaderProgram(vertexShader, fragmentShader);

	useShader();

	m_projectionUniformLocation = getUniformLocation("projMat");
	m_modelUniformLocation = getUniformLocation("modelMat");
	m_viewUniformLocation = getUniformLocation("viewMat");
	m_lightPosUniformLocation = getUniformLocation("lightPos");
	m_lightCountUniformLocation = getUniformLocation("lightCount");
	m_textureUniformLocation = getUniformLocation("u_texture");
	setUniform1i(m_textureUniformLocation, 0);
}

Shader::~Shader() {
}

void Shader::useShader() {
	glDebug(glUseProgram(m_programID));
}

void Shader::setUniform1i(int uniformLocation, int value) {
	glDebug(if (uniformLocation > -1) glUniform1i(uniformLocation, value));
}

void Shader::setUniformMat4f(int uniformLocation, float * mat4) {
	glDebug(if(uniformLocation > -1) glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, mat4));
}

void Shader::setUniformVec3f(int uniformLocation, float * vec3) {
	glDebug(if (uniformLocation > -1) glUniform3fv(uniformLocation, 1, vec3));
}

void Shader::setUniformVec3fArray(int uniformLocation, float * arrayPointer, unsigned int vec3Count) {
	glDebug(if (uniformLocation > -1) glUniform3fv(uniformLocation, vec3Count, arrayPointer));
}

int Shader::getUniformLocation(const char * uniformName) {
	glDebug(return  glGetUniformLocation(m_programID, uniformName));
}

unsigned int Shader::compileShader(GLenum shaderType, const char * shaderSource) {
	glDebug(unsigned int shaderID = glCreateShader(shaderType));
	glDebug(glShaderSource(shaderID, 1, &shaderSource, NULL));
	glDebug(glCompileShader(shaderID));

	checkForShaderError(shaderID);

	return shaderID;
}

unsigned int Shader::createShaderProgram(unsigned int vertexShaderID, unsigned int fragmentShaderID) {
	glDebug(unsigned int shaderProgram = glCreateProgram());
	glDebug(glAttachShader(shaderProgram, vertexShaderID));
	glDebug(glAttachShader(shaderProgram, fragmentShaderID));
	glDebug(glLinkProgram(shaderProgram));

	glDebug(glDeleteShader(vertexShaderID));
	glDebug(glDeleteShader(fragmentShaderID));

	checkForProgramError(shaderProgram);

	return shaderProgram;
}

void Shader::parseShader(const char* shaderPath, std::string * vertexShaderSource, std::string* fragmentShaderSource) {
	std::ifstream ifs(shaderPath);
	std::stringstream vertexStringstream, fragmentStringstream;
	std::string line;
	int shaderType = 0; //0:none, 1:vertex, 2:fragment
	if (ifs.is_open()) {
		while (std::getline(ifs, line)) {
			if (line[0] == '/' && line[1] == '/') {
				if (line.find("VERTEX SHADER") != std::string::npos) { shaderType = 1; }
				if (line.find("FRAGMENT SHADER") != std::string::npos) { shaderType = 2; }
			}
			else {
				if (shaderType == 1) {
					vertexStringstream << line << '\n';
				}
				else if (shaderType == 2) {
					fragmentStringstream << line << '\n';
				}
			}
		}
		*vertexShaderSource = vertexStringstream.str();
		*fragmentShaderSource = fragmentStringstream.str();
	}
	else {
		std::cout << "Could not open file" << std::endl;
	}
	
}

void Shader::checkForShaderError(unsigned int shaderID) {
	int shaderComp;
	glDebug(glGetShaderiv(shaderID, GL_COMPILE_STATUS, &shaderComp));
	if (shaderComp != GL_TRUE) {
		int log_len = 0;
		char message[1024];
		glDebug(glGetShaderInfoLog(shaderID, 1024, &log_len, message));

		gameEngineDebug(message);
	}
}

void Shader::checkForProgramError(unsigned int programID) {
	int programLink;
	glDebug(glGetProgramiv(programID, GL_LINK_STATUS, &programLink));
	if (programLink != GL_TRUE) {
		int logLen = 0;
		char message[1024];
		glDebug(glGetProgramInfoLog(programID, 1024, &logLen, message));

		gameEngineDebug(message);
	}
}
