cmake_minimum_required(VERSION 3.10)
project(EditorApp VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

add_executable(EditorApp main.cpp)

target_link_libraries(EditorApp
	PRIVATE
		GlenEngine
		GlenEditor
		ImGui	
		glfw
)

target_include_directories(EditorApp
	PRIVATE
	${CMAKE_SOURCE_DIR}/GlenEngine/public
	${CMAKE_SOURCE_DIR}/GlenEditor/public
)

