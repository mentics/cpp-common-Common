#include "stdafx.h"

#include <string>
#include <vector>
#include "MenticsCommon.h"
#include "MenticsCommonTest.h"

namespace MenticsGame {

	
	void setupLog() {
		test_sink sink;
		const auto log = std::make_shared<spdlog::logger>("logger", spdlog::sink_ptr(&sink));
		spdlog::register_logger(log);
		log->error("WORKS");
	}
	

	void test_sink::log(const spdlog::details::log_msg& msg)
	{
		Logger::WriteMessage(msg.formatted.c_str());
	}

	void test_sink::log(char* msg)
	{
		Logger::WriteMessage(msg);
	}

	void test_sink::flush()
	{
		// to impl
	}
}
