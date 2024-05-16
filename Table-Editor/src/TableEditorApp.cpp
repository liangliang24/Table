#include <Table.h>
#include <Table/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Table
{
	class TableEditor : public Application
	{
	public:
		TableEditor(ApplicationCommandLineArgs args)
			: Application("TableEditor", args)
		{
			//PushLayer(new ExampleLayer());
			PushLayer(new EditorLayer());
		}

		~TableEditor()
		{

		}

	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new TableEditor(args);
	}
}