#include "GlenEditor/Editor/Editor.h"
#include "GlenEditor/WindowManager/WindowManager.h"
#include <spdlog/spdlog.h>

OPEN_GLEN_NAMESPACE
    Editor::Editor(Engine& engine) : m_engine(engine)
    {
        m_windowManager = new WindowManager();
    }

    Editor::~Editor()
    {
    }

    void Editor::initialize()
    {
        spdlog::info("Initializing Editor");
        m_windowManager->initialize();
    }

    void Editor::run()
    {
    }

CLOSE_GLEN_NAMESPACE
