#include <RedEngine.h>
#include "Components\CameraScript.h"
#include "Components\TestComponent.h"

class TestGame : public RedEngine {
public:
	Model* m;
	Model* m2;
	GameObject* go;
	Texture* tex;
	double timeCounter;
	int frameCounter;

	virtual void start() override {
		getWindow()->enableVSync(true);
		Input::setCusorEnabled(false);
		
		tex = new Texture("assets/img/lowPolyIslandTexture.png");
		m = new Model("assets/models/lowPolyIsland2.obj", tex);
		m2 = new Model("assets/models/cube.obj", tex);
		go = getGameObjectManager()->createGameObject(glm::vec3(0.0f, -2.0f, 0.0f), glm::vec3(0.0f), glm::vec3(1.0f), m);
		getCamera()->addComponent(new CameraScript);
		getGameObjectManager()->createLight(glm::vec3(5.0f, 0.0f, 0.0f));
		getGameObjectManager()->createLight(glm::vec3(0.0f, 2.0f, 0.0f));
	}
	
	virtual void update() override {
		if (Input::getKey(GLFW_KEY_ESCAPE)) Input::setCusorEnabled(!Input::getCursorEnabled());

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

	game.init(1280, 720, "Hello there", CameraType::Perspective);

	game.start();
}