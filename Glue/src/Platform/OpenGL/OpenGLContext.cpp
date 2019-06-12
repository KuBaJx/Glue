#include "gluepch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Glue
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_windowHandle(windowHandle)
	{
		GLUE_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_windowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		GLUE_CORE_ASSERT(status, "Failed to intialize Glad!");

		m_adapterName.append((const char*)glGetString(GL_RENDERER));
		GLUE_CORE_INFO(m_adapterName);

	}

	void OpenGLContext::SwapBuffers()
	{	
		glfwSwapBuffers(m_windowHandle);
	}
}