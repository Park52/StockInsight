#include "logger.hpp"
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#ifdef _WIN32
#include "spdlog/sinks/msvc_sink.h"
#endif
#define PROJECT_NAME "StockInsight"

SILogger::SILogger()
	: m_logger(PROJECT_NAME)
{
}

SILogger::~SILogger()
{
}

bool SILogger::Initialize()
{
	bool ret = false;
	do
	{
		auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
		if (nullptr == console_sink)
		{
			break;
		}

		auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/mylog.txt", true);
		if (nullptr == file_sink)
		{
			break;
		}
#ifdef _WIN32
		auto msvc_sink = std::make_shared<spdlog::sinks::msvc_sink_mt>();
		if (nullptr == msvc_sink)
		{
			break;
		}
#endif

		m_logger = spdlog::logger(PROJECT_NAME, { console_sink, file_sink, msvc_sink});
#ifdef _DEBUG
		m_logger.set_level(spdlog::level::debug);
#else
		m_logger.set_level(spdlog_level::error);
#endif
		ret = true;
	} while (false);

	return ret;
}

void SILogger::Finalize()
{
}
