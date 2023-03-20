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
	}
};

class Sandbox : public Axiom::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Axiom::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Axiom::Application* Axiom::CreateApplicaiton()
{
	return new Sandbox();
}