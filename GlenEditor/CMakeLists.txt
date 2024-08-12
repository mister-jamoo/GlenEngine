set(MODULE_NAME GlenEditor)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(Vulkan REQUIRED)

# Add GLFW
set(GLFW_BUILD_DOCS ON CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/private/include/ThirdParty/glfw GLFW_BUILD)

# Add IMGUI
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/private/include/ThirdParty/imgui)
set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp 
	${IMGUI_DIR}/backends/imgui_impl_vulkan.cpp
)

add_library(ImGui STATIC ${IMGUI_SOURCES})

target_link_libraries(ImGui
	PRIVATE
		glfw
)

target_include_directories(ImGui 
	PUBLIC 
		${IMGUI_DIR}
		${IMGUI_DIR}/backends
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/private/include/ThirdParty/glfw/include
)

target_link_libraries(ImGui
        PRIVATE
        Vulkan::Vulkan
        glfw
)

# GLM
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/private/include/ThirdParty/glm)

# GLENEDTIOR

file(GLOB_RECURSE SOURCES 
		"${CMAKE_CURRENT_SOURCE_DIR}/private/src/*.cpp"
)

add_library(${MODULE_NAME} SHARED ${SOURCES})

target_include_directories(${MODULE_NAME}
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/public>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/private/include
		${IMGUI_DIR}
		${IMGUI_DIR}/backends
		${CMAKE_CURRENT_SOURCE_DIR}/private/include/ThirdParty/glfw/include
		${GLM_INCLUDE_DIRS}
)

# Add any third-party libraries
target_link_libraries(${MODULE_NAME}
    PUBLIC
        # Add any public dependencies
    PRIVATE
		GlenEngine
		glfw
		ImGui
		Vulkan::Vulkan
		glm::glm
)

target_compile_options(${MODULE_NAME} PRIVATE
		$<$<CONFIG:Debug>:-DDEBUG -D_DEBUG>
)

if(APPLE)
    target_compile_definitions(${MODULE_NAME} PRIVATE VK_USE_PLATFORM_MACOS_MVK)
endif()
