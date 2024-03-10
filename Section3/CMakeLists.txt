cmake_minimum_required(VERSION 3.0)

project(LinkedListExample VERSION 1.0.0 LANGUAGES CXX)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc ${CMAKE_CURRENT_SOURCE_DIR}/dep)

add_executable(${PROJECT_NAME} src/Main.cpp
	src/LinkedList.cpp
	src/Person.cpp
)
