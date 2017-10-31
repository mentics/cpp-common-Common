#include "stdafx.h"

#include <chrono>

namespace MenticsGame {

namespace chrono = std::chrono;

uint64_t currentTimeMillis() {
	return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
}

uint64_t currentTimeNanos() {
	return chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
}

}