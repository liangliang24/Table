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
		if (Table::Input::IsKeyPressed(TABLE_KEY_TAB))
		{
			TABLE_TRACE("Tab key is pressed(poll)");
		}
	}

	void OnEvent(Table::Event& event) override
	{
		if (event.GetEventType() ==  Table::EventType::KeyPressed)
		{
			Table::KeyPressedEvent& e = (Table::KeyPressedEvent&)event;
			if (e.GetKeyCode() == TABLE_KEY_TAB)
			{
				TABLE_TRACE("Tab key is pressed(event)");
			}
			TABLE_TRACE("{0}", e.GetKeyCode());
		}
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