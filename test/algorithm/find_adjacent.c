/**
 * Unit tests for the @em find_adjacent and @em find_adjacent_comp algorithms.
 */

#include <nstl/algorithm/find_adjacent.h>

#include <seatest.h>


typedef nstl_bool (*Compare)(nstl_int x, nstl_int y);
NSTL_INSTANTIATE(NSTL_FIND_ADJACENT(nstl_pint, nstl_int))
NSTL_INSTANTIATE(NSTL_FIND_ADJACENT_COMP(nstl_pint, nstl_int, Compare))

#define find_adjacent nstl_find_adjacent(nstl_pint)
#define find_adjacent_comp(first, last)                                        \
    nstl_find_adjacent_comp(nstl_pint, Compare)(                               \
        first, last, nstl_eq(nstl_int, nstl_int)                               \
    )                                                                          \
/**/

static void test_should_not_find_any_when_none_equal_and_adjacent(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint found = find_adjacent(array, array + 10);
    nstl_pint found_comp = find_adjacent_comp(array, array + 10);
    assert_true(found == found_comp);
    assert_true(found == array + 10);
}

static void test_should_not_find_any_when_some_equal_but_not_adjacent(void) {
    nstl_int array[10] = {0, 99, 2, 3, 99, 5, 6, 99, 8, 99};
    nstl_pint found = find_adjacent(array, array + 10);
    nstl_pint found_comp = find_adjacent_comp(array, array + 10);
    assert_true(found == found_comp);
    assert_true(found == array + 10);
}

static void test_should_find_first_when_equal_and_adjacent(void) {
    nstl_int array[10] = {0, 1, 2, 2, 4, 5, 6, 7, 8, 9};
    nstl_pint found = find_adjacent(array, array + 10);
    nstl_pint found_comp = find_adjacent_comp(array, array + 10);
    assert_true(found == found_comp);
    assert_true(found == &array[2]);
}

static void test_should_find_first_of_all_when_many_equal_and_adjacent(void) {
    nstl_int array[10] = {0, 1, 2, 2, 4, 4, 6, 7, 8, 9};
    nstl_pint found = find_adjacent(array, array + 10);
    nstl_pint found_comp = find_adjacent_comp(array, array + 10);
    assert_true(found == found_comp);
    assert_true(found == &array[2]);
}

#undef find_adjacent_comp
#undef find_adjacent

extern void test_fixture_find_adjacent(void) {
    test_fixture_start();

    run_test(test_should_not_find_any_when_none_equal_and_adjacent);
    run_test(test_should_not_find_any_when_some_equal_but_not_adjacent);
    run_test(test_should_find_first_when_equal_and_adjacent);
    run_test(test_should_find_first_of_all_when_many_equal_and_adjacent);

    test_fixture_end();
}
