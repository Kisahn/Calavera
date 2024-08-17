#ifndef MOUSECODES_H
#define MOUSECODES_H

namespace Calavera
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

#define CV_MOUSE_BUTTON_0      ::Calavera::Mouse::Button0
#define CV_MOUSE_BUTTON_1      ::Calavera::Mouse::Button1
#define CV_MOUSE_BUTTON_2      ::Calavera::Mouse::Button2
#define CV_MOUSE_BUTTON_3      ::Calavera::Mouse::Button3
#define CV_MOUSE_BUTTON_4      ::Calavera::Mouse::Button4
#define CV_MOUSE_BUTTON_5      ::Calavera::Mouse::Button5
#define CV_MOUSE_BUTTON_6      ::Calavera::Mouse::Button6
#define CV_MOUSE_BUTTON_7      ::Calavera::Mouse::Button7
#define CV_MOUSE_BUTTON_LAST   ::Calavera::Mouse::ButtonLast
#define CV_MOUSE_BUTTON_LEFT   ::Calavera::Mouse::ButtonLeft
#define CV_MOUSE_BUTTON_RIGHT  ::Calavera::Mouse::ButtonRight
#define CV_MOUSE_BUTTON_MIDDLE ::Calavera::Mouse::ButtonMiddle

#endif // !MOUSECODES_H
