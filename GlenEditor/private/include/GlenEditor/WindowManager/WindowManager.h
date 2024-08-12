#pragma once
#include <GlenEngine/GlenEngineAPI.h>
#include <vulkan/vulkan_core.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>

OPEN_GLEN_NAMESPACE

    const uint32_t WIDTH = 800;
    const uint32_t HEIGHT = 600;

    class WindowManager
    {
    public:
        WindowManager();
        ~WindowManager();

        void initialize();
        

    private:
        void initWindow();
        void initVulkan();
        void createInstance();
        void mainLoop();
        void cleanup();


    private:
        GLFWwindow* window = nullptr;
        VkInstance instance;
    };;

CLOSE_GLEN_NAMESPACE
