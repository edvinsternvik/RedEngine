#include <RedEngine.h>
#include <Gui.h>

class TestGame : public RedEngine {
public:
	Texture* tex;
	Model* model;

	virtual void start() override {
		tex = new Texture("assets/img/ball.png");
		model = new Model("assets/models/quad.obj", tex);
		getGameObjectManager()->createGameObject(glm::vec3(0.0f), glm::vec3(1.0f), glm::vec3(0.0f), model);
	}

	virtual void update() override {
	}

	virtual void render() override {
	}
};

int main() {
	TestGame t;

	t.init(1280, 720, "hello", CameraType::Orthographic);
	t.start();
}