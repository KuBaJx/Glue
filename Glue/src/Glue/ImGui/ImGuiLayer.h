#pragma once

#include "Glue/Layer.h"

#include "Glue/Events/ApplicationEvent.h"
#include "Glue/Events/KeyEvent.h"
#include "Glue/Events/MouseEvent.h"

#include "Glue/Core/Timestep.h"

namespace Glue
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender(Timestep deltaTime) override;

		void Begin();
		void End();
	private:
		float m_Time = 0;
	};
}