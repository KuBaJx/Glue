#include "gluepch.h"
#include "Buffer.h"

#include "Renderer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"
#include "Platform/OpenGL/OpenGLShader.h"


namespace Glue
{
	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
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
				return new OpenGLVertexBuffer(vertices, size);
			}

			GLUE_CORE_ASSERT(false, "Unknown RendererAPI!");
			return nullptr;
		}
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
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
				return new OpenGLIndexBuffer(indices, size);
			}
		}

		GLUE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}