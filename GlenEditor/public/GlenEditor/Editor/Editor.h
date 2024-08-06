#pragma once
#include "GlenEngine/Engine/Engine.h"
#include "GlenEngine/GlenEngineAPI.h"
#include <imgui.h>
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "GLFW/glfw3.h"
#include <iostream>

OPEN_GLEN_NAMESPACE

class Editor {

public:
  Editor(glen::Engine&);
  ~Editor();

  void Initialize();
  void Run();

private:
	glen::Engine& m_engine; 
  // Private members
};

CLOSE_GLEN_NAMESPACE
