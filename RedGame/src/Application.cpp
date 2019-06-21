#include <RedEngine.h>
#include "Components/CameraScript.h"
#include "Components/TestComponent.h"

class TestGame : public RedEngine {
public:
	Scene* currentScene;

	double timeCounter;
	int frameCounter;

	virtual void start() override {
		getWindow()->enableVSync(true);
		Input::setCusorEnabled(false);

		currentScene = getSceneManager()->getCurrentScene();

		Texture* tex = new Texture("assets/img/crate.png", FilterMode::Linear);
		Texture* texSpec = new Texture("assets/img/crate_specular.png", FilterMode::Nearest);
		Model* m = new Model("assets/models/cube.obj", tex, texSpec);

		GameObject* go = currentScene->createGameObject(glm::vec3(0.0f, -2, 0.0f), glm::vec3(0.0f), glm::vec3(10.0f, 0.1f, 10.0f), m);
		currentScene->createGameObject(glm::vec3(-3.0f, 0, -8.0f), glm::vec3(0.0f, 52.0f, 0.0f), glm::vec3(3.0f, 2.0f, 1.0f), m);
		currentScene->createGameObject(glm::vec3(5.0f, 0, 3.0f), glm::vec3(0.0f, 32.0f, 0.0f), glm::vec3(3.0f, 2.0f, 1.0f), m);
		go->addComponent(new CubeCollider(glm::vec3(0.0f), glm::vec3(1.0f), glm::vec3(0.0f)));
		currentScene->createLight(glm::vec3(0, 2, 0), 1.0f);
		currentScene->createCamera(glm::vec3(0.0f), glm::vec3(0.0f), CameraType::Perspective, glm::vec2(1280, 720));
		currentScene->getCamera()->addComponent(new CameraScript);
		
		int sceneIndex = getSceneManager()->addScene();
		getSceneManager()->changeScene(sceneIndex);
		getSceneManager()->getCurrentScene()->createCamera(glm::vec3(0.0f), glm::vec3(0.0f), CameraType::Perspective, glm::vec2(1280, 720));
		getSceneManager()->getCurrentScene()->getCamera()->addComponent(new CameraScript);
		getSceneManager()->getCurrentScene()->createGameObject(glm::vec3(0.0f), glm::vec3(0.0f), glm::vec3(1.0f), m);
		getSceneManager()->changeScene(0);
	}
	
	virtual void update() override {
		if (Input::getKey(GLFW_KEY_ESCAPE)) Input::setCusorEnabled(!Input::getCursorEnabled());

		timeCounter += getTime()->getDeltaTime();
		frameCounter++;
		if (timeCounter > 1.0) {
			gameEngineDebug(frameCounter);
			timeCounter--;
			frameCounter = 0;
		}

		if(Input::getKey(GLFW_KEY_L)) getSceneManager()->nextScene();
	}

	virtual void render() {
		
	}
};

int main() {
	TestGame game;

	game.init(1280, 720, "Hello there");

	game.start();
}