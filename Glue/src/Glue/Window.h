#pragma once

#include "gluepch.h"

#include "Core.h"
#include "Events/Event.h"


namespace Glue
{
	struct WindowProperties
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProperties(const std::string& title = "GlueEngine", unsigned int width = 1280, unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		}

	};


	class Window
	{
	public:
		typedef std::function<void(Event&)> EventCallbackFn;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual void OnResize(int x, int y) = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attribs
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProperties& props = WindowProperties());

	};
}