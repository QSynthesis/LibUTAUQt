cmake_minimum_required(VERSION 3.17)

project(LibUTAUQt)

set(LIBUTAUQT_BUILD_STATIC OFF)
set(LIBUTAUQT_BUILD_TEST ON)

add_subdirectory(LibUTAUQt)

if(LIBUTAUQT_BUILD_TEST)
    add_subdirectory(test)
endif()
