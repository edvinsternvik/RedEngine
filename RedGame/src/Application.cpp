
#include <RedEngine.h>

class TestGame : public RedEngine {
public:
	using RedEngine::RedEngine;

	Model* m;
	GameObject* go;
	Texture* tex;
	double timeCounter;
	int frameCounter;

	virtual void start() override {
		getWindow()->enableVSync(true);

		tex = new Texture("assets/img/lowPolyIslandTexture.png");
		m = new Model("assets/models/lowPolyIsland2.obj", tex);
		go = getGameObjectManager()->createGameObject(glm::vec3(0.0f, -2.0f, 0.0f), glm::vec3(0.0f), m);
		getGameObjectManager()->createLight(glm::vec3(0.0f, 4.0f, 0.0f));
	}

	virtual void update() override {
		if (getWindow()->getKey(GLFW_KEY_ESCAPE)) getWindow()->setCusorEnabled(!getWindow()->getCursorEnabled());

		float walkingSpeed = getTime()->getDeltaTime() * 2.0f;
		if (getWindow()->getKeyDown(GLFW_KEY_W)) getCamera()->move(glm::vec3(0.0f, 0.0f, -walkingSpeed));
		if (getWindow()->getKeyDown(GLFW_KEY_S)) getCamera()->move(glm::vec3(0.0f, 0.0f,  walkingSpeed));
		if (getWindow()->getKeyDown(GLFW_KEY_A)) getCamera()->move(glm::vec3(-walkingSpeed, 0.0f, 0.0f));
		if (getWindow()->getKeyDown(GLFW_KEY_D)) getCamera()->move(glm::vec3(walkingSpeed, 0.0f, 0.0f));
		if (getWindow()->getKeyDown(GLFW_KEY_Q)) getCamera()->move(glm::vec3(0.0f, -walkingSpeed, 0.0f));
		if (getWindow()->getKeyDown(GLFW_KEY_E)) getCamera()->move(glm::vec3(0.0f, walkingSpeed, 0.0f));

		double xpos, ypos;
		getWindow()->getMouseDelta(xpos, ypos);
		getCamera()->rotate(glm::vec3(0.0f, xpos * 0.03f, 0.0f));

		timeCounter += getTime()->getDeltaTime();
		frameCounter++;
		if (timeCounter > 1.0) {
			std::cout << frameCounter << std::endl;
			timeCounter--;
			frameCounter = 0;
		}
	}

	virtual void render() {
		
	}
};

int main() {
	TestGame game;

	game.init(1280, 720, "Hello there", false);

	game.start();
}