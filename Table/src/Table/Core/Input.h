#pragma once

#include "Table/Core/Core.h"
#include "Table/Core/KeyCodes.h"
#include "Table/Core/MouseCodes.h"

namespace Table
{
	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
