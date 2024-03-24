#ifndef _LOGGER_HEADER_INCLUDED_
#define _LOGGER_HEADER_INCLUDED_

#include <spdlog/spdlog.h>

class SILogger
{
public:
	SILogger();
	~SILogger();

public:
	bool Initialize();

private:
	void Finalize();

public:
	template<typename... Args>
	void write(const uint32_t _loglevel, const std::string& fmt, const Args &... args)
	{
		switch (_loglevel)
		{
			case spdlog::level::trace:
			{
				m_logger.trace(fmt, args...);
				break;
			}
			case spdlog::level::debug:
			{
				m_logger.debug(fmt, args...);
				break;
			}
			case spdlog::level::info:
			{
				m_logger.info(fmt, args...);
				break;
			}
			case spdlog::level::warn:
			{
				m_logger.warn(fmt, args...);
				break;
			}
			case spdlog::level::err:
			{
				m_logger.error(fmt, args...);
				break;
			}
			case spdlog::level::critical:
			{
				m_logger.critical(fmt, args...);
				break;
			}
			default:
			{
				break;
			}
		}
	}

private:
	spdlog::logger m_logger;
};
#endif // !_LOGGER_HEADER_INCLUDED_
