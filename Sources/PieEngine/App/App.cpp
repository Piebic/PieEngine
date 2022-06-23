#include "Pie.h"
#include "App.h"

#include "../Core/Logging/PieLog.h"

#include <GLFW/glfw3.h>

Foundation::App::App() {
	window = std::unique_ptr<Core::Window>(Core::Window::create());
}

Foundation::App::~App() { }

void Foundation::App::run() {
	while (isRunning) {
		glClearColor(1, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		for (Core::Layer* layer : layerStack)
			layer->update();

		window->update();
	}
}

void Foundation::App::onEvent(PieEvents::Event& event) {
	PieEvents::EventDispatcher dispatcher(event);
	//dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

	logPieTrace("{0}", event);

	for (auto it = layerStack.end(); it != layerStack.begin();) {
		(*--it)->handle(event);
		if (event.isHandled) break;
	}


}

void Foundation::App::push(Core::Layer* layer) { 
	layerStack.push(layer);
}

void Foundation::App::pushOverlay(Core::Layer* layer) {
	layerStack.pushOverlay(layer);
}
