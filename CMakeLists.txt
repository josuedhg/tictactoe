cmake_minimum_required(VERSION 3.18)

project(tictactoe)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set( CMAKE_CXX_FLAGS "-g -Wall -Wl,--no-as-needed -ldl" )

include(CTest)
include(GNUInstallDirs)
include(CMakeOptions.txt)

if(${COVERAGE})
	include(CodeCoverage)
endif(${COVERAGE})

add_subdirectory(src)
if(${TESTS})
add_subdirectory(tests)
	if(${COVERAGE})
		coverage_target(. */lib/* check)
	endif(${COVERAGE})
endif(${TESTS})

message(STATUS "TESTS " ${TESTS})
message(STATUS "COVERAGE " ${COVERAGE})
