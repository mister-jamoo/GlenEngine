#include "GlenEditor/WindowManager/WindowManager.h"
#include <iostream>

OPEN_GLEN_NAMESPACE

    WindowManager::WindowManager()
    {
    }

    void WindowManager::initialize()
    {
        std::cout << "Window Manager initialized" << std::endl;
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }

    void WindowManager::initWindow()
    {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);

        while (!glfwWindowShouldClose(window))
        {
            glfwPollEvents();
        }
    }

    void WindowManager::initVulkan()
    {
    }

    void WindowManager::mainLoop()
    {
    }

    void WindowManager::cleanup()
    {
        glfwDestroyWindow(window);

        glfwTerminate();
    }

CLOSE_GLEN_NAMESPACE
