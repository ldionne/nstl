/**
 * Unit tests for the @em count algorithm.
 *
 * @author Louis Dionne
 */

#include <nstl/algorithm/count.h>

#include <seatest.h>
#include <stddef.h>


NSTL_INSTANTIATE(NSTL_COUNT(nstl_pint, nstl_int))

static void test_should_count_0_if_none_is_equal(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ptrdiff_t n = nstl_count(nstl_pint)(array, array + 10, -1);
    assert_true(n == 0);
}

static void test_should_count_all_occurrences_of_equal_values(void) {
    nstl_int array[10] = {0, 1, 4, 3, 4, 5, 4, 4, 8, 4};
    ptrdiff_t n = nstl_count(nstl_pint)(array, array + 10, 4);
    assert_true(n == 5);
}

extern void test_fixture_count(void) {
    test_fixture_start();

    run_test(test_should_count_0_if_none_is_equal);
    run_test(test_should_count_all_occurrences_of_equal_values);

    test_fixture_end();
}
