#pragma once

#include "../App/App.h"

#ifdef WIN_API

extern Foundation::App* Foundation::CreateApp();

int main(int argc, char** argv) {
	auto app = Foundation::CreateApp();
	app->run();
	delete app;
	return 0;
}

#endif // WIN_API