# SPDX-FileCopyrightText: Copyright (C) Nile Jocson <nile.oblivia@gmail.com>
# SPDX-License-Identifier: MPL-2.0



cmake_minimum_required(VERSION 3.21)

project(
	"shibal"
	VERSION 0.1.0
	LANGUAGES CXX
)



add_executable(
	${PROJECT_NAME}
	"src/main.cxx"
)



target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

if (MSVC)
	target_compile_options(${PROJECT_NAME} PRIVATE "/W4" "/w14640" "/permissive-")
else ()
	target_compile_options(${PROJECT_NAME} PRIVATE "-Wall" "-Wextra" "-Wshadow" "-Wnon-virtual-dtor" "-Wpedantic")
endif ()
