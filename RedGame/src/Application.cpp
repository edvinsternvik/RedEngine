#include <RedEngine.h>
#include "Components/CameraScript.h"
#include "Components/TestComponent.h"

class TestGame : public RedEngine {
public:
	double timeCounter;
	int frameCounter;

	virtual void start() override {
		getWindow()->enableVSync(true);
		Input::setCusorEnabled(false);

		Texture* tex = new Texture("assets/img/crate.png", FilterMode::Nearest);
		Texture* texSpec = new Texture("assets/img/crate_specular.png", FilterMode::Nearest);
		Model* m = new Model("assets/models/cube.obj", tex, texSpec);
		GameObject* go = getGameObjectManager()->createGameObject(glm::vec3(0.0f, -2.0f, -4.0f), glm::vec3(0.0f), glm::vec3(1.0f), m);
		getGameObjectManager()->createLight(glm::vec3(0, 2, 0));
		getCamera()->addComponent(new CameraScript);
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