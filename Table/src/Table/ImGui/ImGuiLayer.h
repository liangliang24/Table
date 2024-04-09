#pragma once


#include "Table/Layer.h"

#include "Table/Events/ApplicationEvent.h"
#include "Table/Events/KeyEvent.h"
#include "Table/Events/MouseEvent.h"

namespace Table
{
	class TABLE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	};

}

