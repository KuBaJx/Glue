#pragma once

#ifdef GLUE_PLATFORM_WINDOWS
	extern Glue::Application* Glue::CreateApplication();

	int main(int argc, char* argv[])
	{
		printf("[GLUE ENGINE v0.1a]\n");
		auto app = Glue::CreateApplication();
		app->Run();
		delete app;
	}
#endif