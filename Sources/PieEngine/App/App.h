#pragma once

#include "../Core/Core.h"

#include "../Core/Window.h"
#include "../Core/LayerStack.h"
#include "../Events/Event.h"
#include "../Events/Events/ApplicationEvent.h"

namespace Foundation {

	class PIE_API App {

		public:
		App();
		virtual ~App();

		void run();

		void onEvent(PieEvents::Event& event);

		void push(Core::Layer* layer);
		void pushOverlay(Core::Layer* layer);

		private:
		std::unique_ptr<Core::Window> window;
		Core::LayerStack layerStack;

		bool isRunning = true;
		bool isMinimized = false;
	};

	// To be defined in CLIENT
	App* CreateApp();

}
