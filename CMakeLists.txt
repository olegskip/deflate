cmake_minimum_required(VERSION 3.0)
project(deflate VERSION 0.0 LANGUAGES CXX)
#set(CMAAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -g")
add_compile_options(-std=c++17
	-Wall
	-Wextra
	-g)

add_subdirectory(src)
