#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.h"
#include "GameObjectManager.h"
#include "Renderer.h"
#include "Camera.h"

#include <chrono>

glm::vec3 pos = glm::vec3(0.0f);
bool pressedKeys[4];
	
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_W && action == GLFW_PRESS) {
		pressedKeys[0] = true;
	}
	if (key == GLFW_KEY_W && action == GLFW_RELEASE) {
		pressedKeys[0] = false;
	}

	if (key == GLFW_KEY_D && action == GLFW_PRESS) {
		pressedKeys[1] = true;
	}
	if (key == GLFW_KEY_D && action == GLFW_RELEASE) {
		pressedKeys[1] = false;
	}

	if (key == GLFW_KEY_S && action == GLFW_PRESS) {
		pressedKeys[2] = true;
	}
	if (key == GLFW_KEY_S && action == GLFW_RELEASE) {
		pressedKeys[2] = false;
	}

	if (key == GLFW_KEY_A && action == GLFW_PRESS) {
		pressedKeys[3] = true;
	}
	if (key == GLFW_KEY_A && action == GLFW_RELEASE) {
		pressedKeys[3] = false;
	}
}

void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos) {
}

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	glm::vec2 windowSize(1280.0f, 720.0f);
	window = glfwCreateWindow(windowSize.x, windowSize.y, "Red Game Engine", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, cursor_pos_callback);

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		std::cout << "GLEW INIT FAILED" << std::endl;
	}

	Shader shader;
	Camera camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f), CameraType::Perspective, windowSize);
	GameObjectManager gameObjectManager;
	Renderer renderer(&camera, &gameObjectManager, &shader);

	int lightPosUniformLocation = shader.getUniformLocation("lightPos");
	glm::vec3 lPos(-4.0f, 3.0f, 1.0f);
	shader.setUniformVec3f(lightPosUniformLocation, &lPos[0]);
	
	Model m("models/lowPolyIsland.obj");
	GameObject* go = gameObjectManager.createGameObject(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f), &m);

	std::chrono::high_resolution_clock timer;
	auto start = timer.now();
	auto stop = timer.now();
	int frameCounter = 0;
	double timeCounter = 0.0f;

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	glEnable(GL_DEPTH_TEST);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		stop = timer.now();
		double deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
		frameCounter++;
		timeCounter += deltaTime;
		if (timeCounter > 1000000.0) {
			std::cout << frameCounter << std::endl;
			frameCounter = 0;
			timeCounter = 0;

		}
		start = timer.now();

		if (pressedKeys[0]) pos.z-=.001f;
		if (pressedKeys[1]) pos.x += .001f;
		if (pressedKeys[2]) pos.z += .001f;
		if (pressedKeys[3]) pos.x -= .001f;

		//go->rotate(glm::vec3(0.01f, 0.01f, 0.01f));
		//go->move(glm::vec3(0.001f, 0.0f, 0.0f));
		camera.setPosition(pos);
		renderer.renderFrame();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}