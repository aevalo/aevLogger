cmake_minimum_required(VERSION 2.8)

project(aevLogger CXX)

set(AEVLOGGER_PUBLIC_HEADERS src/Logger.hpp src/MessageHandlers.hpp src/Types.hpp)
set(AEVLOGGER_SOURCES src/Logger.cpp src/MessageHandlers.cpp)
set(AEVLOGGER_TEST_SOURCES tsrc/main.cpp)

add_definitions(-DAEVLOGGER_BUILDING)
if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif(MSVC)

include_directories(src)

add_library(aevLogger STATIC ${AEVLOGGER_PUBLIC_HEADERS} ${AEVLOGGER_SOURCES})

add_executable(aevLoggerTest ${AEVLOGGER_PUBLIC_HEADERS} ${AEVLOGGER_TEST_SOURCES})
add_dependencies(aevLoggerTest aevLogger)
target_link_libraries(aevLoggerTest aevLogger)

set_target_properties(aevLoggerTest aevLogger PROPERTIES DEBUG_POSTFIX "d")

install(TARGETS aevLogger DESTINATION lib)
install(FILES ${AEVLOGGER_PUBLIC_HEADERS} DESTINATION include/aev/logger)
install(TARGETS aevLoggerTest DESTINATION bin)
