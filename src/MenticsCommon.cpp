#include "stdafx.h"
#include "MenticsCommon.h"

#include <chrono>

namespace MenticsGame {

namespace chrono = std::chrono;

const chrono::high_resolution_clock::time_point BASE_TIME = chrono::high_resolution_clock::now();

uint64_t currentTimeMillis() {
//	return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
	const chrono::high_resolution_clock::time_point now = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::milliseconds>(now - BASE_TIME).count();
}

uint64_t currentTimeNanos() {
//	return chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
	const chrono::high_resolution_clock::time_point now = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(now - BASE_TIME).count();
}



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

}