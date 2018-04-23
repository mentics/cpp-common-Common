#pragma once
#include "stdafx-common.h"
#include "CppUnitTest.h"
#include "MenticsCommon.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MenticsGame {

class test_sink : public spdlog::sinks::sink {
public:
    inline void log(const spdlog::details::log_msg& msg) override;
    inline void log(const char* msg);
    inline void flush();
};

static spdlog::sink_ptr sink = std::make_shared<test_sink>();

inline void setupLog() {
    MenticsGame::mlog = std::make_shared<spdlog::logger>("logger", sink);
    //spdlog::register_logger(MenticsGame::mlog);
}


inline void test_sink::log(const spdlog::details::log_msg& msg) {
    Logger::WriteMessage(msg.formatted.c_str());
}

inline void test_sink::log(const char* msg) {
    Logger::WriteMessage(msg);
}

inline void test_sink::flush() {
    // to impl
}
}
