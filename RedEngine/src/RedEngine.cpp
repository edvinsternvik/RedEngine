#include "RedEngine.h"
#include "Debug.h"

RedEngine::RedEngine() {
}

RedEngine::~RedEngine() {
	delete m_window;
	delete m_shader;
	delete m_renderer;
	delete m_time;
	delete m_gameObjectManager;
	delete m_physicsManager;
}

void RedEngine::init(int width, int height, const char* title, CameraType cameraType) {
	m_window = new Window(width, height, title);

	if (glewInit() != GLEW_OK) {
		std::cout << "GLEW INIT FAILED" << std::endl;
	}

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	m_shader = new Shader;
	m_gameObjectManager = new GameObjectManager;
	m_camera = m_gameObjectManager->createCamera(glm::vec3(0.0f), glm::vec3(0.0f), cameraType, glm::vec2(width, height));
	m_renderer = new Renderer(m_camera, m_gameObjectManager, m_shader);
	m_time = Time::Instantiate();
	m_input = Input::instantiate();
	m_physicsManager = new PhysicsManager();

	start();

	glClearColor(0.26f, 0.69f, 1.0f, 1.0f);
	loop();
}

void RedEngine::loop() {
	while (!glfwWindowShouldClose(m_window->getWindow())) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		m_time->updateDeltaTime();
		m_physicsManager->calculateCollisions();
		
		update();
		for (GameObject* go : *m_gameObjectManager->getGameObjectList()) {
			for (Component* component : *go->getComponentList()) {
				component->update();
			}
		}

		m_input->updateInput();

		m_renderer->renderFrame();

		render();

		glfwSwapBuffers(m_window->getWindow());
		glfwPollEvents();
	}
}
