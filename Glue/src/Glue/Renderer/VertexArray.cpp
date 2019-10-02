#include "gluepch.h"
#include "VertexArray.h"
#include "Renderer.h"

#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Glue
{
	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetRendererAPI())
		{
		case RendererAPI::API::None: { GLUE_CORE_ASSERT(false, "RendererAPI::None is not supported!\n"); return nullptr;  }
		case RendererAPI::API::OpenGL: { return new OpenGLVertexArray(); }
		case RendererAPI::API::DirectX: { return nullptr;  }
		}
	}
}