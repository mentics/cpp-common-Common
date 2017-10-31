#include "stdafx.h"

//#include <boost/log/core.hpp>
//#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
//#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

namespace MenticsGame {

void setupLog() {
	auto sink = boost::log::add_file_log("unit-test.log");
	sink->locked_backend()->auto_flush(true);
	boost::log::core::get()->set_filter(
		boost::log::trivial::severity >= boost::log::trivial::trace
	);
	boost::log::add_common_attributes();
}

}