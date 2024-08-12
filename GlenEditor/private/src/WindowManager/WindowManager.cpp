#include "GlenEditor/WindowManager/WindowManager.h"
#include <iostream>

OPEN_GLEN_NAMESPACE
    WindowManager::WindowManager()
    {
    }

    WindowManager::~WindowManager()
    = default;

    void WindowManager::initialize()
    {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }

    void WindowManager::initWindow()
    {
        // Initialize GLFW window.
        spdlog::info("Initializing GLFW window");
#if DEBUG && defined(__APPLE__)
        spdlog::info("MacOS detected");
#endif
#if DEBUG && defined(_WIN32) || defined(_WIN64)
        spdlog::info("Windows detected");
#endif
#if DEBUG && defined(__linux__)
        spdlog::info("Linux detected");
#endif
        // Set up error callback
        glfwSetErrorCallback([](int error, const char* description)
        {
            spdlog::error("GLFW Error {}: {}", error, description);
        });

        if (!glfwInit())
        {
            throw std::runtime_error("Failed to initialize GLFW");
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
    }

    void WindowManager::initVulkan()
    {
        createInstance();
    }

    void WindowManager::createInstance()
    {
        // Create VkApplication information struct.
        VkApplicationInfo appInfo{}; // Create application information struct.
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO; // Set the struct type.
        appInfo.pApplicationName = "Hello Triangle"; // Set the application name.
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0); // Set the application version.
        appInfo.pEngineName = "No Engine"; // Set the Engine name.
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0); // Set the engine version.
        appInfo.apiVersion = VK_API_VERSION_1_0; // Set the api version.

        VkInstanceCreateInfo createInfo{}; // Create instance info struct.
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO; // Set the struct type.
        createInfo.pApplicationInfo = &appInfo; // Pass a reference to the app info struct we just created.

        // Pull out all of the extensions required by Vulkan.
        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;

        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
        
        // Add all the glfw extensions to the required extensions list.
        std::vector<const char*> requiredExtensions;
        for(uint32_t i = 0; i < glfwExtensionCount; i++) {
            requiredExtensions.emplace_back(glfwExtensions[i]);
        }
        
#if defined(__APPLE__) || defined(__MACH__)
        // Add the VK_KHR_portability_subset extension.
        requiredExtensions.emplace_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);
        // Set the flags for the instance creation. Using Bitwise OR to add the VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR flag.
        createInfo.flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
#endif
        // Set the count of enabled extensions and the extension names.
        createInfo.enabledExtensionCount = (uint32_t) requiredExtensions.size();
        createInfo.ppEnabledExtensionNames = requiredExtensions.data();

#ifdef DEBUG
        // Lets find out all the supported extensions.
        uint32_t extensionCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

        std::vector<VkExtensionProperties> extensions(extensionCount);
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

        std::string allExtensionsList;
        for (const auto& extension : extensions)
        {    
            allExtensionsList += "\n\t" + std::string(extension.extensionName);
        }
        
        spdlog::info("Available Vulkan Extensions: {}", allExtensionsList);
        
        std::string requiredExtensionsList; 
        for (int i = 0; i < requiredExtensions.size(); i++)
        {
            requiredExtensionsList += "\n\t" + std::string(requiredExtensions[i]);
        }
        spdlog::info("Required Vulkan Extensions: {}", requiredExtensionsList);
        
#endif
        if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to create instance!");
        }
    }

    void WindowManager::mainLoop()
    {
        while (!glfwWindowShouldClose(window))
        {
            glfwPollEvents();
        }
    }

    void WindowManager::cleanup()
    {
        vkDestroyInstance(instance, nullptr);
        glfwDestroyWindow(window);
        glfwTerminate();
    }

CLOSE_GLEN_NAMESPACE
