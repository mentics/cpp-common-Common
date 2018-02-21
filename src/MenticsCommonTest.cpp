#include "stdafx.h"

#include <string>
#include <vector>
#include "MenticsCommon.h"
#include "MenticsCommonTest.h"

namespace MenticsGame {
	std::shared_ptr<spdlog::logger> log = spdlog::get("logger");
	spdlog::sink_ptr sink = std::make_shared<test_sink>();

	void setupLog() {
		log = std::make_shared<spdlog::logger>("logger", sink);
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
