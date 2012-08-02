/**
 * Unit tests for the @em max and @em max_comp algorithms.
 */

#include <nstl/algorithm/max.h>

#include <seatest.h>


typedef nstl_bool (*Compare)(nstl_int a, nstl_int b);
NSTL_INSTANTIATE(NSTL_MAX(nstl_int))
NSTL_INSTANTIATE(NSTL_MAX_COMP(nstl_int, Compare))

#define max nstl_max(nstl_int)
#define max_comp(a, b) \
    nstl_max_comp(nstl_int, Compare)(a, b, nstl_lt(nstl_int, nstl_int))

static void test_should_pick_greatest(void) {
    nstl_int a = -10, b = 10, c = 30;

    assert_int_equal(max(a, b), max_comp(a, b));
    assert_int_equal(b, max(a, b));

    assert_int_equal(max(b, c), max_comp(b, c));
    assert_int_equal(c, max(b, c));

    assert_int_equal(max(c, b), max_comp(c, b));
    assert_int_equal(c, max(c, b));
}

#undef max_comp
#undef max

extern void test_fixture_max(void) {
    test_fixture_start();

    run_test(test_should_pick_greatest);

    test_fixture_end();
}
