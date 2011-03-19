# This will build aevLogger component
cmake_minimum_required(VERSION 2.8)

# Select Debug as build type, if not selected
if(DEFINED CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel.")
else()
   set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel.")
endif()

# Define the project
project(aevLogger CXX)

# Declare sources
set(AEVLOGGER_PUBLIC_HEADERS src/Logger.hpp src/MessageHandlers.hpp src/Types.hpp)
set(AEVLOGGER_SOURCES src/Logger.cpp src/MessageHandlers.cpp)
set(AEVLOGGER_TEST_SOURCES tsrc/main.cpp)

# Add definitions for Visual Studio
# to prevent warnings.
add_definitions(-DAEVLOGGER_BUILDING)
if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif(MSVC)

# Use src as include directory
include_directories(src)

# Add the library
add_library(aevLogger STATIC ${AEVLOGGER_PUBLIC_HEADERS} ${AEVLOGGER_SOURCES})

# Add the test executable
add_executable(aevLoggerTest ${AEVLOGGER_PUBLIC_HEADERS} ${AEVLOGGER_TEST_SOURCES})
add_dependencies(aevLoggerTest aevLogger)
target_link_libraries(aevLoggerTest aevLogger)

# Mark the debug builds
set_target_properties(aevLoggerTest aevLogger PROPERTIES DEBUG_POSTFIX "d")

# The install rules
install(TARGETS aevLogger DESTINATION lib)
install(FILES ${AEVLOGGER_PUBLIC_HEADERS} DESTINATION include/aev/logger)
install(TARGETS aevLoggerTest DESTINATION bin)
