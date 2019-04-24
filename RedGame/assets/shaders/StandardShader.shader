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

uniform vec3 u_cameraPos;
uniform vec3 lightPos[32];
uniform int lightCount;
uniform sampler2D u_texture;
uniform sampler2D u_specular;

void main() {
	vec3 texColor = vec3(texture(u_texture, texCoords));
	vec3 norm = normalize(normal);

	float diff = 0, spec = 0;
	for (int i = 0; i < min(lightCount, 32); i++) {
		vec3 lightDir = normalize(lightPos[i] - fragPos);
		float lightStrength = dot(norm, lightDir);
		float lightDistance = distance(lightPos[i], fragPos);
		float lightFalloff = 1.0f / (1.0f + 0.000005f * lightDistance + 0.025f * lightDistance * lightDistance);

		diff += max(lightStrength * lightFalloff, 0.0);
		
		vec3 viewDir = normalize(u_cameraPos - fragPos);
		vec3 reflectDir = reflect(-lightDir, norm);
		spec += max(dot(viewDir, reflectDir), 0);
	}
	vec3 ambient = 0.25f * texColor;
	vec3 diffuse = 1.0f * diff * texColor;
	vec3 specular = 0.5f * spec * vec3(texture(u_specular, texCoords));

	FragColor = vec4(ambient + diffuse + specular, 1.0f);
}