#pragma once

#ifdef GLUE_PLATFORM_WINDOWS
	extern Glue::Application* Glue::CreateApplication();

	int main(int argc, char* argv[])
	{
		Glue::Log::Init();
		GLUE_CORE_WARN("Log Initialized!");
		GLUE_INFO("Hello from client!");

		auto app = Glue::CreateApplication();
		app->Run();
		delete app;
	}
#endif