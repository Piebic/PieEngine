#pragma once

#include "Core/Window.h"

#include "GLFW/glfw3.h"
//#include "Acrylic/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Core {

	class WindowsWindow: public Window {
		public:
		WindowsWindow(const WindowInfo& info);
		virtual ~WindowsWindow();

		void update() override;

		inline unsigned int getWidth() const override { return data.width; }
		inline unsigned int getHeight() const override { return data.height; }

		//Window attributes
		inline void setEventCallback(const EventCallbackFn& callback) override { data.eventCallback = callback; }
		void setVSync(bool enabled) override;
		bool isVSync() const override;

		inline virtual void* getNativeWindow() const { return window; }

		private:
		virtual void init(const WindowInfo& info);
		virtual void shutdown();
		private:
		GLFWwindow* window;
		//GraphicsContext* context;

		struct WindowData {
			std::string title;
			unsigned int width, height;
			bool isVSyncEnabled;

			EventCallbackFn eventCallback;
		};

		WindowData data;
	};

}