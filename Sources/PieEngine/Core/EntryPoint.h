#pragma once

#include "../App/App.h"

#ifdef WIN_API

extern Foundation::App* Foundation::CreateApp();

int main(int argc, char** argv) {
	Core::PieLog::init();

	logPieTrace("Hello, pie trace");
	logPieInfo("Hello, pie info");
	logPieWarn("Hello, pie warn");
	logPieError("Hello, pie error");

	logTrace("Hello, app trace");
	logInfo("Hello, app info");
	logWarn("Hello, app warn");
	logError("Hello, app error");

	auto app = Foundation::CreateApp();
	app->run();
	delete app;
	return 0;
}

#endif // WIN_API