// SPDX-FileCopyrightText: Copyright (C) Nile Jocson <nile.oblivia@gmail.com>
// SPDX-License-Identifier: MPL-2.0



#include "ecliptinae-oblivia/shibal/Window.hxx"

#include <stdexcept>

#include "imgui.h"




namespace ecliptinae_oblivia::shibal
{
	Window::Window()
	{
		if (!glfwInit())
		{
			throw std::runtime_error("Failed to initialize GLFW.");
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_window = glfwCreateWindow(1280, 720, "shibal", nullptr, nullptr);
		if (m_window == nullptr)
		{
			throw std::runtime_error("Failed to create GLFW window.");
		}

		glfwMakeContextCurrent(m_window);
		if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
		{
			throw std::runtime_error("Failed to initialize GLAD.");
		}

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		[[maybe_unused]] auto &io = ImGui::GetIO();

		ImGui::StyleColorsLight();

		if (!ImGui_ImplGlfw_InitForOpenGL(m_window, true))
		{
			throw std::runtime_error("Failed to initialize ImGui for GLFW for OpenGL.");
		}

		if (!ImGui_ImplOpenGL3_Init("#version 460"))
		{
			throw std::runtime_error("Failed to initialize ImGui for OpenGL3.");
		}
	}

	Window::~Window() noexcept
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();

		glfwTerminate();
	}
}
