#pragma once

class GameObject;

class Component {
public:
	const GameObject* gameObject;
	bool enabled = true;
public:
	Component() {}
	~Component() {}

	virtual void init() {}
	virtual void start() {}
	virtual void update() {}
private:
	void setParentGameObject(GameObject* gameObject) { this->gameObject = gameObject; }
	friend class GameObject;
};