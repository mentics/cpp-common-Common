#pragma once

#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/trivial.hpp>

namespace mentics { namespace common {

class CanLog {
public:
	boost::log::sources::severity_logger_mt<boost::log::trivial::severity_level> lg;
};

}}