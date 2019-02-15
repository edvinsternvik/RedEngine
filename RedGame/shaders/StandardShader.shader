//VERTEX SHADER
#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormals;

uniform mat4 projMat;
uniform mat4 viewMat;
uniform mat4 modelMat;

out vec3 fragPos;
out vec3 normal;

void main() {
	gl_Position = projMat * viewMat * modelMat * vec4(aPos, 1.0);
	fragPos = vec3(modelMat * vec4(aPos, 1.0));
	normal = mat3(transpose(inverse(modelMat))) * aNormals;
}

//FRAGMENT SHADER
#version 330 core

out vec4 FragColor;

in vec3 fragPos;
in vec3 normal;

uniform vec3 lightPos;

void main() {
	vec3 norm = normalize(normal);
	vec3 lightDir = normalize(lightPos - fragPos);

	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * vec3(0.5, 0.5, 0.5);

	FragColor = vec4(diffuse + 0.1, 1.0);
}