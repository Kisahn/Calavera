#pragma once

namespace Calavera
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

		A = 81,
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
		Q = 65,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 90,
		X = 88,
		Y = 89,
		Z = 87,

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
#define CV_KEY_SPACE           ::Calavera::Key::Space
#define CV_KEY_APOSTROPHE      ::Calavera::Key::Apostrophe    /* ' */
#define CV_KEY_COMMA           ::Calavera::Key::Comma         /* , */
#define CV_KEY_MINUS           ::Calavera::Key::Minus         /* - */
#define CV_KEY_PERIOD          ::Calavera::Key::Period        /* . */
#define CV_KEY_SLASH           ::Calavera::Key::Slash         /* / */
#define CV_KEY_0               ::Calavera::Key::D0
#define CV_KEY_1               ::Calavera::Key::D1
#define CV_KEY_2               ::Calavera::Key::D2
#define CV_KEY_3               ::Calavera::Key::D3
#define CV_KEY_4               ::Calavera::Key::D4
#define CV_KEY_5               ::Calavera::Key::D5
#define CV_KEY_6               ::Calavera::Key::D6
#define CV_KEY_7               ::Calavera::Key::D7
#define CV_KEY_8               ::Calavera::Key::D8
#define CV_KEY_9               ::Calavera::Key::D9
#define CV_KEY_SEMICOLON       ::Calavera::Key::Semicolon     /* ; */
#define CV_KEY_EQUAL           ::Calavera::Key::Equal         /* = */
#define CV_KEY_A               ::Calavera::Key::A
#define CV_KEY_B               ::Calavera::Key::B
#define CV_KEY_C               ::Calavera::Key::C
#define CV_KEY_D               ::Calavera::Key::D
#define CV_KEY_E               ::Calavera::Key::E
#define CV_KEY_F               ::Calavera::Key::F
#define CV_KEY_G               ::Calavera::Key::G
#define CV_KEY_H               ::Calavera::Key::H
#define CV_KEY_I               ::Calavera::Key::I
#define CV_KEY_J               ::Calavera::Key::J
#define CV_KEY_K               ::Calavera::Key::K
#define CV_KEY_L               ::Calavera::Key::L
#define CV_KEY_M               ::Calavera::Key::M
#define CV_KEY_N               ::Calavera::Key::N
#define CV_KEY_O               ::Calavera::Key::O
#define CV_KEY_P               ::Calavera::Key::P
#define CV_KEY_Q               ::Calavera::Key::Q
#define CV_KEY_R               ::Calavera::Key::R
#define CV_KEY_S               ::Calavera::Key::S
#define CV_KEY_T               ::Calavera::Key::T
#define CV_KEY_U               ::Calavera::Key::U
#define CV_KEY_V               ::Calavera::Key::V
#define CV_KEY_W               ::Calavera::Key::W
#define CV_KEY_X               ::Calavera::Key::X
#define CV_KEY_Y               ::Calavera::Key::Y
#define CV_KEY_Z               ::Calavera::Key::Z
#define CV_KEY_LEFT_BRACKET    ::Calavera::Key::LeftBracket   /* [ */
#define CV_KEY_BACKSLASH       ::Calavera::Key::Backslash     /* \ */
#define CV_KEY_RIGHT_BRACKET   ::Calavera::Key::RightBracket  /* ] */
#define CV_KEY_GRAVE_ACCENT    ::Calavera::Key::GraveAccent   /* ` */
#define CV_KEY_WORLD_1         ::Calavera::Key::World1        /* non-US #1 */
#define CV_KEY_WORLD_2         ::Calavera::Key::World2        /* non-US #2 */

/* Function keys */
#define CV_KEY_ESCAPE          ::Calavera::Key::Escape
#define CV_KEY_ENTER           ::Calavera::Key::Enter
#define CV_KEY_TAB             ::Calavera::Key::Tab
#define CV_KEY_BACKSPACE       ::Calavera::Key::Backspace
#define CV_KEY_INSERT          ::Calavera::Key::Insert
#define CV_KEY_DELETE          ::Calavera::Key::Delete
#define CV_KEY_RIGHT           ::Calavera::Key::Right
#define CV_KEY_LEFT            ::Calavera::Key::Left
#define CV_KEY_DOWN            ::Calavera::Key::Down
#define CV_KEY_UP              ::Calavera::Key::Up
#define CV_KEY_PAGE_UP         ::Calavera::Key::PageUp
#define CV_KEY_PAGE_DOWN       ::Calavera::Key::PageDown
#define CV_KEY_HOME            ::Calavera::Key::Home
#define CV_KEY_END             ::Calavera::Key::End
#define CV_KEY_CAPS_LOCK       ::Calavera::Key::CapsLock
#define CV_KEY_SCROLL_LOCK     ::Calavera::Key::ScrollLock
#define CV_KEY_NUM_LOCK        ::Calavera::Key::NumLock
#define CV_KEY_PRINT_SCREEN    ::Calavera::Key::PrintScreen
#define CV_KEY_PAUSE           ::Calavera::Key::Pause
#define CV_KEY_F1              ::Calavera::Key::F1
#define CV_KEY_F2              ::Calavera::Key::F2
#define CV_KEY_F3              ::Calavera::Key::F3
#define CV_KEY_F4              ::Calavera::Key::F4
#define CV_KEY_F5              ::Calavera::Key::F5
#define CV_KEY_F6              ::Calavera::Key::F6
#define CV_KEY_F7              ::Calavera::Key::F7
#define CV_KEY_F8              ::Calavera::Key::F8
#define CV_KEY_F9              ::Calavera::Key::F9
#define CV_KEY_F10             ::Calavera::Key::F10
#define CV_KEY_F11             ::Calavera::Key::F11
#define CV_KEY_F12             ::Calavera::Key::F12
#define CV_KEY_F13             ::Calavera::Key::F13
#define CV_KEY_F14             ::Calavera::Key::F14
#define CV_KEY_F15             ::Calavera::Key::F15
#define CV_KEY_F16             ::Calavera::Key::F16
#define CV_KEY_F17             ::Calavera::Key::F17
#define CV_KEY_F18             ::Calavera::Key::F18
#define CV_KEY_F19             ::Calavera::Key::F19
#define CV_KEY_F20             ::Calavera::Key::F20
#define CV_KEY_F21             ::Calavera::Key::F21
#define CV_KEY_F22             ::Calavera::Key::F22
#define CV_KEY_F23             ::Calavera::Key::F23
#define CV_KEY_F24             ::Calavera::Key::F24
#define CV_KEY_F25             ::Calavera::Key::F25

/* Keypad */
#define CV_KEY_KP_0            ::Calavera::Key::KP0
#define CV_KEY_KP_1            ::Calavera::Key::KP1
#define CV_KEY_KP_2            ::Calavera::Key::KP2
#define CV_KEY_KP_3            ::Calavera::Key::KP3
#define CV_KEY_KP_4            ::Calavera::Key::KP4
#define CV_KEY_KP_5            ::Calavera::Key::KP5
#define CV_KEY_KP_6            ::Calavera::Key::KP6
#define CV_KEY_KP_7            ::Calavera::Key::KP7
#define CV_KEY_KP_8            ::Calavera::Key::KP8
#define CV_KEY_KP_9            ::Calavera::Key::KP9
#define CV_KEY_KP_DECIMAL      ::Calavera::Key::KPDecimal
#define CV_KEY_KP_DIVIDE       ::Calavera::Key::KPDivide
#define CV_KEY_KP_MULTIPLY     ::Calavera::Key::KPMultiply
#define CV_KEY_KP_SUBTRACT     ::Calavera::Key::KPSubtract
#define CV_KEY_KP_ADD          ::Calavera::Key::KPAdd
#define CV_KEY_KP_ENTER        ::Calavera::Key::KPEnter
#define CV_KEY_KP_EQUAL        ::Calavera::Key::KPEqual

#define CV_KEY_LEFT_SHIFT      ::Calavera::Key::LeftShift
#define CV_KEY_LEFT_CONTROL    ::Calavera::Key::LeftControl
#define CV_KEY_LEFT_ALT        ::Calavera::Key::LeftAlt
#define CV_KEY_LEFT_SUPER      ::Calavera::Key::LeftSuper
#define CV_KEY_RIGHT_SHIFT     ::Calavera::Key::RightShift
#define CV_KEY_RIGHT_CONTROL   ::Calavera::Key::RightControl
#define CV_KEY_RIGHT_ALT       ::Calavera::Key::RightAlt
#define CV_KEY_RIGHT_SUPER     ::Calavera::Key::RightSuper
#define CV_KEY_MENU            ::Calavera::Key::Menu