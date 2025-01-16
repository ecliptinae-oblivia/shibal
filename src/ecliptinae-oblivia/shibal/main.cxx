// SPDX-FileCopyrightText: Copyright (C) Nile Jocson <nile.oblivia@gmail.com>
// SPDX-License-Identifier: MPL-2.0



#include <cstdlib>

#include "ecliptinae-oblivia/shibal/Window.hxx"

#include "imgui.h"



auto main() -> int
{
	using namespace ecliptinae_oblivia;

	auto window = shibal::Window();

	auto show_demo_window = false;

	window.loop([&]() -> void
	{
		auto const *viewport = ImGui::GetMainViewport();
		ImGui::SetNextWindowPos(viewport->WorkPos);
		ImGui::SetNextWindowSize(viewport->WorkSize);
		if (ImGui::Begin("shibal", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoBringToFrontOnFocus))
		{
			ImGui::Checkbox("Show Demo Window", &show_demo_window);

			if (show_demo_window)
			{
				ImGui::ShowDemoWindow();
			}
		}
		ImGui::End();
	});

	return EXIT_SUCCESS;
}
