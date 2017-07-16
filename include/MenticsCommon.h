#pragma once

#include <string>
#include <vector>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/trivial.hpp>

typedef uint8_t byte;

namespace mentics { namespace common {

#define LOG(lvl) BOOST_LOG_SEV(lg, lvl) << name << ": "

const std::string EMPTY_STRING;

uint64_t currentTimeMillis();

// https://stackoverflow.com/questions/39912/how-do-i-remove-an-item-from-a-stl-vector-with-a-certain-value
template <typename T>
inline void removeBySwap(std::vector<T>& v, T& value) {
	auto it = std::find(v.begin(), v.end(), value);

	if (it != v.end()) {
		// swap the one to be removed with the last element
		// and remove the item at the end of the container
		// to prevent moving all items after value by one
		std::swap(*it, v.back());
		v.pop_back();
	}
}

template <typename T>
inline std::string toString(const T& object) {
	std::ostringstream ss;
	ss << object;
	return ss.str();
}

class CanLog {
protected:
	std::string name;
public:
	CanLog(std::string logName) : name(logName) {}
	boost::log::sources::severity_logger_mt<boost::log::trivial::severity_level> lg;
};

}}