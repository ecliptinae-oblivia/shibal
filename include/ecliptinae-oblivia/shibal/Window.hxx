// SPDX-FileCopyrightText: Copyright (C) Nile Jocson <nile.oblivia@gmail.com>
// SPDX-License-Identifier: MPL-2.0



#ifndef ECLIPTINAE_OBLIVIA_SHIBAL_INCLUDE_ECLIPTINAE_OBLIVIA_SHIBAL_WINDOW_HXX
#define ECLIPTINAE_OBLIVIA_SHIBAL_INCLUDE_ECLIPTINAE_OBLIVIA_SHIBAL_WINDOW_HXX

#include <concepts>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "imgui.h"



namespace ecliptinae_oblivia::shibal
{
	class Window
	{
	public:
		Window();
		~Window() noexcept;

	public:
		template<typename T> requires std::invocable<T>
		auto loop(T f) -> void;

	private:
		GLFWwindow *m_window;
	};



	template<typename T> requires std::invocable<T>
	auto Window::loop(T body) -> void
	{
		while (!glfwWindowShouldClose(m_window))
		{
			ImGui_ImplGlfw_NewFrame();
			ImGui_ImplOpenGL3_NewFrame();
			ImGui::NewFrame();

			body();

			ImGui::Render();

			auto width = 0;
			auto height = 0;
			glfwGetFramebufferSize(m_window, &width, &height);
			glViewport(0, 0, width, height);
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

			glfwSwapBuffers(m_window);
			glfwPollEvents();
		}
	}
}



#endif
