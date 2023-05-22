#pragma once

#include "Core.h"

#include "Window.h"
#include "Axiom/LayerStack.h"
#include "Axiom/Events/Event.h"
#include "Axiom/Events/ApplicationEvent.h"

#include"Axiom/Core/TimeStep.h"

#include "Axiom/ImGui/ImGuiLayer.h"

namespace Axiom {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	
	private:
		bool OnWindowClose(WindowCloseEvent& e);
	
	private:
		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplicaiton();

}