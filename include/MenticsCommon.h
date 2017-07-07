#pragma once

#include <string>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/trivial.hpp>

namespace mentics { namespace common {

#define LOG(lvl) BOOST_LOG_SEV(lg, lvl) << logName << ": "

uint64_t currentTimeMillis();

template <typename T>
inline std::string toString(const T& object) {
	std::ostringstream ss;
	ss << object;
	return ss.str();
}

class CanLog {
protected:
	std::string logName;
public:
	CanLog(std::string logName) : logName(logName) {}
	boost::log::sources::severity_logger_mt<boost::log::trivial::severity_level> lg;
};

}}