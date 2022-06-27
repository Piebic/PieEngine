#include "Pie.h"
#include "App/App.h"

#include "../Core/Logging/PieLog.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Foundation {

	App* App::instance = nullptr;

	App::App() {
		//ACR_PROFILE_FUNCTION();
		pieCoreAssert(!instance, "Application already exist");

		instance = this;
		window = std::unique_ptr<Core::Window>(Core::Window::create());
		window->setEventCallback(BIND_EVENT_FN(onEvent));
		imGuiLayer = new Core::ImGuiLayer();
		pushOverlay(imGuiLayer);
	}

	App::~App() { }

	void App::run() {
		//ACR_PROFILE_FUNCTION();

		while (isRunning) {
			//ACR_PROFILE_SCOPE("Main run loop.");
			float time = (float) glfwGetTime();
			//TimeStep timeStep = time - m_LastFrameTime;
			//m_LastFrameTime = time;

			if (!isMinimized) {
				{
					//ACR_PROFILE_SCOPE("LayerStack OnUpdate.");

					for (Core::Layer* layer : layerStack)
						layer->update();
				}

				imGuiLayer->begin();

				{
					//ACR_PROFILE_SCOPE("LayerStack OnImGuiRender.");

					for (Core::Layer* layer : layerStack)
						layer->imGuiRender();
				}

				imGuiLayer->end();
			}

			window->update();
		}
	}

	void App::onEvent(Foundation::Event& event) {
		Foundation::EventDispatcher dispatcher(event);
		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(Foundation::App::onWindowClose));
		dispatcher.dispatch<WindowResizeEvent>(BIND_EVENT_FN(Foundation::App::onWindowResize));

		logPieTrace("{0}", event);

		for (auto it = layerStack.end(); it != layerStack.begin();) {
			(*--it)->handle(event);
			if (event.isEventHandled) break;
		}


	}

	void App::push(Core::Layer* layer) {
		layerStack.push(layer);
		layer->attach();
	}

	void App::pushOverlay(Core::Layer* layer) {
		layerStack.pushOverlay(layer);
		layer->attach();
	}

	void App::close() {
		isRunning = false;
	}

	bool App::onWindowClose(WindowCloseEvent& e) {
		isRunning = false;
		return true;
	}

	bool App::onWindowResize(WindowResizeEvent& e) {
		//ACR_PROFILE_FUNCTION();

		if (e.getWidth() == 0 || e.getHeight() == 0) {
			isMinimized = true;
			return false;
		}

		isMinimized = false;

		//Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

		return false;
	}

}