/**
 * Unit tests for the @em advance algorithm.
 *
 * @author Louis Dionne
 */

#include <nstl/algorithm/advance.h>

#include <seatest.h>


NSTL_INSTANTIATE(NSTL_INTEGRAL(ptrdiff_t))
NSTL_INSTANTIATE(NSTL_ADVANCE(nstl_pint, ptrdiff_t))

static void test_should_not_advance_when_distance_is_0(void) {
    int array[10];
    nstl_pint iter = array;
    nstl_advance(nstl_pint, ptrdiff_t)(&iter, 0);
    assert_true(iter == array);
}

static void test_should_advance_by_the_distance_given(void) {
    int array[10];
    nstl_pint iter = array;
    nstl_advance(nstl_pint, ptrdiff_t)(&iter, 5);
    assert_true(iter == array + 5);
}

extern void test_fixture_advance(void) {
    test_fixture_start();

    run_test(test_should_not_advance_when_distance_is_0);
    run_test(test_should_advance_by_the_distance_given);

    test_fixture_end();
}
