#include "stdafx.h"

#include <chrono>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/trivial.hpp>

namespace mentics { namespace common {

namespace chrono = std::chrono;

uint64_t currentTimeMillis() {
	return chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count();
}

}}