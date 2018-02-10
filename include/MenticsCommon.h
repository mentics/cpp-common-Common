#pragma once

#include <string>
#include <vector>
#include "stdafx.h"

#include "nn.hpp"
#include <spdlog/spdlog.h>

#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


#define FOREVER 1E+31



#define PTRS(TypeName)\
using TypeName##Ptr = nn::nn<TypeName*>;\
using TypeName##UniquePtr = nn::nn<std::unique_ptr<TypeName> >;

#define PTRS1(TypeName, TemplateName)\
template <typename TemplateName>\
using TypeName##Ptr = nn::nn<TypeName<TemplateName>*>;\
template <typename TemplateName>\
using TypeName##UniquePtr = nn::nn<std::unique_ptr<TypeName<TemplateName>>>;

#define PTRS2(TypeName, TemplateName1, TemplateName2)\
template <typename TemplateName1, typename TemplateName2>\
using TypeName##Ptr = nn::nn<TypeName<TemplateName1, TemplateName2>*>;\
template <typename TemplateName1, typename TemplateName2>\
using TypeName##UniquePtr = nn::nn<std::unique_ptr<TypeName<TemplateName1, TemplateName2>>>;

typedef uint8_t byte;

namespace nn = dropbox::oxygen;


//template <typename T, typename... Args>
//std::unique_ptr<T> uniquePtr(Args &&... args) {
//	return std::make_unique<T>(std::forward<Args>(args)...);
//}

namespace MenticsGame {

const std::string EMPTY_STRING;

uint64_t currentTimeMillis();
uint64_t currentTimeNanos();

// https://stackoverflow.com/questions/39912/how-do-i-remove-an-item-from-a-stl-vector-with-a-certain-value

template <typename T, typename... Args>
nn::nn_unique_ptr<T> uniquePtr(Args &&... args);
template <typename T, typename TC, typename... Args>
nn::nn_unique_ptr<T> uniquePtrC(Args &&... args);

class CanLog {
protected:
	std::string name;
public:
	CanLog(std::string logName) : name(logName) {}
	std::shared_ptr<spdlog::logger> m_log = spdlog::stdout_logger_mt("unique name");
	
};


// Not yet used --------------
/*   
class unit_test_sink : public spdlog::sinks::sink
{
public:

	void log(const spdlog::details::log_msg& msg) override
	{
		Logger::WriteMessage(msg.formatted.c_str());
	}

	void log(char* msg)
	{                                                            
		Logger::WriteMessage(msg);
	}

	void flush()
	{
		// to impl
	}

};*/

}


using namespace MenticsGame;