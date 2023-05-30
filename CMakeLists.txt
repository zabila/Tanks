cmake_minimum_required(VERSION 3.21)

project(tanks_game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "src/core/*.cpp")
file(GLOB_RECURSE PROJECT_RESOURCES CONFIGURE_DEPENDS "src/qml/*.qml")

add_library(tanks_game_lib STATIC ${PROJECT_SOURCES})

target_include_directories(tanks_game_lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/core)

add_executable(${PROJECT_NAME} "src/main.cpp" ${PROJECT_RESOURCES} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} tanks_game_lib Qt5::Core Qt5::Quick)

if(ENABLED_TESTS)
    enable_testing()
    include(CTest)
    add_subdirectory(tests)
endif()
