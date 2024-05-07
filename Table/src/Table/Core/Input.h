#pragma once

#include <glm/glm.hpp>
#include "Table/Core/KeyCodes.h"
#include "Table/Core/MouseCodes.h"

namespace Table
{
	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
