
file(
    GLOB_RECURSE
    unit_test_files
    *.[c,h]
)

include_directories(${nstl_SOURCE_DIR}/include
                    ${nstl_SOURCE_DIR}/ext/seatest/src)
link_directories(${nstl_BINARY_DIR}/test)

add_library(seatest ${nstl_SOURCE_DIR}/ext/seatest/src/seatest.c)

add_executable(
    unit-tests
    ${unit_test_files}
)

target_link_libraries(unit-tests seatest)

add_custom_target(
    run-tests
    COMMAND ./unit-tests
    DEPENDS unit-tests
    WORKING_DIRECTORY ${nstl_BINARY_DIR}/test
)
