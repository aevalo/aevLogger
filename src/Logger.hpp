#ifndef AEV_LOGGER_HPP
#define AEV_LOGGER_HPP

#include <sstream>
#include "Types.hpp"


namespace aev
{
	void aevInstallMessageHandlerA( aevMsgHandlerA msgHandler = NULL );
	void aevInstallMessageHandlerW( aevMsgHandlerW msgHandler = NULL );

	template<typename E, typename T = std::char_traits<E>>
	class basic_logstream : public std::basic_ostream<E, T>
	{
		public:
			// Connect the base ostream with the custom streambuf.
			basic_logstream( LogLevel level );
			~basic_logstream();
	};

	//	Typedefs for the obvious template instantions
	typedef basic_logstream<char>		logstream;
	typedef basic_logstream<wchar_t>	logstreamw;

	logstream aevNone();
	logstreamw aevNoneW();

	logstream aevInfo();
	logstreamw aevInfoW();

	logstream aevDebug();
	logstreamw aevDebugW();

	logstream aevWarning();
	logstreamw aevWarningW();

	logstream aevCritical();
	logstreamw aevCriticalW();

	logstream aevFatal();
	logstreamw aevFatalW();
}

#endif // AEV_LOGGER_HPP
