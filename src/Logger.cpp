#include <iostream>
#include <ctime>
#include <sstream>
#include "Logger.hpp"
#include "Types.hpp"
#include "MessageHandlers.hpp"

namespace aev
{
	// Global message handler (ASCII)
	aevMsgHandlerA gMsgHandlerA = NULL;
	// Global message handler (WIDE CHARACTER)
	aevMsgHandlerW gMsgHandlerW = NULL;

	void aevInstallMessageHandlerA( aevMsgHandlerA msgHandler )
	{
		if ( msgHandler )
		{
			gMsgHandlerA = msgHandler;
		}
		else
		{
			gMsgHandlerA = aevMessageHandlerLogA;
		}
	}

	void aevInstallMessageHandlerW( aevMsgHandlerW msgHandler )
	{
		if ( msgHandler )
		{
			gMsgHandlerW = msgHandler;
		}
		else
		{
			gMsgHandlerW = aevMessageHandlerLogW;
		}
	}

	//	Custom streambuf class for the logstream
	template<typename E, typename T = std::char_traits<E>>
	class basic_logbuf : public std::basic_stringbuf<E, T>
	{
		public:
			basic_logbuf( LogLevel level ) : _level( level ) {}
			~basic_logbuf() { sync(); }
	
		protected:
			int sync() {
				output_log_string( str().c_str() );
				str( std::basic_string<E>() );	// Clear the string buffer.
				return 0;
			}
			
			void output_log_string( const E* text ) {}

		private:
			 LogLevel _level;
	};
	
	//	Specialisations for char and wchar_t
	template<>
	void basic_logbuf<char>::output_log_string( const char* text )
	{
		if ( gMsgHandlerA )
		{
			(*gMsgHandlerA)( _level, text );
		}
		else
		{
			aevMessageHandlerLogA( _level, text );
		}
	}
	
	template<>
	void basic_logbuf<wchar_t>::output_log_string( const wchar_t* text )
	{
		if ( gMsgHandlerW )
		{
			(*gMsgHandlerW)( _level, text );
		}
		else
		{
			aevMessageHandlerLogW( _level, text );
		}
	}

		// The logstream
	template<typename E, typename T> basic_logstream<E,T>::basic_logstream( LogLevel level )
		: std::basic_ostream<E, T>( new basic_logbuf<E, T>( level ) ) {}
	
	template<typename E, typename T> basic_logstream<E,T>::~basic_logstream() { delete rdbuf(); }
	
	logstream aevNone() { return logstream( None ); }
	logstreamw aevNoneW() { return logstreamw( None ); }

	logstream aevInfo() { return logstream( Info ); }
	logstreamw aevInfoW() { return logstreamw( Info ); }

	logstream aevDebug() { return logstream( Debug ); }
	logstreamw aevDebugW() { return logstreamw( Debug ); }

	logstream aevWarning() { return logstream( Warning ); }
	logstreamw aevWarningW() { return logstreamw( Warning ); }

	logstream aevCritical() { return logstream( Critical ); }
	logstreamw aevCriticalW() { return logstreamw( Critical ); }

	logstream aevFatal() { return logstream( Fatal ); }
	logstreamw aevFatalW() { return logstreamw( Fatal ); }
}