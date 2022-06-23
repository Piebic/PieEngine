#include "Pie.h"
#include "App.h"

Foundation::App::App() {
	window = std::unique_ptr<Core::Window>(Core::Window::create());
}

Foundation::App::~App() { }

void Foundation::App::run() {
	while (isRunning) {
		window->update();
	}
}
