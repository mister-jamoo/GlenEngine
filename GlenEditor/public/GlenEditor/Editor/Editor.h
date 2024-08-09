#pragma once
#include "GlenEngine/Engine/Engine.h"
#include "GlenEngine/GlenEngineAPI.h"


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
