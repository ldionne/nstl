
file(
    GLOB_RECURSE
    unit_test_files
    "*.[c,h]"
)


include_directories("${nstl_SOURCE_DIR}/include")
include_directories("${nstl_SOURCE_DIR}/ext/seatest/src")
add_executable(
    unit_tests
    ${unit_test_files}
    "${nstl_SOURCE_DIR}/ext/seatest/src/seatest.c"
)
