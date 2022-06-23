#include "Pie.h"
#include "WindowsWindow.h"

#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"
#include "Events/KeyEvent.h"

#include "Platforms/OpenGL/OpenGLContext.h"

namespace Core {

	static bool isGLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description) {
		logPieError("GLFW Error {0}: {1}", error, description);
	}

	Window* Window::create(const WindowInfo& info) {
		return new WindowsWindow(info);
	}

	WindowsWindow::WindowsWindow(const WindowInfo& info) {
		//ACR_PROFILE_FUNCTION();

		init(info);
	}

	WindowsWindow::~WindowsWindow() {
		shutdown();
	}

	void WindowsWindow::init(const WindowInfo& info) {
		//ACR_PROFILE_FUNCTION();

		data.title = info.title;
		data.width = info.width;
		data.height = info.height;

		logPieInfo("Creating window {0} ({1}, {2})", info.title, info.width, info.height);


		if (!isGLFWInitialized) {
			//ACR_PROFILE_SCOPE("glfwInit")
			int success = glfwInit();
			pieCoreAssert(success, "Could not initialize GLFW!");

			glfwSetErrorCallback(GLFWErrorCallback);

			isGLFWInitialized = true;
		}

		{
			//ACR_PROFILE_SCOPE("glfwCreateWindow")
			window = glfwCreateWindow((int) info.width, (int) info.height, data.title.c_str(), nullptr, nullptr);
		}

		//context = new OpenGLContext(window);
		//context->init();

		glfwSetWindowUserPointer(window, &data);
		setVSync(false);

		glfwSetWindowSizeCallback(window, [] (GLFWwindow* window, int width, int height) {
			WindowData& data = *(WindowData*) (glfwGetWindowUserPointer(window));

			data.width = width;
			data.height = height;

			//WindowResizeEvent event(width, height);
			//data.eventCallback(event);
		});

		glfwSetWindowCloseCallback(window, [] (GLFWwindow* window) {
			WindowData& data = *(WindowData*) (glfwGetWindowUserPointer(window));
			//WindowCloseEvent event;
			//data.eventCallback(event);
		});

		glfwSetCharCallback(window, [] (GLFWwindow* window, unsigned int keycode) {
			WindowData& data = *(WindowData*) (glfwGetWindowUserPointer(window));

			//KeyTypedEvent event(keycode);
			//data.eventCallback(event);
		});

		glfwSetKeyCallback(window, [] (GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& data = *(WindowData*) (glfwGetWindowUserPointer(window));

			switch (action) {
				case GLFW_PRESS:
				{
					//KeyPressedEvent event(key, 0);
					//data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					//KeyReleasedEvent event(key);
					//data.eventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					//KeyPressedEvent event(key, 1);
					//data.eventCallback(event);
					break;
				}
			}

		});

		glfwSetMouseButtonCallback(window, [] (GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = *(WindowData*) (glfwGetWindowUserPointer(window));

			switch (action) {
				case GLFW_PRESS:
				{
					//MouseButtonPressedEvent event(button);
					//data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					//MouseButtonReleasedEvent event(button);
					//data.eventCallback(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(window, [] (GLFWwindow* window, double xOffset, double yOfsset) {
			WindowData& data = *(WindowData*) (glfwGetWindowUserPointer(window));

			//MouseScrolledEvent event((float)xOffset, (float)yOfsset);
			//data.eventCallback(event);
		});

		glfwSetCursorPosCallback(window, [] (GLFWwindow* window, double xOffset, double yOfsset) {
			WindowData& data = *(WindowData*) (glfwGetWindowUserPointer(window));

			//MouseMovedEvent event((float)xOffset, (float)yOfsset);
			//data.eventCallback(event);
		});
	}

	void WindowsWindow::shutdown() {
		//ACR_PROFILE_FUNCTION();

		glfwDestroyWindow(window);
	}

	void WindowsWindow::update() {
		//ACR_PROFILE_FUNCTION();

		glfwPollEvents();
		//context->SwapBuffers();
	}

	void WindowsWindow::setVSync(bool enabled) {
		//ACR_PROFILE_FUNCTION();

		logPieInfo("Set VSync to {0}", enabled ? "enabled" : "disabled");

		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		data.isVSyncEnabled = enabled;
	}

	bool WindowsWindow::isVSync() const {
		return data.isVSyncEnabled;
	}
}