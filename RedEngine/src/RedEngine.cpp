#include "RedEngine.h"
#include "Debug.h"

#include <imgui\imgui.h>
#include <imgui\imgui_impl_glfw.h>
#include <imgui\imgui_impl_opengl3.h>

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

void RedEngine::init(int width, int height, const char* title, CameraType cameraType) {
	m_window = new Window(width, height, title);
	
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(getWindow()->getWindow(), true);
	ImGui_ImplOpenGL3_Init("#version 130");

	if (glewInit() != GLEW_OK) {
		std::cout << "GLEW INIT FAILED" << std::endl;
	}

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	m_camera = new Camera(glm::vec3(0.0f), glm::vec3(0.0f), cameraType, glm::vec2(m_window->getWidth(), m_window->getHeight()));
	m_shader = new Shader;
	m_gameObjectManager = new GameObjectManager;
	m_renderer = new Renderer(m_camera, m_gameObjectManager, m_shader);
	m_time = new Time;

	start();

	glClearColor(0.26f, 0.69f, 1.0f, 1.0f);
	loop();
}

void RedEngine::loop() {
	while (!glfwWindowShouldClose(m_window->getWindow())) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		m_time->updateDeltaTime();
		
		update();

		m_window->updateInput();

		m_renderer->renderFrame();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		ImGui::Begin("hello");
		ImGui::Text("hello there");
		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		render();

		glfwSwapBuffers(m_window->getWindow());
		glfwPollEvents();
	}
}
