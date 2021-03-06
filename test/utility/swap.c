/**
 * Unit tests for the @em swap utility function.
 */

#include <nstl/utility/swap.h>

#include <seatest.h>


NSTL_INSTANTIATE(NSTL_SWAP((self_type nstl_char)))

static void test_should_swap_both_values(void) {
    nstl_char a = 'a', b = 'b';
    nstl_swap(nstl_char)(&a, &b);
    assert_true(a == 'b');
    assert_true(b == 'a');
}

extern void test_fixture_swap(void) {
    test_fixture_start();

    run_test(test_should_swap_both_values);

    test_fixture_end();
}
