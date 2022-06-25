#pragma once

#include "Events/Event.h"

namespace Foundation {

	class PIE_API MouseMovedEvent: public Event {
		public:
		MouseMovedEvent(float x, float y)
			: mouseX(x), mouseY(y) { }
		inline float getX() const { return mouseX; }
		inline float getY() const { return mouseY; }

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << mouseX << ", " << mouseX;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(Mouse | Input)
		private:
		float mouseX, mouseY;
	};

	class PIE_API MouseScrolledEvent: public Event {
		public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: xOffset(xOffset), yOffset(yOffset) { }
		inline float getXOffset() const { return xOffset; }
		inline float getYOffset() const { return yOffset; }

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << xOffset << ", " << yOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(Mouse | Input)
		private:
		float xOffset, yOffset;
	};

	class PIE_API MouseButtonEvent: public Event {
		public:
		inline int getMouseButton() const { return mouseButton; }

		EVENT_CLASS_CATEGORY(Mouse | Input)
		protected:
		MouseButtonEvent(int button)
			:mouseButton(button) { }

		int mouseButton;
	};

	class PIE_API MouseButtonPressedEvent: public MouseButtonEvent {
		public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) { }

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << mouseButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class PIE_API MouseButtonReleasedEvent: public MouseButtonEvent {
		public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) { }

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << mouseButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}