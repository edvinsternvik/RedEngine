#include "RedEngine.h"
#include "Debug.h"

RedEngine::RedEngine() {
}

RedEngine::~RedEngine() {
	delete m_window;
	delete m_shader;
	delete m_renderer;
	delete m_sceneManager;
	delete m_time;
}

void RedEngine::init(int width, int height, const char* title) {
	m_window = new Window(width, height, title);

	//This should be in the renderer constructor but it neads to be done before initializing m_shader or any other OpenGL specific code
	if (glewInit() != GLEW_OK) {
		std::cout << "GLEW INIT FAILED" << std::endl;
	}

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//---------------------------------------------------------------------------------------------------------------------------------

	m_shader = new Shader;
	m_renderer = new Renderer(m_shader);
	m_sceneManager = new SceneManager();
	m_time = Time::Instantiate();
	m_input = Input::instantiate();

	start();

	glClearColor(0.26f, 0.69f, 1.0f, 1.0f);
	loop();
}

void RedEngine::loop() {
	while (!glfwWindowShouldClose(m_window->getWindow())) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		m_time->updateDeltaTime();
		
		update();

		m_sceneManager->getCurrentScene()->updateObjects();

		m_input->updateInput();

		m_sceneManager->getCurrentScene()->renderScene(m_renderer);

		render();

		glfwSwapBuffers(m_window->getWindow());
		glfwPollEvents();
	}
}
