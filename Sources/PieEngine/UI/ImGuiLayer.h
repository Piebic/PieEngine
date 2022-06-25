#pragma once

#include "../Core/Layer.h"
#include "../Events/Events/ApplicationEvent.h"
#include "../Events/Events/KeyEvent.h"
#include "../Events/Events/MouseEvent.h"

namespace Core {

	class PIE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void attach() override;
		virtual void detach() override;

		void begin();
		void end();

	private:
		float time = 0.0f;
	};

}