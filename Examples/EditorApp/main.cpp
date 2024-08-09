#include "GlenEditor/Editor/Editor.h"
#include "GlenEngine/Engine/Engine.h"

int main(){

	glen::Engine engine;
	glen::Editor editor(engine);

	editor.initialize();

}
