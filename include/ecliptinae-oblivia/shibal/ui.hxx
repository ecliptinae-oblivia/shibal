// SPDX-FileCopyrightText: Copyright (C) Nile Jocson <nile.oblivia@gmail.com>
// SPDX-License-Identifier: MPL-2.0



#ifndef ECLIPTINAE_OBLIVIA_SHIBAL_INCLUDE_ECLIPTINAE_OBLIVIA_SHIBAL_UI_HXX
#define ECLIPTINAE_OBLIVIA_SHIBAL_INCLUDE_ECLIPTINAE_OBLIVIA_SHIBAL_UI_HXX

#include <concepts>
#include <string>

#include "imgui.h"



namespace ecliptinae_oblivia::shibal::ui
{
	template<typename T> requires std::invocable<T>
	auto window(std::string const &name, bool *open, int flags, T body) -> void;



	template<typename T> requires std::invocable<T>
	auto window(std::string const &name, bool *open, int flags, T body) -> void
	{
		if (ImGui::Begin(name.c_str(), open, flags))
		{
			body();
		}
		ImGui::End();
	}
}



#endif
