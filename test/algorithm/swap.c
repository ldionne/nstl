/**
 * Unit tests for the @em swap algorithm.
 *
 * @author Louis Dionne
 */

#include <nstl/algorithm/swap.h>

#include <seatest.h>


NSTL_INSTANTIATE(NSTL_SWAP(char, char))

static void test_should_swap_both_values(void) {
    char a = 'a', b = 'b';
    nstl_swap(char, char)(&a, &b);
    assert_true(a == 'b');
    assert_true(b == 'a');
}

extern void test_fixture_swap(void) {
    test_fixture_start();

    run_test(test_should_swap_both_values);

    test_fixture_end();
}
