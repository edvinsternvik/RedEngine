#include <RedEngine.h>
#include <Gui.h>

class TestGame : public RedEngine {
public:
	Texture* tex;
	Model* model;

	virtual void start() override {
		tex = new Texture("assets/img/ball.png");
		model = new Model("assets/models/quad.obj", tex);
		getGameObjectManager()->createGameObject(glm::vec3(0.0f), glm::vec3(0.0f), glm::vec3(1.0f), model);
	}

	int frameCounter = 0;
	float timeCounter = 0.0f;
	virtual void update() override {
		timeCounter += getTime()->getDeltaTime();
		frameCounter++;
		if (timeCounter > 1.0) {
			std::cout << frameCounter << std::endl;
			timeCounter--;
			frameCounter = 0;
		}
		
	}

	virtual void render() override {
	}
};

int main() {
	TestGame t;

	t.init(1280, 720, "hello", CameraType::Orthographic);
	t.start();
}