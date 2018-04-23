// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//
#pragma once
#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include <stdio.h>
#include <tchar.h>
#include <gsl/gsl>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <random>
#include <functional>

#include <spdlog/logger.h>
#include <spdlog/spdlog.h>
#include "spdlog/fmt/bundled/ostream.h"

#include "nn.hpp"
