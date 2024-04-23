#pragma once


#include "Table/Core/Layer.h"

#include "Table/Events/ApplicationEvent.h"
#include "Table/Events/KeyEvent.h"
#include "Table/Events/MouseEvent.h"

namespace Table
{
	class ImGuiLayer : public Layer
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

