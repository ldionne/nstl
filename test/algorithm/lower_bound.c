/**
 * Unit tests for the @em lower_bound and @em lower_bound_cmp algorithms.
 *
 * @author Louis Dionne
 */

#include <nstl/algorithm/advance.h>
#include <nstl/algorithm/distance.h>
#include <nstl/algorithm/lower_bound.h>

#include <seatest.h>


typedef nstl_bool (*Compare)(int x, int y);

NSTL_INSTANTIATE(NSTL_INTEGRAL(ptrdiff_t))
NSTL_INSTANTIATE(NSTL_ADVANCE(nstl_pint, ptrdiff_t))
NSTL_INSTANTIATE(NSTL_DISTANCE(nstl_pint))

NSTL_INSTANTIATE(NSTL_LOWER_BOUND(nstl_pint, nstl_int))

/* Note: nstl_lower_bound_cmp is not tested because its implementation is just
 *       the same as nstl_lower_bound, with the comparator made custom.
 */
NSTL_INSTANTIATE(NSTL_LOWER_BOUND_CMP(nstl_pint, nstl_int, Compare))

static void test_returns_last_when_value_out_of_bounds(void) {
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint iter = nstl_lower_bound(nstl_pint)(array, array + 10, 20);
    assert_true(iter == array + 10);
}

static void test_returns_first_not_less_no_duplicates(void) {
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint iter = nstl_lower_bound(nstl_pint)(array, array + 10, 6);
    assert_true(iter == &array[6]);
}

static void test_returns_first_not_less_with_duplicates(void) {
    int array[10] = {0, 1, 2, 2, 4, 5, 6, 6, 7, 9};
    nstl_pint iter = nstl_lower_bound(nstl_pint)(array, array + 10, 6);
    assert_true(iter == &array[6]);
}

extern void test_fixture_lower_bound(void) {
    test_fixture_start();

    run_test(test_returns_last_when_value_out_of_bounds);
    run_test(test_returns_first_not_less_no_duplicates);
    run_test(test_returns_first_not_less_with_duplicates);

    test_fixture_end();
}
