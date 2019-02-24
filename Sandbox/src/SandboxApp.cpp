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
		if (Glue::Input::IsKeyPressed(GLUE_KEY_TAB))
		{
			GLUE_INFO("Tab was pressed!");
		}
	}

	void OnEvent(Glue::Event& e) override
	{
		GLUE_TRACE("{0}", e);
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
