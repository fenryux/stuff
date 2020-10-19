cmake_minimum_required(VERSION 3.0.0)
project(quicksort VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(quicksort main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set_target_properties(quicksort PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:CONSOLE")
include(CPack)
