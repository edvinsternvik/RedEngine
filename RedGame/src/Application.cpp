#include <RedEngine.h>

class TestGame : public RedEngine {
public:
	using RedEngine::RedEngine;

	Model* m;
	GameObject* go;
	Camera* cam;

	virtual void start() override {
		m = new Model("models/lowPolyIsland.obj");
		go = getGameObjectManager()->createGameObject(glm::vec3(0.0f, 0.0f, -10.0f), glm::vec3(0.0f), m);
		cam = getCamera();
	}

	virtual void update() override {
		if (Window::INSTANCE->getKey(GLFW_KEY_W)) cam->move(glm::vec3(0.0f, 0.0f, -0.0005f));
		if (Window::INSTANCE->getKey(GLFW_KEY_S)) cam->move(glm::vec3(0.0f, 0.0f,  0.0005f));
		if (Window::INSTANCE->getKey(GLFW_KEY_A)) cam->move(glm::vec3(-0.0005f, 0.0f, 0.0f));
		if (Window::INSTANCE->getKey(GLFW_KEY_D)) cam->move(glm::vec3(0.0005f, 0.0f, 0.0f));

		double xpos, ypos;
		Window::INSTANCE->getMouseDelta(xpos, ypos);
		cam->rotate(glm::vec3(0.0f, xpos * 0.03f, 0.0f));

		if (Window::INSTANCE->getKey(GLFW_KEY_ESCAPE)) glfwSetWindowShouldClose(Window::INSTANCE->getWindow(), true);
	}

};

int main() {
	TestGame game;

	game.init(1280, 720, "Hello there", false);

	game.start();
}