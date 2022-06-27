#include "Pie.h"
#include "Core/Input.h"

#include <GLFW/glfw3.h>
#include "App/App.h"

namespace Core {

	bool Input::isKeyPressed(const KeyCode keycode) {
		auto* window = static_cast<GLFWwindow*>(Foundation::App::get().getWindow().getNativeWindow());
		auto state = glfwGetKey(window, static_cast<int32_t>(keycode));
		return state == GLFW_PRESS;
	}

	bool Input::isMouseButtonPressed(const MouseCode button) {
		auto* window = static_cast<GLFWwindow*>(Foundation::App::get().getWindow().getNativeWindow());
		auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));
		return state == GLFW_PRESS;
	}

	glm::vec2 Input::getMousePosition() {
		auto* window = static_cast<GLFWwindow*>(Foundation::App::get().getWindow().getNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		return { (float) xpos, (float) ypos };
	}

	float Input::getMouseX() {
		return getMousePosition().x;
	}

	float Input::getMouseY() {
		return getMousePosition().y;
	}

}