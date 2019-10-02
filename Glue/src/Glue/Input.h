#pragma once

#include "Glue/Core.h"

namespace Glue
{
	class Input
	{
	public:
		inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }

		inline static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }

		inline static std::tuple<float, float> GetMouseXY() { return s_Instance->GetMouseXYImpl(); }

		inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }
	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0; // Pure virtual - to be implemented per platform
		virtual bool IsMouseButtonPressedImpl(int button) = 0;

		virtual std::tuple<float, float> GetMouseXYImpl() = 0;
		
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;

	
	private:
		static Input* s_Instance;
	};
}