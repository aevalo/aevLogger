#ifndef AEV_LOGGER_TYPES_HPP
#define AEV_LOGGER_TYPES_HPP

namespace aev
{
	enum LogLevel
	{
		None		= 0,
		Info		= 1,
		Debug		= 2,
		Warning		= 3,
		Critical	= 4,
		Fatal		= 5
	};

	typedef void (*aevMsgHandlerA)( int level, const char* msg );
	typedef void (*aevMsgHandlerW)( int level, const wchar_t* msg );
}

#endif // AEV_LOGGER_TYPES_HPP

