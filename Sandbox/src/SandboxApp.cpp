#include <Glue.h>

#include "imgui.h"

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


	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test window");
		ImGui::Text("This is simple text created by client not Glue!");
		ImGui::End();
	}
};

class Sandbox : public Glue::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox() {}
};

Glue::Application* Glue::CreateApplication()
{
	return new Sandbox();
}
