/**
 * Unit tests for the @em distance algorithm.
 */

#include <nstl/algorithm/distance.h>

#include <seatest.h>


NSTL_INSTANTIATE(NSTL_DISTANCE(nstl_pint))

static void test_should_have_distance_of_0_when_same_iter(void) {
    nstl_int array[10];
    assert_true(nstl_distance(nstl_pint)(array, array) == 0);
}

static void test_should_be_number_of_elements_between_both_iters(void) {
    nstl_int array[10];
    assert_true(nstl_distance(nstl_pint)(array, array + 6) == 6);
}

extern void test_fixture_distance(void) {
    test_fixture_start();

    run_test(test_should_have_distance_of_0_when_same_iter);
    run_test(test_should_be_number_of_elements_between_both_iters);

    test_fixture_end();
}
