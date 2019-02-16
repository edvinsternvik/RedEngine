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
		m = new Model("assets/models/lowPolyIsland.obj");
		tex = new Texture("assets/img/lowPolyIslandTexture.png");
		go = getGameObjectManager()->createGameObject(glm::vec3(0.0f, 0.0f, -10.0f), glm::vec3(0.0f), m);
		int texLoc = getShader()->getUniformLocation("u_Texture");
		getShader()->setUniform1i(texLoc, 0);
		getWindow()->enableVSync(true);

		glm::vec3 lPos(0.0f, 10.0f, 10.0f);
		int lightUniformLocation = getShader()->getUniformLocation("lightPos");
		getShader()->setUniformVec3f(lightUniformLocation, &lPos[0]);
	}

	virtual void update() override {
		if (getWindow()->getKey(GLFW_KEY_ESCAPE)) glfwSetWindowShouldClose(Window::INSTANCE->getWindow(), true);

		float walkingSpeed = getTime()->getDeltaTime() * 2.0f;
		if (getWindow()->getKey(GLFW_KEY_W)) getCamera()->move(glm::vec3(0.0f, 0.0f, -walkingSpeed));
		if (getWindow()->getKey(GLFW_KEY_S)) getCamera()->move(glm::vec3(0.0f, 0.0f,  walkingSpeed));
		if (getWindow()->getKey(GLFW_KEY_A)) getCamera()->move(glm::vec3(-walkingSpeed, 0.0f, 0.0f));
		if (getWindow()->getKey(GLFW_KEY_D)) getCamera()->move(glm::vec3(walkingSpeed, 0.0f, 0.0f));

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
};

int main() {
	TestGame game;

	game.init(1280, 720, "Hello there", false);

	game.start();
}