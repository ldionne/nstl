/**
 * Unit tests for the @em lower_bound and @em lower_bound_comp algorithms.
 */

#include <nstl/algorithm/lower_bound.h>

#include <seatest.h>


typedef nstl_bool (*Compare)(nstl_int x, nstl_int y);
NSTL_INSTANTIATE(NSTL_LOWER_BOUND(nstl_pint, nstl_int))
NSTL_INSTANTIATE(NSTL_LOWER_BOUND_COMP(nstl_pint, nstl_int, Compare))

#define lower_bound nstl_lower_bound(nstl_pint)
#define lower_bound_comp(first, last, value)                                   \
    nstl_lower_bound_comp(nstl_pint, Compare)(                                 \
        first, last, value, nstl_lt(nstl_int, nstl_int)                        \
    )                                                                          \
/**/

static void test_returns_last_when_value_above(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint iter = lower_bound(array, array + 10, 20);
    nstl_pint comp_iter = lower_bound_comp(array, array + 10, 20);
    assert_true(iter == comp_iter);
    assert_true(iter == array + 10);
}

static void test_returns_first_when_value_under(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint iter = lower_bound(array, array + 10, -1);
    nstl_pint comp_iter = lower_bound_comp(array, array + 10, -1);
    assert_true(iter == comp_iter);
    assert_true(iter == array);
}

static void test_returns_first_that_is_not_less_in_range_wo_duplicates(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint iter = lower_bound(array, array + 10, 6);
    nstl_pint comp_iter =  lower_bound_comp(array, array + 10, 6);
    assert_true(iter == comp_iter);
    assert_true(iter == &array[6]);
}

static void test_returns_first_that_is_not_less_in_range_w_duplicates(void) {
    nstl_int array[10] = {0, 1, 2, 2, 4, 5, 6, 6, 7, 9};
    nstl_pint iter = lower_bound(array, array + 10, 6);
    nstl_pint comp_iter = lower_bound_comp(array, array + 10, 6);
    assert_true(iter == comp_iter);
    assert_true(iter == &array[6]);
}

static void test_check_for_off_by_one_at_beginning(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint iter = lower_bound(array, array + 10, 0);
    nstl_pint comp_iter = lower_bound_comp(array, array + 10, 0);
    assert_true(iter == comp_iter);
    assert_true(iter == array);
}

static void test_check_for_off_by_one_at_end(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint iter = lower_bound(array, array + 10, 9);
    nstl_pint comp_iter = lower_bound_comp(array, array + 10, 9);
    assert_true(iter == comp_iter);
    assert_true(iter == array + 9);
}

#undef lower_bound_comp
#undef lower_bound

extern void test_fixture_lower_bound(void) {
    test_fixture_start();

    run_test(test_returns_last_when_value_above);
    run_test(test_returns_first_when_value_under);
    run_test(test_returns_first_that_is_not_less_in_range_wo_duplicates);
    run_test(test_returns_first_that_is_not_less_in_range_w_duplicates);
    run_test(test_check_for_off_by_one_at_beginning);
    run_test(test_check_for_off_by_one_at_end);

    test_fixture_end();
}
