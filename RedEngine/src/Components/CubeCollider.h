#pragma once
#include "Collider.h"

//UPDATE ROTATIONMATRIX WHEN ROTATING

class CubeCollider : public Collider {
private:
	glm::vec3 vertecies[8]{
		glm::vec3(-1, -1, 1), glm::vec3(1, -1, 1), glm::vec3(1, 1, 1), glm::vec3(-1, 1, 1),
		glm::vec3(-1, -1, -1), glm::vec3(1, -1, -1), glm::vec3(1, 1, -1), glm::vec3(-1, 1, -1)
	};
	glm::mat4 rotationMatrix, invertedRotationMatrix;

public:
    CubeCollider(glm::vec3 offset, glm::vec3 rotation, glm::vec3 scale);
    ~CubeCollider();

    virtual void start() override;
	virtual void update() override;

	inline virtual ColliderType getColliderType() override { return ColliderType::CubeCollider; }

	virtual bool cubeCollision(CubeCollider* other) override;
	virtual bool sphereCollision(SphereCollider* other) override;

private:
	bool calculateCubeCollision(CubeCollider* other);

	void setRotationMatrix();
	void setInvertedRotationMatrix();
};