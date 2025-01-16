// SPDX-FileCopyrightText: Copyright (C) Nile Jocson <nile.oblivia@gmail.com>
// SPDX-License-Identifier: MPL-2.0



#include <cstdlib>

#include "ecliptinae-oblivia/shibal/Window.hxx"
#include "imgui.h"



auto main() -> int
{
	using namespace ecliptinae_oblivia;

	auto window = shibal::Window();

	window.loop([]() -> void
	{
		auto show = true;
		ImGui::ShowDemoWindow(&show);
	});

	return EXIT_SUCCESS;
}
