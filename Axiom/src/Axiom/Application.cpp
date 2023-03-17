#include "axpch.h"
#include "Application.h"

#include "Axiom/Events/ApplicationEvent.h"

namespace Axiom {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}

}