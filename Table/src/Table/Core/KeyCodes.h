#pragma once

namespace Table
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define TABLE_KEY_SPACE           ::Table::Key::Space
#define TABLE_KEY_APOSTROPHE      ::Table::Key::Apostrophe    /* ' */
#define TABLE_KEY_COMMA           ::Table::Key::Comma         /* , */
#define TABLE_KEY_MINUS           ::Table::Key::Minus         /* - */
#define TABLE_KEY_PERIOD          ::Table::Key::Period        /* . */
#define TABLE_KEY_SLASH           ::Table::Key::Slash         /* / */
#define TABLE_KEY_0               ::Table::Key::D0
#define TABLE_KEY_1               ::Table::Key::D1
#define TABLE_KEY_2               ::Table::Key::D2
#define TABLE_KEY_3               ::Table::Key::D3
#define TABLE_KEY_4               ::Table::Key::D4
#define TABLE_KEY_5               ::Table::Key::D5
#define TABLE_KEY_6               ::Table::Key::D6
#define TABLE_KEY_7               ::Table::Key::D7
#define TABLE_KEY_8               ::Table::Key::D8
#define TABLE_KEY_9               ::Table::Key::D9
#define TABLE_KEY_SEMICOLON       ::Table::Key::Semicolon     /* ; */
#define TABLE_KEY_EQUAL           ::Table::Key::Equal         /* = */
#define TABLE_KEY_A               ::Table::Key::A
#define TABLE_KEY_B               ::Table::Key::B
#define TABLE_KEY_C               ::Table::Key::C
#define TABLE_KEY_D               ::Table::Key::D
#define TABLE_KEY_E               ::Table::Key::E
#define TABLE_KEY_F               ::Table::Key::F
#define TABLE_KEY_G               ::Table::Key::G
#define TABLE_KEY_H               ::Table::Key::H
#define TABLE_KEY_I               ::Table::Key::I
#define TABLE_KEY_J               ::Table::Key::J
#define TABLE_KEY_K               ::Table::Key::K
#define TABLE_KEY_L               ::Table::Key::L
#define TABLE_KEY_M               ::Table::Key::M
#define TABLE_KEY_N               ::Table::Key::N
#define TABLE_KEY_O               ::Table::Key::O
#define TABLE_KEY_P               ::Table::Key::P
#define TABLE_KEY_Q               ::Table::Key::Q
#define TABLE_KEY_R               ::Table::Key::R
#define TABLE_KEY_S               ::Table::Key::S
#define TABLE_KEY_T               ::Table::Key::T
#define TABLE_KEY_U               ::Table::Key::U
#define TABLE_KEY_V               ::Table::Key::V
#define TABLE_KEY_W               ::Table::Key::W
#define TABLE_KEY_X               ::Table::Key::X
#define TABLE_KEY_Y               ::Table::Key::Y
#define TABLE_KEY_Z               ::Table::Key::Z
#define TABLE_KEY_LEFT_BRACKET    ::Table::Key::LeftBracket   /* [ */
#define TABLE_KEY_BACKSLASH       ::Table::Key::Backslash     /* \ */
#define TABLE_KEY_RIGHT_BRACKET   ::Table::Key::RightBracket  /* ] */
#define TABLE_KEY_GRAVE_ACCENT    ::Table::Key::GraveAccent   /* ` */
#define TABLE_KEY_WORLD_1         ::Table::Key::World1        /* non-US #1 */
#define TABLE_KEY_WORLD_2         ::Table::Key::World2        /* non-US #2 */

/* Function keys */
#define TABLE_KEY_ESCAPE          ::Table::Key::Escape
#define TABLE_KEY_ENTER           ::Table::Key::Enter
#define TABLE_KEY_TAB             ::Table::Key::Tab
#define TABLE_KEY_BACKSPACE       ::Table::Key::Backspace
#define TABLE_KEY_INSERT          ::Table::Key::Insert
#define TABLE_KEY_DELETE          ::Table::Key::Delete
#define TABLE_KEY_RIGHT           ::Table::Key::Right
#define TABLE_KEY_LEFT            ::Table::Key::Left
#define TABLE_KEY_DOWN            ::Table::Key::Down
#define TABLE_KEY_UP              ::Table::Key::Up
#define TABLE_KEY_PAGE_UP         ::Table::Key::PageUp
#define TABLE_KEY_PAGE_DOWN       ::Table::Key::PageDown
#define TABLE_KEY_HOME            ::Table::Key::Home
#define TABLE_KEY_END             ::Table::Key::End
#define TABLE_KEY_CAPS_LOCK       ::Table::Key::CapsLock
#define TABLE_KEY_SCROLL_LOCK     ::Table::Key::ScrollLock
#define TABLE_KEY_NUM_LOCK        ::Table::Key::NumLock
#define TABLE_KEY_PRINT_SCREEN    ::Table::Key::PrintScreen
#define TABLE_KEY_PAUSE           ::Table::Key::Pause
#define TABLE_KEY_F1              ::Table::Key::F1
#define TABLE_KEY_F2              ::Table::Key::F2
#define TABLE_KEY_F3              ::Table::Key::F3
#define TABLE_KEY_F4              ::Table::Key::F4
#define TABLE_KEY_F5              ::Table::Key::F5
#define TABLE_KEY_F6              ::Table::Key::F6
#define TABLE_KEY_F7              ::Table::Key::F7
#define TABLE_KEY_F8              ::Table::Key::F8
#define TABLE_KEY_F9              ::Table::Key::F9
#define TABLE_KEY_F10             ::Table::Key::F10
#define TABLE_KEY_F11             ::Table::Key::F11
#define TABLE_KEY_F12             ::Table::Key::F12
#define TABLE_KEY_F13             ::Table::Key::F13
#define TABLE_KEY_F14             ::Table::Key::F14
#define TABLE_KEY_F15             ::Table::Key::F15
#define TABLE_KEY_F16             ::Table::Key::F16
#define TABLE_KEY_F17             ::Table::Key::F17
#define TABLE_KEY_F18             ::Table::Key::F18
#define TABLE_KEY_F19             ::Table::Key::F19
#define TABLE_KEY_F20             ::Table::Key::F20
#define TABLE_KEY_F21             ::Table::Key::F21
#define TABLE_KEY_F22             ::Table::Key::F22
#define TABLE_KEY_F23             ::Table::Key::F23
#define TABLE_KEY_F24             ::Table::Key::F24
#define TABLE_KEY_F25             ::Table::Key::F25

/* Keypad */
#define TABLE_KEY_KP_0            ::Table::Key::KP0
#define TABLE_KEY_KP_1            ::Table::Key::KP1
#define TABLE_KEY_KP_2            ::Table::Key::KP2
#define TABLE_KEY_KP_3            ::Table::Key::KP3
#define TABLE_KEY_KP_4            ::Table::Key::KP4
#define TABLE_KEY_KP_5            ::Table::Key::KP5
#define TABLE_KEY_KP_6            ::Table::Key::KP6
#define TABLE_KEY_KP_7            ::Table::Key::KP7
#define TABLE_KEY_KP_8            ::Table::Key::KP8
#define TABLE_KEY_KP_9            ::Table::Key::KP9
#define TABLE_KEY_KP_DECIMAL      ::Table::Key::KPDecimal
#define TABLE_KEY_KP_DIVIDE       ::Table::Key::KPDivide
#define TABLE_KEY_KP_MULTIPLY     ::Table::Key::KPMultiply
#define TABLE_KEY_KP_SUBTRACT     ::Table::Key::KPSubtract
#define TABLE_KEY_KP_ADD          ::Table::Key::KPAdd
#define TABLE_KEY_KP_ENTER        ::Table::Key::KPEnter
#define TABLE_KEY_KP_EQUAL        ::Table::Key::KPEqual

#define TABLE_KEY_LEFT_SHIFT      ::Table::Key::LeftShift
#define TABLE_KEY_LEFT_CONTROL    ::Table::Key::LeftControl
#define TABLE_KEY_LEFT_ALT        ::Table::Key::LeftAlt
#define TABLE_KEY_LEFT_SUPER      ::Table::Key::LeftSuper
#define TABLE_KEY_RIGHT_SHIFT     ::Table::Key::RightShift
#define TABLE_KEY_RIGHT_CONTROL   ::Table::Key::RightControl
#define TABLE_KEY_RIGHT_ALT       ::Table::Key::RightAlt
#define TABLE_KEY_RIGHT_SUPER     ::Table::Key::RightSuper
#define TABLE_KEY_MENU            ::Table::Key::Menu