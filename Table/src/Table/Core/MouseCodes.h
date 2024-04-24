#pragma once
namespace Table
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define TABLE_MOUSE_BUTTON_0      ::Table::Mouse::Button0
#define TABLE_MOUSE_BUTTON_1      ::Table::Mouse::Button1
#define TABLE_MOUSE_BUTTON_2      ::Table::Mouse::Button2
#define TABLE_MOUSE_BUTTON_3      ::Table::Mouse::Button3
#define TABLE_MOUSE_BUTTON_4      ::Table::Mouse::Button4
#define TABLE_MOUSE_BUTTON_5      ::Table::Mouse::Button5
#define TABLE_MOUSE_BUTTON_6      ::Table::Mouse::Button6
#define TABLE_MOUSE_BUTTON_7      ::Table::Mouse::Button7
#define TABLE_MOUSE_BUTTON_LAST   ::Table::Mouse::ButtonLast
#define TABLE_MOUSE_BUTTON_LEFT   ::Table::Mouse::ButtonLeft
#define TABLE_MOUSE_BUTTON_RIGHT  ::Table::Mouse::ButtonRight
#define TABLE_MOUSE_BUTTON_MIDDLE ::Table::Mouse::ButtonMiddle