#pragma once

#include "Glue/Window.h"
#include "Glue/Renderer/RenderingContext.h"

#include <GLFW/glfw3.h>

namespace Glue
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProperties& props);
		virtual ~WindowsWindow();

		virtual void OnUpdate() override;

		virtual inline unsigned int GetWidth() const override { return m_Data.Width; }
		virtual inline unsigned int GetHeight() const override { return m_Data.Height; }

		// Window attribs
		virtual inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override;

		inline void* GetNativeWindow() const override { return m_Window; };

	private:
		virtual void Init(const WindowProperties& props);
		virtual void Shutdown();
	private:
		 GLFWwindow* m_Window;
		 RenderingContext* m_Context;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}