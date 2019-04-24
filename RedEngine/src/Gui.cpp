// #include "Gui.h"
// #include <imgui\imgui.h>
// #include <imgui\imgui_impl_glfw.h>
// #include <imgui\imgui_impl_opengl3.h>

// Gui::Gui(GLFWwindow* window) {
// 	IMGUI_CHECKVERSION();
// 	ImGui::CreateContext();

// 	ImGui::StyleColorsDark();
// 	ImGui_ImplGlfw_InitForOpenGL(window, true);
// 	ImGui_ImplOpenGL3_Init("#version 130");
// }

// Gui::~Gui() {
// }

// void Gui::renderGui() {
// 	ImGui_ImplOpenGL3_NewFrame();
// 	ImGui_ImplGlfw_NewFrame();
// 	ImGui::NewFrame();

// 	ImGui::Begin("hello");
// 	ImGui::Text("hello there");
// 	ImGui::End();

// 	ImGui::Render();
// 	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
// }
