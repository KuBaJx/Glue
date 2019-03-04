#pragma once

#include "Glue/Layer.h"

#include "Glue/Events/ApplicationEvent.h"
#include "Glue/Events/KeyEvent.h"
#include "Glue/Events/MouseEvent.h"


namespace Glue
{
	class GLUE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0;
	};
}