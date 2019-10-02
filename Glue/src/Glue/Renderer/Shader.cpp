#include "gluepch.h"
#include "Shader.h"

#include "Renderer.h"

#include "Platform/OpenGL/OpenGLShader.h"

namespace Glue
{
	Shader* Shader::Create(const char* vertexPath, const char* fragmentPath)
	{
		switch (Renderer::GetRendererAPI())
		{
		case RendererAPI::API::None:
		{
			GLUE_CORE_ASSERT(false, "RendererAPI::None is not supported!");
			return nullptr;
		}
		case RendererAPI::API::OpenGL:
		{
			return new OpenGLShader(vertexPath, fragmentPath);
		}
		}
	}
}