#include <Table.h>
#include <Table/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Table
{
	class TableEditor : public Application
	{
	public:
		TableEditor(const ApplicationSpecification& spec)
			: Application(spec)
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
		ApplicationSpecification spec;
		spec.Name = "Table-Editor";
		spec.CommandLineArgs = args;

		return new TableEditor(spec);
	}
}