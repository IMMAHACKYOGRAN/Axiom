#pragma once

#include "Axiom/Layer.h"
#include "Axiom/Events/ApplicationEvent.h"
#include "Axiom/Events/KeyEvent.h"
#include "Axiom/Events/MouseEvent.h"

namespace Axiom {

	class AXIOM_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& e);
	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMoveEvent(MouseMovedEvent& e);
		bool OnMouseScrollEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResized(WindowResizeEvent& e);
	private:
		float m_Time = 0.0f;
	};

}