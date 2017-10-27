// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers



// TODO: reference additional headers your program requires here

#include <stdio.h>
#include <tchar.h>

#include <gsl/gsl>

#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/trivial.hpp>
#include <boost/lockfree/queue.hpp>

#include <vector>
#include <queue>

#include <mutex>
#include <condition_variable>

#include "CppUnitTest.h"

#include "nlopt/nlopt.hpp"

#include "nn.hpp"
