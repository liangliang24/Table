#pragma once
#include "Table/Core/Core.h"
#include "Table/Events/Event.h"
#include "Table/Core/TimeStep.h"


namespace Table{
	class Layer
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

