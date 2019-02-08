#include "Shader.h"

Shader::Shader() {

	const char* vertShaderSource =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec3 aPos;\n"
		"\n"
		"uniform mat4 projMat;\n"
		"uniform mat4 modelMat;\n"
		"uniform mat4 viewMat;\n"
		"\n"
		"void main() {\n"
		"	vec4 vertPos = projMat * viewMat * modelMat * vec4(aPos, 1.0);\n"
		"	gl_Position = vertPos;\n"
		"}";

	unsigned int vertexShader = compileShader(GL_VERTEX_SHADER, vertShaderSource);

	const char* fragShaderSource =
		"#version 330 core\n"
		"\n"
		"out vec4 FragColor;\n"
		"\n"
		"void main() {\n"
		"	FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n"
		"}\n";

	unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragShaderSource);
	m_programID = createShaderProgram(vertexShader, fragmentShader);

	useShader();

	m_projectionUniformLocation = getUniformLocation("projMat");
	m_modelUniformLocation = getUniformLocation("modelMat");
	m_viewUniformLocation = getUniformLocation("viewMat");
}

Shader::~Shader() {
}

void Shader::useShader() {
	glDebug(glUseProgram(m_programID));
}

void Shader::setUniformMat4f(int uniformLocation, float * mat4) {
	glDebug(glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, mat4));
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
