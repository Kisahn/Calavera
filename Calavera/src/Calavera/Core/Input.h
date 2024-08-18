#ifndef INPUT_H
#define INPUT_H

#include <glm/glm.hpp>

#include "Calavera/Core/KeyCodes.h"
#include "Calavera/Core/MouseCodes.h"

namespace Calavera {

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

#endif // !INPUT_H
