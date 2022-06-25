#pragma once

#include "Core.h"
#include "../Events/Event.h"
//#include "Core/TimeStep.h"

namespace Core {

	class PIE_API Layer {
		public:
		Layer(const std::string& name = "Undefined Layer");
		virtual ~Layer();

		virtual void attach() { }
		virtual void detach() { }
		//virtual void update(TimeStep timeStep) { }
		virtual void update() { }
		virtual void imGuiRender() { };
		virtual void handle(Foundation::Event& event) { }

		inline const std::string& name() const { return debugName; }

		protected:
		std::string debugName;
	};

}