#pragma once

#include "../Core/Core.h"

namespace Foundation {

	class PIE_API App {

		public:
		App();
		virtual ~App();

		void run();

	};

	// To be defined in CLIENT
	App* CreateApp();

}
