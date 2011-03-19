#include <iostream>
#include <sstream>
#include "Logger.hpp"
#include "MessageHandlers.hpp"

using namespace aev;

int main( int argc, char* argv[] )
{
	aevNone() << "This message should not be shown! " << " " << 1 << " " << 2 << " " << 3;
	aevInfo() << "My info message! " << " " << 1 << " " << 2 << " " << 3;
	aevDebug() << "My debug message! " << " " << 1 << " " << 2 << " " << 3;
	aevWarning() << "My warning message! " << " " << 1 << " " << 2 << " " << 3;
	aevCritical() << "My critical message! " << " " << 1 << " " << 2 << " " << 3;
	aevFatal() << "My fatal message! " << " " << 1 << " " << 2 << " " << 3;

#ifdef WIN32
	aevMsgHandlerA handler = &aevMessageHandlerDebugA;
	aevInstallMessageHandlerA( handler );

	aevInfo() << "This message should appear in Visual Studios Debug output.";

	aevInstallMessageHandlerA( NULL );

	aevInfo() << "Informative message.";
#endif

	std::cin.get();
	return 0;
}
