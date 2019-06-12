#pragma once

#include "Glue/Renderer/RenderingContext.h"

struct GLFWwindow;

namespace Glue
{
	class OpenGLContext : public RenderingContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;

	private:
		GLFWwindow* m_windowHandle;
		std::string m_adapterName;
	};
}