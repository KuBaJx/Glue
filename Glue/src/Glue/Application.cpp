#include "gluepch.h"
#include "Application.h"

namespace Glue {


#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);

		// If event matches WindowCloseEvent (Checking template) then we'll call OnWindowClosed function
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClosed));

		GLUE_CORE_TRACE("{0}", e.ToString());
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();

		}
	}

	bool Application::OnWindowClosed(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}
