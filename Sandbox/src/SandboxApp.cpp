#include <Calavera.h>

class Sandbox : public Calavera::Application
{
	public :
		Sandbox()
		{

		}

		~Sandbox()
		{

		}
};

Calavera::Application* Calavera::CreateApplication()
{
	return new Sandbox();
}