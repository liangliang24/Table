#pragma once

#include "Table/Core/Input.h"

namespace Table
{
	class WindowsInput : public Input
	{
	protected:
		bool IsKeyPressedImpl(int keycode) override;


		bool IsMouseButtonPressedImpl(int button) override;


		std::pair<float, float> GetMousePositionImpl() override;


		float GetMouseXImpl() override;


		float GetMouseYImpl() override;

	};

}

