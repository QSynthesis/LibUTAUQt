project(LibUTAUQt LANGUAGES CXX VERSION 0.0.1.1)

set(_qt_libs)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)
list(APPEND _qt_libs Qt${QT_VERSION_MAJOR}::Core)

file(GLOB _src include/*.h include/*.cpp src/*.h src/*.cpp)

if(LIBUTAUQT_BUILD_STATIC)
    add_library(${PROJECT_NAME} STATIC ${_src})
    target_compile_definitions(${PROJECT_NAME} PUBLIC LIBUTAUQT_STATIC)
else()
    add_library(${PROJECT_NAME} SHARED ${_src})
endif()

target_compile_definitions(${PROJECT_NAME} PRIVATE LIBUTAUQT_LIBRARY)

target_link_libraries(${PROJECT_NAME} PUBLIC ${_qt_libs})

target_include_directories(${PROJECT_NAME} PUBLIC include)