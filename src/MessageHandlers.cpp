#include <iostream>
#include <sstream>
#include <ctime>

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif

#include "MessageHandlers.hpp"
#include "Types.hpp"

namespace aev
{
	// Format the timestamp as DD/MM/YYYY HH:MM:SS
	const char* timeStampCustomA = "%d/%m/%Y %H:%M:%S";
	// Format the timestamp as locale says
	const char* timeStampLocaleA = "%x %X";
	// Format the timestamp as DD/MM/YYYY HH:MM:SS
	const wchar_t* timeStampCustomW = (wchar_t*)("%d/%m/%Y %H:%M:%S");
	// Format the timestamp as locale says
	const wchar_t* timeStampLocaleW = (wchar_t*)("%x %X");

	void timestamp( wchar_t* buf, std::size_t len, const wchar_t* format )
	{
		time_t rawtime;
		struct tm* timeinfo;

		time( &rawtime );
		timeinfo = localtime( &rawtime );

		wcsftime( buf, len, format, timeinfo );
	}

	void timestamp( char* buf, std::size_t len, const char* format )
	{
		time_t rawtime;
		struct tm* timeinfo;

		time( &rawtime );
		timeinfo = localtime( &rawtime );

		strftime( buf, len, format, timeinfo );
	}

	void aevMessageHandlerLogA( int level, const char* msg )
	{
		char buffer[ 80 ];
		timestamp( buffer, 80, timeStampLocaleA );

		switch ( level )
		{
			case None:
				break;
			case Info:
				std::clog << "[" << buffer << "] INFO: " << msg << std::endl;
				break;
			case Debug:
				std::clog << "[" << buffer << "] DEBUG: " << msg << std::endl;
				break;
			case Warning:
				std::clog << "[" << buffer << "] WARNING: " << msg << std::endl;
				break;
			case Critical:
				std::clog << "[" << buffer << "] CRITICAL: " << msg << std::endl;
				break;
			case Fatal:
				std::clog << "[" << buffer << "] FATAL: " << msg << std::endl;
				break;
		}
	}

	void aevMessageHandlerLogW( int level, const wchar_t* msg )
	{
		wchar_t buffer[ 80 ];
		timestamp( buffer, 80, timeStampLocaleW );

		switch ( level )
		{
			case None:
				break;
			case Info:
				std::clog << "[" << buffer << "] INFO: " << msg << std::endl;
				break;
			case Debug:
				std::clog << "[" << buffer << "] DEBUG: " << msg << std::endl;
				break;
			case Warning:
				std::clog << "[" << buffer << "] WARNING: " << msg << std::endl;
				break;
			case Critical:
				std::clog << "[" << buffer << "] CRITICAL: " << msg << std::endl;
				break;
			case Fatal:
				std::clog << "[" << buffer << "] FATAL: " << msg << std::endl;
				break;
		}
	}

#ifdef WIN32

	void aevMessageHandlerDebugA( int level, const char* msg )
	{
		std::ostringstream oss;

		switch ( level )
		{
			case None:
				break;
			case Info:
				oss << "INFO: " << msg << std::endl;
				::OutputDebugStringA( oss.str().c_str() );
				break;
			case Debug:
				oss << "DEBUG: " << msg << std::endl;
				::OutputDebugStringA( oss.str().c_str() );
				break;
			case Warning:
				oss << "WARNING: " << msg << std::endl;
				::OutputDebugStringA( oss.str().c_str() );
				break;
			case Critical:
				oss << "CRITICAL: " << msg << std::endl;
				::OutputDebugStringA( oss.str().c_str() );
				break;
			case Fatal:
				oss << "FATAL: " << msg << std::endl;
				::OutputDebugStringA( oss.str().c_str() );
				break;
		}
	}

	void aevMessageHandlerDebugW( int level, const wchar_t* msg )
	{
		std::wostringstream woss;

		switch ( level )
		{
			case None:
				break;
			case Info:
				woss << "INFO: " << msg << std::endl;
				::OutputDebugStringW( woss.str().c_str() );
				break;
			case Debug:
				woss << "DEBUG: " << msg << std::endl;
				::OutputDebugStringW( woss.str().c_str() );
				break;
			case Warning:
				woss << "WARNING: " << msg << std::endl;
				::OutputDebugStringW( woss.str().c_str() );
				break;
			case Critical:
				woss << "CRITICAL: " << msg << std::endl;
				::OutputDebugStringW( woss.str().c_str() );
				break;
			case Fatal:
				woss << "FATAL: " << msg << std::endl;
				::OutputDebugStringW( woss.str().c_str() );
				break;
		}
	}

#endif // WIN32
}
