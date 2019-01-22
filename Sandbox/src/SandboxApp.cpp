#include <Glue.h>

class ExampleLayer : public Glue::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		GLUE_INFO("ExampleLayer::Update");
	}

	void OnEvent(Glue::Event& e) override
	{
		GLUE_TRACE("{0}", e.ToString());
	}
};

class Sandbox : public Glue::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Glue::ImGuiLayer());
	}

	~Sandbox() {}
};

Glue::Application* Glue::CreateApplication()
{
	return new Sandbox();
}
