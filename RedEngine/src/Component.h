#pragma once
#include "GameObject.h"

class GameObject;

class Component {
protected:
	GameObject* m_gameObject;
public:
	bool enabled = true;
public:
	Component() {}
	~Component() {}

	virtual void init() {}
	virtual void start() {}
	virtual void update() {}

	inline GameObject* const getParentGameObject() const { return m_gameObject; }
private:
	void setParentGameObject(GameObject* gameObject) { m_gameObject = gameObject; }
	friend class GameObject;
};