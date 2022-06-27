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
		virtual void handle(Foundation::Event& e) override;

		void begin();
		void end();

		void blockEvents(bool block) { isBlockingEvents = block; }

		void setDarkThemeColors();

	private:
		bool isBlockingEvents = true;
	};

}