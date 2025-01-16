// SPDX-FileCopyrightText: Copyright (C) Nile Jocson <nile.oblivia@gmail.com>
// SPDX-License-Identifier: MPL-2.0



#include <cstdlib>

#include "imgui.h"

#include "ecliptinae-oblivia/shibal/Window.hxx"
#include "ecliptinae-oblivia/shibal/ui.hxx"




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
		shibal::ui::window("shibal", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoBringToFrontOnFocus, [&]() -> void
		{
			ImGui::Checkbox("Show Demo Window", &show_demo_window);

			if (show_demo_window)
			{
				ImGui::ShowDemoWindow();
			}
		});
	});

	return EXIT_SUCCESS;
}
