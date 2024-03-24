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
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;

	private:
		float m_Time = 0.0f;

		bool OnMouseButtonPressEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleaseEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);
	};

}

