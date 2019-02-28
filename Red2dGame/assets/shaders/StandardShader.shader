//VERTEX SHADER
#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormals;
layout(location = 2) in vec2 aTexCoords;

uniform mat4 projMat;
uniform mat4 viewMat;
uniform mat4 modelMat;

out vec3 fragPos;
out vec3 normal;
out vec2 texCoords;

void main() {
	gl_Position = projMat * viewMat * modelMat * vec4(aPos, 1.0);
	fragPos = vec3(modelMat * vec4(aPos, 1.0));
	normal = mat3(transpose(inverse(modelMat))) * aNormals;
	texCoords = aTexCoords;
}

//FRAGMENT SHADER
#version 330 core

out vec4 FragColor;

in vec3 fragPos;
in vec3 normal;
in vec2 texCoords;

uniform sampler2D u_texture;

void main() {
	vec4 texColor = texture(u_texture, texCoords);

	FragColor = texColor;
}