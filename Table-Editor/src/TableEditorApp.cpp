#include <Table.h>
#include <Table/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Table
{
	class TableEditor : public Application
	{
	public:
		TableEditor()
		{
			//PushLayer(new ExampleLayer());
			PushLayer(new EditorLayer());
		}

		~TableEditor()
		{

		}

	};

	Application* CreateApplication()
	{
		return new TableEditor();
	}
}