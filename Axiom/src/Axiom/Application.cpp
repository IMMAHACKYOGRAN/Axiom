#include "Application.h"

#include "Axiom/Events/ApplicationEvent.h"
#include "Axiom/Log.h"

namespace Axiom {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		AX_TRACE(e);

		while (true);
	}

}