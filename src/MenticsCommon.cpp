#include "stdafx.h"

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

}