#pragma once

#include "../Core/Core.h"
#include "Core/Window.h"

namespace Foundation {

	class PIE_API App {

		public:
		App();
		virtual ~App();

		void run();

		private:
		std::unique_ptr<Core::Window> window;

		bool isRunning = true;
		bool isMinimized = false;
	};

	// To be defined in CLIENT
	App* CreateApp();

}
