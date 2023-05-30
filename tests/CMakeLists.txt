cmake_minimum_required(VERSION 3.16)

project(tanks_game_tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "src/core/*.cpp")

add_executable(${PROJECT_NAME} ${PROJECT_RESOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src)

target_link_libraries(${PROJECT_NAME} GTest::GTest GTest::Main Qt5::Core)

gtest_discover_tests(${PROJECT_NAME})
