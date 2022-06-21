#include "SandboxApp.h"

SandboxApp::SandboxApp() { }

SandboxApp::~SandboxApp() { }

Foundation::App* Foundation::CreateApp() {
	return new SandboxApp();
}
