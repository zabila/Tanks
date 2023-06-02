cmake_minimum_required(VERSION 3.21)

project(tanks_game LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

include_directories(${Qt5Widgets_INCLUDE_DIRS} ${QtQml_INCLUDE_DIRS})
add_definitions(${Qt5Widgets_DEFINITIONS} ${QtQml_DEFINITIONS} ${${Qt5Quick_DEFINITIONS}})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Quick Qml REQUIRED)

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "src/core/*.cpp")
file(GLOB_RECURSE PROJECT_HEADERS CONFIGURE_DEPENDS "src/core/*.h")
file(GLOB_RECURSE QML_FILES "src/*.qml")
include_directories(src/core)


qt5_add_resources(QRC_SOURCES "src/qml.qrc")

add_executable(${PROJECT_NAME} ${PROJECT_HEADERS} ${PROJECT_SOURCES} ${QRC_SOURCES} ${QML_FILES} src/core/Logger.h src/main.cpp)

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick Qt5::Qml -lpthread)

if (ENABLED_TESTS)
    enable_testing()
    include(CTest)
    add_subdirectory(tests)
endif ()
