#include "gluepch.h"
#include "Application.h"

#include <glad/glad.h>

namespace Glue {


#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		GLUE_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);

		// If event matches WindowCloseEvent (Checking template) then we'll call OnWindowClosed function
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClosed));

		GLUE_CORE_TRACE("{0}", e.ToString());

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
			{
				break;
			}
		}
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();

			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}

		}
	}

	bool Application::OnWindowClosed(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}
