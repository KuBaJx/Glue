#pragma once

#include "RenderCommand.h"

#include "Camera.h"
#include "Shader.h"

namespace Glue
{
	class Renderer
	{
	public:
		static void BeginScene(OrthographicCamera& camera);
		static void EndScene();

		static void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray);

		inline static RendererAPI::API GetRendererAPI() { return RendererAPI::GetAPI(); }
		static std::string GetAPIName();
	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static SceneData* m_SceneData;
	};
}