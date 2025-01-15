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



	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.6314f, 0.8902f, 0.8235f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}



	glfwTerminate();

	return EXIT_SUCCESS;
}
