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

void main() {
	vec4 texColor = texture(u_texture, texCoords);
	vec3 norm = normalize(normal);

	float diffuse = 0, specular = 0;
	for (int i = 0; i < min(lightCount, 32); i++) {
		vec3 lightDir = normalize(lightPos[i] - fragPos);
		float lightStrength = dot(norm, lightDir);
		float lightDistance = distance(lightPos[i], fragPos);
		float lightFalloff = 1.0f / (1.0f + 0.00001f * lightDistance + 0.1f * lightDistance * lightDistance);

		diffuse += max(lightStrength * lightFalloff, 0.0);
		
		vec3 viewDir = normalize(u_cameraPos - fragPos);
		vec3 reflectDir = reflect(-lightDir, norm);
		specular += max(dot(viewDir, reflectDir), 0);
	}


	FragColor = texColor * vec4(vec3(diffuse + specular) + 0.25, 1.0);
}