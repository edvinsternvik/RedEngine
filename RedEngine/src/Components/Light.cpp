#include "Light.h"
#include "Scene.h"

Light::Light(float brightness) : brightness(brightness) {
}

Light::~Light() {
}

void Light::init() {
    gameObject->scene->m_lights.push_back(this);
}
