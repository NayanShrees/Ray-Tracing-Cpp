cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

project(Ray-Tracing VERSION 0.1)

set(TARGET RayTracing)
set(TARGET_LIB RayTracingLib)
set(UNIT_TESTS_TARGET Unit-Tests)

set(SOURCES
    ${CMAKE_SOURCE_DIR}/src/data_structures/tuples.cpp
    ${CMAKE_SOURCE_DIR}/src/game.cpp
    ${CMAKE_SOURCE_DIR}/src/main.cpp
)

add_executable(${TARGET} ${SOURCES})
add_library(${TARGET_LIB} STATIC ${SOURCES})

target_include_directories(${TARGET} PUBLIC "${CMAKE_SOURCE_DIR}/include/")
target_include_directories(${TARGET_LIB} PUBLIC "${CMAKE_SOURCE_DIR}/include/")

set(UNIT_TEST_SOURCES
    ${CMAKE_SOURCE_DIR}/tests/unit/data_structures/tuples.cpp
)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${UNIT_TESTS_TARGET} ${UNIT_TEST_SOURCES})

target_link_libraries(${UNIT_TESTS_TARGET} PUBLIC GTest::gtest_main ${TARGET_LIB})

include(GoogleTest)
gtest_discover_tests(${UNIT_TESTS_TARGET})
