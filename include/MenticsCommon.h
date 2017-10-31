#pragma once

#include <string>
#include <vector>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/trivial.hpp>
#include "nn.hpp"

#define FOREVER 1E+31

#define LOG(lvl) BOOST_LOG_SEV(lg, lvl) << name << ": "

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

template <typename T, typename... Args>
nn::nn_unique_ptr<T> uniquePtr(Args &&... args) {
	return nn::nn_unique_ptr<T>(nn::i_promise_i_checked_for_null,
		std::unique_ptr<T>(new T(std::forward<Args>(args)...)));
}

template <typename T, typename TC, typename... Args>
nn::nn_unique_ptr<T> uniquePtrC(Args &&... args) {
	return nn::nn_unique_ptr<T>(nn::i_promise_i_checked_for_null,
		std::unique_ptr<T>(new TC(std::forward<Args>(args)...)));
}

//template <typename T, typename... Args>
//std::unique_ptr<T> uniquePtr(Args &&... args) {
//	return std::make_unique<T>(std::forward<Args>(args)...);
//}

namespace mentics { namespace common {

const std::string EMPTY_STRING;

uint64_t currentTimeMillis();
uint64_t currentTimeNanos();

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

namespace lvl = boost::log::trivial;
namespace cmn = mentics::common;
