#ifndef AEV_LOGGER_MESSAGE_HANDLERS_HPP
#define AEV_LOGGER_MESSAGE_HANDLERS_HPP

namespace aev
{
	void aevMessageHandlerLogA( int level, const char* msg );
	void aevMessageHandlerLogW( int level, const wchar_t* msg );

#ifdef WIN32
	void aevMessageHandlerDebugA( int level, const char* msg );
	void aevMessageHandlerDebugW( int level, const wchar_t* msg );
#endif
}

#endif // AEV_LOGGER_MESSAGE_HANDLERS_HPP

