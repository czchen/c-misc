cmake_minimum_required(VERSION 2.8)
project(c-misc)

find_package(PkgConfig)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB src ${PROJECT_SOURCE_DIR}/src/*)
add_library(cmisc ${src})

pkg_check_modules(CHECK check)
if ("${CHECK_FOUND}")
    enable_testing()

    file(GLOB tests_src ${PROJECT_SOURCE_DIR}/tests/*)

    foreach(test_src ${tests_src})
        get_filename_component(test_name ${test_src} NAME_WE)
        add_executable(${test_name} ${test_src})
        message(WARNING ${CHECK_LIBRARIES})
        target_link_libraries(${test_name} cmisc ${CHECK_LIBRARIES})

        add_test(${test_name} ${test_name})
    endforeach()
endif()
