#pragma once

#include <glm/glm.hpp>

#include "Core/Core.h"

#include "Core/KeyCodes.h"
#include "Core/MouseCodes.h"

namespace Core {

	class Input {
		public:
		static bool isKeyPressed(KeyCode keycode);

		static bool isMouseButtonPressed(MouseCode button);
		static glm::vec2 getMousePosition();
		static float getMouseX();
		static float getMouseY();

		private:
		static Input* instance;
	};
}