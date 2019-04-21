#include <RedEngine.h>
#include "Components/CameraScript.h"
#include "Components/TestComponent.h"

class TestGame : public RedEngine {
public:
	Model* m;
	GameObject* go;
	Texture* tex, *texSpec;
	double timeCounter;
	int frameCounter;

	virtual void start() override {
		getWindow()->enableVSync(true);
		Input::setCusorEnabled(false);

		tex = new Texture("RedGame/assets/img/crate.png", FilterMode::Nearest);
		texSpec = new Texture("RedGame/assets/img/crate_specular.png", FilterMode::Nearest);
		m = new Model("RedGame/assets/models/cube.obj", tex, texSpec);
		go = getGameObjectManager()->createGameObject(glm::vec3(0.0f, 0.0f, -2.0f), glm::vec3(0.0f), glm::vec3(1.0f), m);
		getGameObjectManager()->createLight(glm::vec3(3, 2, 4));
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