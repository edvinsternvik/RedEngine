#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.h"
#include "GameObjectManager.h"
#include "Renderer.h"
#include "Camera.h"

glm::vec3 pos = glm::vec3(0.0f);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_W && action == GLFW_PRESS) {
		pos.z -= 0.1f;
	}
	if (key == GLFW_KEY_A && action == GLFW_PRESS) {
		pos.x -= 0.1f;
	}
	if (key == GLFW_KEY_S && action == GLFW_PRESS) {
		pos.z += 0.1f;
	}
	if (key == GLFW_KEY_D && action == GLFW_PRESS) {
		pos.x += 0.1f;
	}
}

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;


	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(1280, 720, "Red Game Engine", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwSetKeyCallback(window, key_callback);

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		std::cout << "GLEW INIT FAILED" << std::endl;
	}

	Shader shader;
	Camera camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f));
	GameObjectManager gameObjectManager;
	Renderer renderer(&camera, &gameObjectManager, &shader);
	//std::cout << "sdgosd" << std::endl;
	//for (auto a : mData.vertexData) {
	//	std::cout << a.positions.x << std::endl;
	//	std::cout << a.positions.y << std::endl;
	//	std::cout << a.positions.z << std::endl;
	//	std::cout << std::endl;
	//}

	//for (int b : mData.indexData) {
	//	std::cout << b << std::endl;
	//}

	Model m;
	GameObject* go = gameObjectManager.createGameObject(glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f), &m);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		go->rotate(glm::vec3(0.01f, 0.01f, 0.01f));
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