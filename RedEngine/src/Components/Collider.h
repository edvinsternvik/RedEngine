#pragma once
#include "Component.h"

enum class ColliderType {
	CubeCollider, SphereCollider
};

class CubeCollider;
class SphereCollider;

class Collider : public Component {
public:
	glm::vec3 offset, rotation;
	
private:
	glm::vec3 scale, AABBhScale;
	
public:
	Collider(glm::vec3 offset, glm::vec3 rotation, glm::vec3 scale);
	~Collider();

	virtual void init() override;

	inline virtual ColliderType getColliderType() = 0;

	bool AABB(Collider* other);

	bool isCollidingWith(Collider* other, ColliderType colliderType);

	virtual bool cubeCollision(CubeCollider* other) = 0;
	virtual bool sphereCollision(SphereCollider* other) = 0;

	void setScale(glm::vec3 newScale);
	inline const glm::vec3* getScale() const { return &scale; }

protected:
	virtual void calculateAABBscale();

	//inline const glm::vec3* getAABBhScale() const { return &AABBhScale; }
};