#pragma once
#include "Core.h"

namespace Glue {

	class GLUE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined by Client //
	Application* CreateApplication();
}


