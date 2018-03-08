#pragma once



#include "stdafx.h"

#include "MenticsCommon.h"
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace MenticsGame {

	void setupLog();

	class test_sink : public spdlog::sinks::sink
	{
	public:
		void log(const spdlog::details::log_msg& msg) override;
		void log(const char* msg);
		void flush();

	};

}


using namespace MenticsGame;

#include <string>
#include <vector>
#include "MenticsCommon.h"
#include "MenticsCommonTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MenticsGame {

	spdlog::sink_ptr sink = std::make_shared<test_sink>();

	void setupLog() {
		mlog = std::make_shared<spdlog::logger>("logger", sink);
		spdlog::register_logger(mlog);
	}


	void test_sink::log(const spdlog::details::log_msg& msg)
	{
		Logger::WriteMessage(msg.formatted.c_str());
	}

	void test_sink::log(const char* msg)
	{
		Logger::WriteMessage(msg);
	}

	void test_sink::flush()
	{
		// to impl
	}
}
