#pragma once

#include "Axiom/Core.h"
#include "Axiom/Events/Event.h"

namespace Axiom {

	class AXIOM_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& e) {}

		inline const std::string& GetName() const { return m_DebugName; };

	protected:
		std::string m_DebugName;
	};

}