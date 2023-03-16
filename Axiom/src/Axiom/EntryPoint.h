#pragma once

#ifdef AX_PLATFORM_WINDOWS

extern Axiom::Application* Axiom::CreateApplicaiton();

int main(int argc, char** argv)
{
	Axiom::Log::Init();
	AX_CORE_INFO("Logger Init");

	auto app = Axiom::CreateApplicaiton();
	app->Run();
	delete app;
}

#endif