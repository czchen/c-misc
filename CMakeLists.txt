cmake_minimum_required(VERSION 2.8)
project(c-misc)

find_package(PkgConfig)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB src ${PROJECT_SOURCE_DIR}/src/*)
add_library(cmisc ${src})

pkg_check_modules(CHECK check)
if ("${CHECK_FOUND}")
    enable_testing()

    add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})

    find_program(VALGRIND valgrind)

    include_directories(
        ${CHECK_INCLUDE_DIRS}
    )

    file(GLOB tests_src ${PROJECT_SOURCE_DIR}/tests/*)

    foreach(test_src ${tests_src})
        get_filename_component(test_name ${test_src} NAME_WE)
        add_executable(${test_name} ${test_src})
        add_dependencies(check ${test_name})
        # FIXME: Why pthread is not in ${CHECK_LIBRARIES}?
        target_link_libraries(${test_name} cmisc ${CHECK_LIBRARIES} pthread)

        add_test(${test_name} ${test_name})

        if (VALGRIND)
            add_test("valgrind-${test_name}" ${VALGRIND} --error-exitcode=255 --leak-check=full --suppressions=${PROJECT_SOURCE_DIR}/valgrind.supp ${PROJECT_BINARY_DIR}/${test_name})
        endif()
    endforeach()
endif()
