#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Core/Logging/PieLog.h"
#include "Core/KeyCodes.h"
#include "Core/MouseCodes.h"

//#include "Acrylic/Debug/Instrumentor.h"

#ifdef WIN_API
	#include <Windows.h>
#endif // WIN_API