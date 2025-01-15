// SPDX-FileCopyrightText: Copyright (C) Nile Jocson <nile.oblivia@gmail.com>
// SPDX-License-Identifier: MPL-2.0



#include <cstdlib>

#include <exception>
#include <stdexcept>
#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "imgui.h"

#include "ecliptinae-oblivia/shibal/Window.hxx"



auto main() -> int
{
	if (!glfwInit())
	{
		throw std::runtime_error("Failed to initialize GLFW.");
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	auto window = glfwCreateWindow(1280, 720, "shibal", nullptr, nullptr);
	if (window == nullptr)
	{
		throw std::runtime_error("Failed to create GLFW window.");
	}

	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
	{
		throw std::runtime_error("Failed to initialize GLAD.");
	}



	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	[[maybe_unused]] auto &io = ImGui::GetIO();

	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 460");



	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();



		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		auto show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();

		auto width = 0;
		auto height = 0;
		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}



	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwTerminate();

	return EXIT_SUCCESS;
}
