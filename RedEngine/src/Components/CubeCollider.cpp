#include "CubeCollider.h"

CubeCollider::CubeCollider() : offset(glm::vec3(0.0f)), size(glm::vec3(1.0f)), rotation(glm::vec3(0.0f)) {

}

CubeCollider::CubeCollider(glm::vec3 offset, glm::vec3 size, glm::vec3 rotation) : offset(offset), size(size), rotation(rotation) {

}

CubeCollider::~CubeCollider() {

}

void CubeCollider::start() {

}

void CubeCollider::update() {
    
}