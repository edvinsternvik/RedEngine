#include "../src/RedEngine.h"

class TestGame : public RedEngine {
public:
	using RedEngine::RedEngine;

	Model* m;
	GameObject* go;

	virtual void start() override {
		m = new Model("models/lowPolyIsland.obj");
		go = getGameObjectManager()->createGameObject(glm::vec3(0.0f, 0.0f, -10.0f), glm::vec3(0.0f), m);
	}

	virtual void update() override {
		go->rotate(glm::vec3(0.0f, 0.01f, 0.0f));
	}

};

int main() {
	TestGame game;

	game.init(1280, 720, "Hello there", true);

	game.start();
}