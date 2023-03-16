#include <Axiom.h>

class Sandbox : public Axiom::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Axiom::Application* Axiom::CreateApplicaiton()
{
	return new Sandbox();
}