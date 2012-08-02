/**
 * Unit tests for the @em swap algorithm.
 */

#include <nstl/algorithm/swap.h>

#include <seatest.h>


NSTL_INSTANTIATE(NSTL_SWAP(nstl_char, nstl_char))

static void test_should_swap_both_values(void) {
    nstl_char a = 'a', b = 'b';
    nstl_swap(nstl_char, nstl_char)(&a, &b);
    assert_true(a == 'b');
    assert_true(b == 'a');
}

extern void test_fixture_swap(void) {
    test_fixture_start();

    run_test(test_should_swap_both_values);

    test_fixture_end();
}
