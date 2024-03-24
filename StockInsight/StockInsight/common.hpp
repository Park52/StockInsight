#ifndef _COMMON_HPP_INCLUDED_
#define _COMMON_HPP_INCLUDED_

#include <spdlog/spdlog.h>
enum log_level : int {
	trace = SPDLOG_LEVEL_TRACE,
	debug = SPDLOG_LEVEL_DEBUG,
	info = SPDLOG_LEVEL_INFO,
	warn = SPDLOG_LEVEL_WARN,
	err = SPDLOG_LEVEL_ERROR,
	CRITICAL = SPDLOG_LEVEL_CRITICAL,
	off = SPDLOG_LEVEL_OFF,
};
#endif