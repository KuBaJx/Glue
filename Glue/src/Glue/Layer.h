#pragma once

#include "Glue/Core.h"
#include "Glue/Events/Event.h"
#include "Core/Timestep.h"

namespace Glue
{
	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep deltaTime) {}
		virtual void OnImGuiRender(Timestep deltaTime) {}
		virtual void OnEvent(Event& e) {}

		inline const std::string& GetName() const { return m_DebugName; };

	protected:
		std::string m_DebugName;
	};
}
