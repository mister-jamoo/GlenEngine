#pragma once
#include "GlenEngine/Engine/Engine.h"
#include "GlenEngine/GlenEngineAPI.h"

OPEN_GLEN_NAMESPACE

    // Forward Declaration.
    class WindowManager;

    class Editor
    {
    public:
        Editor(Engine&);
        ~Editor();

        void initialize();
        void run();

    private:
        Engine& m_engine;
        WindowManager* m_windowManager;
    };

CLOSE_GLEN_NAMESPACE
