#include "Collider.h"
#include <Scene.h>

Collider::Collider(glm::vec3 offset, glm::vec3 rotation, glm::vec3 scale) : offset(offset), rotation(rotation), scale(scale) {
	calculateAABBscale();
}

Collider::~Collider() {
}

void Collider::init() {
	gameObject->scene->m_colliders.push_back(this);
}

bool Collider::AABB(Collider* other) {
	glm::vec3 thisPos = gameObject->transform->position + offset, otherPos = other->gameObject->transform->position + other->offset;

	glm::vec3 thisMin = thisPos - AABBhScale;
	glm::vec3 thisMax = thisPos + AABBhScale;

	glm::vec3 otherMin = otherPos - other->AABBhScale;
	glm::vec3 otherMax = otherPos + other->AABBhScale;

	if (thisMin.x < otherMax.x && otherMin.x < thisMax.x
		&& thisMin.y < otherMax.y && otherMin.y < thisMax.y
		&& thisMin.z < otherMax.z && otherMin.z < thisMax.z) {

		return true;
	}

	return false;
}

bool Collider::isCollidingWith(Collider* other, ColliderType colliderType) {
	switch (colliderType) {
	case ColliderType::CubeCollider:
		return cubeCollision((CubeCollider*)other);
		break;
	case ColliderType::SphereCollider:
		return sphereCollision((SphereCollider*)other);
		break;
	}

	return false;
}

void Collider::setScale(glm::vec3 newScale) {
	scale = newScale;
	calculateAABBscale();
}

void Collider::calculateAABBscale() {
	float hSide = std::sqrt((scale.x * scale.x + scale.y * scale.y) + (scale.z * scale.z));

	AABBhScale = glm::vec3(hSide, hSide, hSide);
}

//AABB - Axis aligned bounding box

//Rotateable cube collider
	//translate positions into new 
//Sphere collider
//Capsule collider