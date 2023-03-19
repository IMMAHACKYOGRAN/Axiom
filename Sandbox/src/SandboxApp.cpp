#include <Axiom.h>

class ExampleLayer : public Axiom::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{}

	void OnUpdate() override
	{
	}

	void OnEvent(Axiom::Event& e) override
	{
		AX_CORE_TRACE("{0}", e);
	}
};

class Sandbox : public Axiom::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Axiom::Application* Axiom::CreateApplicaiton()
{
	return new Sandbox();
}