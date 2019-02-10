#pragma once

#include "Glue/Input.h"

namespace Glue
{
	class WindowsInput : public Input
	{
	public:
		bool IsKeyPressedImpl(int keycode) override;
		bool IsMouseButtonPressedImpl(int button) override;
		std::tuple<float, float> GetMouseXYImpl() override;
		
		float GetMouseXImpl() override;
		float GetMouseYImpl() override;


	};
}