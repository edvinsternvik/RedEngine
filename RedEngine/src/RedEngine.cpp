#include "RedEngine.h"
#include "Debug.h"

RedEngine::RedEngine() {
}

RedEngine::~RedEngine() {
	delete m_window;
	delete m_camera;
	delete m_shader;
	delete m_gameObjectManager;
	delete m_renderer;
	delete m_time;
}

void RedEngine::init(int width, int height, const char* title, bool enableCursor) {
	m_window = new Window(width, height, title, enableCursor);
	
	if (glewInit() != GLEW_OK) {
		std::cout << "GLEW INIT FAILED" << std::endl;
	}

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	m_camera = new Camera(glm::vec3(0.0f), glm::vec3(0.0f), CameraType::Perspective, glm::vec2(m_window->getWidth(), m_window->getHeight()));
	m_shader = new Shader;
	m_gameObjectManager = new GameObjectManager;
	m_renderer = new Renderer(m_camera, m_gameObjectManager, m_shader);
	m_time = new Time;

	start();

	loop();
}

void RedEngine::loop() {
	while (!glfwWindowShouldClose(m_window->getWindow())) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		m_time->updateDeltaTime();
		
		update();

		m_window->resetMouseDelta();

		m_renderer->renderFrame();

		glfwSwapBuffers(m_window->getWindow());
		glfwPollEvents();
	}
}
