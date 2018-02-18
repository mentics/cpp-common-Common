#pragma once



using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace MenticsGame {

void setupLog();



class test_sink : public spdlog::sinks::sink
{
public:
	void log(const spdlog::details::log_msg& msg) override;
	void log(char* msg);
	void flush();

};

}


using namespace MenticsGame;


