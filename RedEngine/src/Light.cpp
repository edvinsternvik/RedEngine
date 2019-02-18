#include "Light.h"



Light::Light(glm::vec3 pos) : GameObject(pos, glm::vec3(0.0f)) {
}

Light::Light(glm::vec3 pos, Model * model) : GameObject(pos, glm::vec3(0.0f), model) {
}

Light::~Light() {
}
