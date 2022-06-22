#pragma once

#include "Core/Core.h"

namespace PieEvents {

	// Events are blocking, meaning when event occurs it must to be dealt right then an there

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory {
		None = 0,
		App			= BIT(0),
		Input		= BIT(1),
		Keyboard	= BIT(2),
		Mouse		= BIT(3),
		MouseButton = BIT(4)
	};

	#define EVENT_CLASS_TYPE(type)	static EventType staticType() { return EventType::##type; }\
									virtual EventType type() const override { return staticType(); }\
									virtual const char* name() const override { return #type; }

	#define EVENT_CLASS_CATEGORY(category) virtual int categoryFlags() const override { return category; }

	class PIE_API Event {
		friend class EventDispatcher;
		public:
		virtual EventType type() const = 0;
		virtual const char* name() const = 0;
		virtual int categoryFlags() const = 0;
		virtual std::string toString() const { return name(); }

		// Is this event in the given category
		inline bool isIn(EventCategory category) {
			return categoryFlags() & category;
		}

		// Is event handled or not
		bool isEventHandled = false;
	};

	class EventDispatcher {
		template<typename T>
		using EventFn = std::function<bool(T&)>;
		public:
		EventDispatcher(Event& event)
			: storedEvent(event) { }

		template<typename T>
		bool dispatch(EventFn<T> func) {
			if (storedEvent.type() == T::staticType()) {
				storedEvent.isEventHandled = func(*(T*) &storedEvent);
				return true;
			}
			return false;
		}

		private:
		Event& storedEvent;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& event) {
		return os << event.toString();
	}
}