#ifndef INPUT_H
#define INPUT_H

#include "Calavera/Core/Base.h"
#include "Calavera/Core/KeyCodes.h"
#include "Calavera/Core/MouseCodes.h"

namespace Calavera {

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

#endif // !INPUT_H
