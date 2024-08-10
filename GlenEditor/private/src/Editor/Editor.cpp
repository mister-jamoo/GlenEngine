#include "GlenEditor/Editor/Editor.h"
#include "GlenEditor/WindowManager/WindowManager.h"


OPEN_GLEN_NAMESPACE
    Editor::Editor(glen::Engine& engine) : m_engine(engine)
    {
    }

    Editor::~Editor()
    {
    }

    void Editor::initialize()
    {
        m_windowManager->initilize();
    }

    void Editor::run()
    {
    }

CLOSE_GLEN_NAMESPACE
