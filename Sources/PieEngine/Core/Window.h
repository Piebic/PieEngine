#pragma once

#include "Pie.h"

#include "Core/Core.h"
#include "Events/Event.h"


namespace Core {

	struct WindowInfo {
		std::string title;
		unsigned int width;
		unsigned int height;

		WindowInfo(const std::string& title = "Pie Game Engine",
					unsigned int width = 1920,
					unsigned int height = 1080)
			: title(title), width(width), height(height) { }

	};

	class PIE_API Window {
		public:
		using EventCallbackFn = std::function<void(Foundation::Event&)>;

		virtual ~Window() { }

		virtual void update() = 0;

		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;

		virtual void setEventCallback(const EventCallbackFn& callback) = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual bool isVSync() const = 0;

		virtual void* getNativeWindow() const = 0;

		static Window* create(const WindowInfo& info = WindowInfo());

	};

}