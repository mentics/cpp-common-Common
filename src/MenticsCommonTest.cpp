#include "stdafx.h"

//#include <boost/log/core.hpp>
//#include <boost/log/trivial.hpp>
//#include <boost/log/expressions.hpp>
//#include <boost/log/sinks/text_file_backend.hpp>
//#include <boost/log/utility/setup/file.hpp>
//#include <boost/log/utility/setup/common_attributes.hpp>
//#include <boost/log/sources/severity_logger.hpp>
//#include <boost/log/sources/record_ostream.hpp>

#include "MenticsCommon.h"

namespace MenticsGame {

	
	void setupLog() {

		unit_test_sink s;
		// s.log("something");
		// m_logger->flush_on(spdlog::level::err); TODO: automatic flash?

	}
	
}