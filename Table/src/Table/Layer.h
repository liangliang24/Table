#pragma once
#include "Table/Core.h"
#include "Events/Event.h"
#include "Core/TimeStep.h"


namespace Table{
	class TABLE_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(TimeStep ts) {}
		virtual void OnEvent(Event& event){}
		virtual void OnImGuiRender() { }

		inline const std::string& GetName() const { return m_DebugName; }
	private:
		std::string m_DebugName;
	};
}

