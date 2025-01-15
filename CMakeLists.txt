# SPDX-FileCopyrightText: Copyright (C) Nile Jocson <nile.oblivia@gmail.com>
# SPDX-License-Identifier: MPL-2.0



cmake_minimum_required(VERSION 3.21)

project(
	"shibal"
	VERSION 0.1.0
	LANGUAGES C CXX
)



add_subdirectory("vendor/glfw")

set(glad_src "vendor/glad/src/glad.c")
set(glad_include "vendor/glad/include")

set(
	imgui_src
	"vendor/imgui/backends/imgui_impl_glfw.cpp"
	"vendor/imgui/backends/imgui_impl_opengl3.cpp"
	"vendor/imgui/imgui.cpp"
	"vendor/imgui/imgui_demo.cpp"
	"vendor/imgui/imgui_draw.cpp"
	"vendor/imgui/imgui_tables.cpp"
	"vendor/imgui/imgui_widgets.cpp"
)
set(imgui_include "vendor/imgui")



set(
	project_src
	"src/ecliptinae-oblivia/shibal/main.cxx"
)

add_executable(${PROJECT_NAME} ${project_src} ${glad_src} ${imgui_src})

target_include_directories(${PROJECT_NAME} PRIVATE ${glad_include} ${imgui_include})

target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

if (MSVC)
	target_compile_options(${PROJECT_NAME} PRIVATE "/W4" "/w14640" "/permissive-")
else ()
	target_compile_options(${PROJECT_NAME} PRIVATE "-Wall" "-Wextra" "-Wshadow" "-Wnon-virtual-dtor" "-Wpedantic")
endif ()
