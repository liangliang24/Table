#include <Table.h>

class Card : public Table::Application
{
public:
	Card()
	{

	}

	~Card()
	{

	}

};

Table::Application* Table::CreateApplication()
{
	return new Card();
}