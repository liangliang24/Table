#include <Table.h>

class ExampleLayer:public Table::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		TABLE_INFO("ExampleLayerUpdate");
	}

	void OnEvent(Table::Event& event) override
	{
		TABLE_TRACE("{0}", event);
	}
};

class Card : public Table::Application
{
public:
	Card()
	{
		PushLayer(new ExampleLayer());
		PushOverLay(new Table::ImGuiLayer());
	}

	~Card()
	{

	}

};

Table::Application* Table::CreateApplication()
{
	return new Card();
}