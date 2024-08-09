#pragma once
#include "GlenEngine/Engine/Engine.h"
#include "GlenEngine/GlenEngineAPI.h"

OPEN_GLEN_NAMESPACE

    // Forward Declaration.
    class WindowManager;

    class Editor
    {
    public:
        Editor(glen::Engine&);
        ~Editor();

        void initialize();
        void run();

    private:
        glen::Engine& m_engine;
        glen::WindowManager* m_windowManager;
    };

CLOSE_GLEN_NAMESPACE
