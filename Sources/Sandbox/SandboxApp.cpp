#include "SandboxApp.h"

class ExampleLayer: public Core::Layer {
	public:
	ExampleLayer(): Core::Layer("Example") { }

	void update() override { logInfo("ExampleLayer update"); }

	void handle(Foundation::Event& event) override { logTrace("Event {0}", event); }

};

SandboxApp::SandboxApp() {
	push(new ExampleLayer());
	pushOverlay(new Core::ImGuiLayer());
}

SandboxApp::~SandboxApp() { }

Foundation::App* Foundation::CreateApp() {
	return new SandboxApp();
}
