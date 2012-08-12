/**
 * Unit tests for the @em advance algorithm.
 */

#include <nstl/algorithm/advance.h>

#include <seatest.h>


NSTL_INSTANTIATE(
    NSTL_I_ADVANCE_FORWARD(fwd_advance, nstl_pint, nstl_ptrdiff_t))
NSTL_INSTANTIATE(
    NSTL_I_ADVANCE_BIDIRECTIONAL(bidir_advance, nstl_pint, nstl_ptrdiff_t))
NSTL_INSTANTIATE(
    NSTL_I_ADVANCE_RANDOM_ACCESS(rand_advance, nstl_pint, nstl_ptrdiff_t))

static void test_should_not_advance_when_distance_is_0(void) {
    nstl_int array[10];
    nstl_pint fwd_iter = array, bidir_iter = array, rand_iter = array;
    fwd_advance(&fwd_iter, 0);
    bidir_advance(&bidir_iter, 0);
    rand_advance(&rand_iter, 0);
    assert_true(fwd_iter == bidir_iter);
    assert_true(fwd_iter == rand_iter);
    assert_true(fwd_iter == array);
}

static void test_should_advance_by_the_distance_given(void) {
    nstl_int array[10];
    nstl_pint fwd_iter = array, bidir_iter = array, rand_iter = array;
    fwd_advance(&fwd_iter, 5);
    bidir_advance(&bidir_iter, 5);
    rand_advance(&rand_iter, 5);
    assert_true(fwd_iter == bidir_iter);
    assert_true(fwd_iter == rand_iter);
    assert_true(fwd_iter == array + 5);
}

static void test_should_rewind_by_the_distance_given(void) {
    nstl_int array[10];
    nstl_pint bidir_iter = array + 10, rand_iter = array + 10;
    bidir_advance(&bidir_iter, -5);
    rand_advance(&rand_iter, -5);
    assert_true(bidir_iter == rand_iter);
    assert_true(bidir_iter == array + 5);
}

extern void test_fixture_advance(void) {
    test_fixture_start();

    run_test(test_should_not_advance_when_distance_is_0);
    run_test(test_should_advance_by_the_distance_given);
    run_test(test_should_rewind_by_the_distance_given);

    test_fixture_end();
}
