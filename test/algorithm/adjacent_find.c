/**
 * Unit tests for the @em adjacent_find and @em adjacent_find_comp algorithms.
 *
 * @author Louis Dionne
 */

#include <nstl/algorithm/adjacent_find.h>

#include <seatest.h>


typedef nstl_bool (*Compare)(nstl_int x, nstl_int y);

NSTL_INSTANTIATE(NSTL_ADJACENT_FIND(nstl_pint, nstl_int))
NSTL_INSTANTIATE(NSTL_ADJACENT_FIND_COMP(nstl_pint, nstl_int, Compare))

#define adjacent_find nstl_adjacent_find(nstl_pint)
#define adjacent_find_comp(first, last)                                        \
    nstl_adjacent_find_comp(nstl_pint, Compare)(                               \
        first, last, nstl_eq(nstl_int, nstl_int)                               \
    )                                                                          \
/**/

static void test_should_not_find_any_when_none_equal_and_adjacent(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint found = adjacent_find(array, array + 10);
    nstl_pint found_comp = adjacent_find_comp(array, array + 10);
    assert_true(found == found_comp);
    assert_true(found == array + 10);
}

static void test_should_not_find_any_when_some_equal_but_not_adjacent(void) {
    nstl_int array[10] = {0, 99, 2, 3, 99, 5, 6, 99, 8, 99};
    nstl_pint found = adjacent_find(array, array + 10);
    nstl_pint found_comp = adjacent_find_comp(array, array + 10);
    assert_true(found == found_comp);
    assert_true(found == array + 10);
}

static void test_should_find_first_when_equal_and_adjacent(void) {
    nstl_int array[10] = {0, 1, 2, 2, 4, 5, 6, 7, 8, 9};
    nstl_pint found = adjacent_find(array, array + 10);
    nstl_pint found_comp = adjacent_find_comp(array, array + 10);
    assert_true(found == found_comp);
    assert_true(found == &array[2]);
}

static void test_should_find_first_of_all_when_many_equal_and_adjacent(void) {
    nstl_int array[10] = {0, 1, 2, 2, 4, 4, 6, 7, 8, 9};
    nstl_pint found = adjacent_find(array, array + 10);
    nstl_pint found_comp = adjacent_find_comp(array, array + 10);
    assert_true(found == found_comp);
    assert_true(found == &array[2]);
}

#undef adjacent_find_comp
#undef adjacent_find

extern void test_fixture_adjacent_find(void) {
    test_fixture_start();

    run_test(test_should_not_find_any_when_none_equal_and_adjacent);
    run_test(test_should_not_find_any_when_some_equal_but_not_adjacent);
    run_test(test_should_find_first_when_equal_and_adjacent);
    run_test(test_should_find_first_of_all_when_many_equal_and_adjacent);

    test_fixture_end();
}
