/**
 * Unit tests for the @em upper_bound and @em upper_bound_comp algorithms.
 *
 * @author Louis Dionne
 */

#include <nstl/algorithm/upper_bound.h>

#include <seatest.h>


typedef nstl_bool (*Compare)(nstl_int x, nstl_int y);

NSTL_INSTANTIATE(NSTL_UPPER_BOUND(nstl_pint, nstl_int))
NSTL_INSTANTIATE(NSTL_UPPER_BOUND_COMP(nstl_pint, nstl_int, Compare))

#define upper_bound nstl_upper_bound(nstl_pint)
#define upper_bound_comp(first, last, value)                                   \
    nstl_upper_bound_comp(nstl_pint, Compare)(                                 \
        first, last, value, nstl_lt(nstl_int, nstl_int)                        \
    )                                                                          \
/**/

static void test_returns_last_when_value_out_of_bounds(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint iter = upper_bound(array, array + 10, 20);
    nstl_pint comp_iter = upper_bound_comp(array, array + 10, 20);
    assert_true(iter == comp_iter);
    assert_true(iter == array + 10);
}

static void test_returns_first_greater_no_duplicates(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint iter = upper_bound(array, array + 10, 6);
    nstl_pint comp_iter =  upper_bound_comp(array, array + 10, 6);
    assert_true(iter == comp_iter);
    assert_true(iter == &array[7]);
}

static void test_returns_first_greater_with_duplicates(void) {
    nstl_int array[10] = {0, 1, 2, 2, 4, 5, 6, 6, 7, 9};
    nstl_pint iter = upper_bound(array, array + 10, 6);
    nstl_pint comp_iter = upper_bound_comp(array, array + 10, 6);
    assert_true(iter == comp_iter);
    assert_true(iter == &array[8]);
}

#undef upper_bound_comp
#undef upper_bound

extern void test_fixture_upper_bound(void) {
    test_fixture_start();

    run_test(test_returns_last_when_value_out_of_bounds);
    run_test(test_returns_first_greater_no_duplicates);
    run_test(test_returns_first_greater_with_duplicates);

    test_fixture_end();
}
