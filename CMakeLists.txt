cmake_minimum_required(VERSION 2.8)
project(c-misc)

find_package(Check REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB src ${PROJECT_SOURCE_DIR}/src)
add_library(cmisc ${src})

enable_testing()

file(GLOB tests_src ${PROJECT_SOURCE_DIR}/tests)
add_executable(tests ${tests_src})
add_test(tests)
