#include "gluepch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Glue
{
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}