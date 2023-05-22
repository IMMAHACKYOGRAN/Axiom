#pragma once

#include "Axiom/Layer.h"
#include "Axiom/Events/ApplicationEvent.h"
#include "Axiom/Events/KeyEvent.h"
#include "Axiom/Events/MouseEvent.h"

namespace Axiom {

	class  ImGuiLayer : public Layer
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
		float m_Time = 0.0f;
	};

}