#pragma once
#include <GlenEngine/GlenEngineAPI.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_vulkan.h"

OPEN_GLEN_NAMESPACE

    class WindowManager
    {
    public:
        WindowManager() = default;
        ~WindowManager() = default;

        void initilize();
    };

CLOSE_GLEN_NAMESPACE
