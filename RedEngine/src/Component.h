#pragma once

class GameObject;

class Component {
public:
	bool enabled = true;
	GameObject* gameObject;

public:
	Component();

	virtual void init() {}
	virtual void start() {}
	virtual void update() {}
	
protected:
	inline void setGameObject(GameObject* gameObject) { this->gameObject = gameObject; }

	friend class GameObject;
};