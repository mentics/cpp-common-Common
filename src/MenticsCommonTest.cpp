#include "stdafx.h"

#include "MenticsCommon.h"

namespace MenticsGame {

	
	void setupLog() {
		test_sink sink;
		const auto log = std::make_shared<spdlog::logger>("logger", spdlog::sink_ptr(&sink));
		spdlog::register_logger(log);
	}
	
}
