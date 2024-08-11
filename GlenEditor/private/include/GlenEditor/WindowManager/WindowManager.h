#pragma once
#include <GlenEngine/GlenEngineAPI.h>
#include <vulkan/vulkan_core.h>
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"

OPEN_GLEN_NAMESPACE

    constexpr uint32_t WIDTH = 800;
    constexpr uint32_t HEIGHT = 600;

    class WindowManager
    {
    public:
        WindowManager();
        ~WindowManager();

        void initialize();

    private:
        //GLFW
        void initWindow();

        // Vulkan
        void initVulkan();
        void mainLoop();
        void cleanup();
    public:

    private:
        GLFWwindow* window;
    };;

CLOSE_GLEN_NAMESPACE
