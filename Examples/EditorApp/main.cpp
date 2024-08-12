#include <exception>
#include <iostream>

#include <GlenEditor/Editor/Editor.h>
#include <GlenEngine/Engine/Engine.h>

int main(){

	glen::Engine engine;
	glen::Editor editor(engine);

	try
	{
	editor.initialize();
	} catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;

}
