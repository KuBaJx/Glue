#include <Glue.h>

class Sandbox : public Glue::Application
{
public:
	Sandbox() {}
	~Sandbox() {}
};

Glue::Application* Glue::CreateApplication()
{
	return new Sandbox();
}
