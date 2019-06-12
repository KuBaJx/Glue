#pragma once

namespace Glue
{
	enum class RendererAPI
	{
		None = 0, OpenGL, DirectX
	};

	class Renderer
	{
	public:
		inline static RendererAPI GetRendererAPI() { return s_RendererAPI; }

	private:
		static RendererAPI s_RendererAPI;
	};
}