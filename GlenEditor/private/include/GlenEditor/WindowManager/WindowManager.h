#pragma once
#include <GlenEngine/GlenEngineAPI.h>
#include <vulkan/vulkan_core.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

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
        void mainLoop();
        void cleanup();

        // Vulkan methods:
        void createInstance();
        VkApplicationInfo createVulkanAppInfo();
        void logRequiredExtensions(std::vector<const char*> requiredExtensions);
        void logAvailableExtensions();
        bool checkValidationSupport();
        bool checkValidationLayerSupport();

    private:
        GLFWwindow* window = nullptr;
        VkInstance instance;

        const std::vector<const char*> validationLayers = {"VK_LAYER_KHRONOS_validation"};

#ifdef NDEBUG
        const bool enableValidationLayers = false;
#else
        const bool enableValidationLayers = true;
#endif
    };

CLOSE_GLEN_NAMESPACE
