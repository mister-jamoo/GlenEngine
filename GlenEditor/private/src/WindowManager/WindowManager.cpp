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
        // Set up error callback
        glfwSetErrorCallback([](int error, const char* description)
        {
            std::cerr << "GLFW Error " << error << ": " << description << std::endl;
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


#ifdef DEBUG
        // Lets find out all the supported extensions.
        uint32_t extensionCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

        std::vector<VkExtensionProperties> extensions(extensionCount);
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

        std::cout << "Available Vulkan extensions:\n";
        for (const auto& extension : extensions)
        {
            std::cout << '\t' << extension.extensionName << '\n';
        }
        
        std::cout << "Required Vulkan extensions for GLFW:" << std::endl;
        for (int i = 0; i < glfwExtensionCount; i++)
        {
            std::cout << '\t' << "Required GLFW Vulkan extension: " << glfwExtensions[i] << std::endl;
        }
#endif

        createInfo.enabledExtensionCount = glfwExtensionCount; // Set the count of enabled extensions for OS.
        createInfo.ppEnabledExtensionNames = glfwExtensions; // Set the extension names.
        createInfo.enabledLayerCount = 0; // Global validation layers enabled.

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
