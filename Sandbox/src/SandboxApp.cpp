#include <Glue.h>

#include <array>

#include "imgui.h"

class DebugLayer : public Glue::Layer
{
public:
	DebugLayer()
		: Layer("DebugLayer"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f)
	{
		m_VertexArray.reset(Glue::VertexArray::Create());

		m_Colors = { 0.0f, 0.0f, 0.0f };
		
		float vertices[3 * 7] = {
		-0.5f, -0.5f, 0.0f, 1.0f, 0.2f, 0.8f, 1.0f,
		 0.5f, -0.5f, 0.0f, 0.8f, 0.8f, 0.8f, 1.0f,
		 0.0f,  0.5f, 0.0f, 0.3f, 0.7f, 0.2f, 1.0f
		};

		std::shared_ptr<Glue::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Glue::VertexBuffer::Create(vertices, sizeof(vertices)));
		Glue::BufferLayout layout = {
			{ Glue::ShaderDataType::Float3, "a_Position" },
			{ Glue::ShaderDataType::Float4, "a_Color" }
		};

		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		unsigned int indices[] = { 0, 1, 2 };
		std::shared_ptr<Glue::IndexBuffer> indexBuffer;
		indexBuffer.reset(Glue::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_Shader.reset(Glue::Shader::Create("shaders/shader.vs", "shaders/shader.fs"));
	}

	virtual void OnUpdate(Glue::Timestep deltaTime) override
	{
		m_MousePos = ImGui::GetIO().MousePos;
		
		glm::vec3 normalized = glm::normalize(glm::vec3(m_Colors.at(0), m_Colors.at(1), m_Colors.at(2)));
		// KeyPress handling
		if(Glue::Input::IsKeyPressed(GLUE_KEY_A))
		{
			m_CameraPosition.x -= m_CameraSpeed * deltaTime;
		}
		if(Glue::Input::IsKeyPressed(GLUE_KEY_D))
		{
			m_CameraPosition.x += m_CameraSpeed * deltaTime;
		}
		if(Glue::Input::IsKeyPressed(GLUE_KEY_W))
		{
			m_CameraPosition.y += m_CameraSpeed * deltaTime; 
		}
		if(Glue::Input::IsKeyPressed(GLUE_KEY_S))
		{
			m_CameraPosition.y -= m_CameraSpeed * deltaTime;
		}

		Glue::Application::Get().GetWindow().SetVSync(m_VSync);

		Glue::RenderCommand::SetClearColor(glm::vec4(0.1f, 0.2f, 0.2f, 1.0f));
		Glue::RenderCommand::Clear();
		
		m_Camera.SetPosition(m_CameraPosition);
		m_Shader->SetUniform4f("u_Color", normalized.x, normalized.y, normalized.z, 1.0f);
		
		Glue::Renderer::BeginScene(m_Camera);
		Glue::Renderer::Submit(m_Shader, m_VertexArray);
		Glue::Renderer::EndScene();

	}

	virtual void OnImGuiRender(Glue::Timestep deltaTime) override
	{
		ImGui::Begin("Debug Window");
		ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "Renderer API: %s", Glue::Renderer::GetAPIName().c_str());
		ImGui::Text("FPS: %i", static_cast<int>(1000 / deltaTime.GetMillis()));
		ImGui::Text("Last frame took %f s (%f ms)", deltaTime.GetSeconds(), deltaTime.GetMillis());
		ImGui::Text("Camera position X: %f Y: %f Z: %f", m_CameraPosition.x, m_CameraPosition.y, m_CameraPosition.z);\
		ImGui::SliderFloat("Camera speed", &m_CameraSpeed, 0.0f, 50.0f);
		ImGui::Text("Mouse position X: %f Y: %f", m_MousePos.x, m_MousePos.y);
		ImGui::Checkbox("V-Sync", &m_VSync);
		ImGui::NewLine();
		ImGui::ColorEdit3("Triangle color", m_Colors.data());
		ImGui::End();
	}

	void OnEvent(Glue::Event& e) override 
	{
		Glue::EventDispatcher dispatcher(e);
		dispatcher.Dispatch<Glue::KeyPressedEvent>(GLUE_BIND_EVENT_FN(DebugLayer::OnKeyPressedEvent));
	}

	bool OnKeyPressedEvent(Glue::KeyPressedEvent event)
	{
		return false;
	}

private:
	// General
	bool m_VSync = false;
	ImVec2 m_MousePos;

	std::array<float, 3> m_Colors;
	
	std::shared_ptr<Glue::VertexArray> m_VertexArray;
	std::shared_ptr<Glue::Shader> m_Shader;
	// Camera
	Glue::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition = { 0.0f, 0.0f, 0.0f };
	float m_CameraSpeed = 1.0f;
	float m_CameraRotation = 0.0f;
	// Testing
};


class Sandbox : public Glue::Application
{
public:
	Sandbox()
	{
		PushLayer(new DebugLayer());
	}

	~Sandbox() {}
};

Glue::Application* Glue::CreateApplication()
{
	return new Sandbox();
}
