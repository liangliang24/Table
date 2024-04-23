#include <Table.h>
#include <Table/Core/EntryPoint.h>

#include "Card2D.h"

class Card : public Table::Application
{
public:
	Card()
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new Card2D());
	}

	~Card()
	{

	}

};

Table::Application* Table::CreateApplication()
{
	return new Card();
}