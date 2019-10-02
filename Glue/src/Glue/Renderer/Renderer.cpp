#include "gluepch.h"
#include "Renderer.h"

namespace Glue
{
	Renderer::SceneData* Renderer::m_SceneData = new Renderer::SceneData;

	std::string Renderer::GetAPIName()
	{
		switch (GetRendererAPI())
		{
			case RendererAPI::API::None:
			{
				return "None";
			}
			case RendererAPI::API::OpenGL:
			{
				return "OpenGL";
			}
			case RendererAPI::API::DirectX:
			{
				return "Direct3D";
			}
		}
	}

	void Renderer::BeginScene(OrthographicCamera& camera)
	{
		m_SceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
	}

	void Renderer::EndScene()
	{
	}

	void Renderer::Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray)
	{
		shader->Bind();
		shader->SetUniformMat4("u_ViewProjection", m_SceneData->ViewProjectionMatrix);
		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
	}
}