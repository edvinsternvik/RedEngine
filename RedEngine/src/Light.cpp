#include "Light.h"

Light::Light(glm::vec3 pos, float brightness) : GameObject(pos, glm::vec3(0.0f), glm::vec3(1.0f)), brightness(brightness) {
}

Light::~Light() {
}
