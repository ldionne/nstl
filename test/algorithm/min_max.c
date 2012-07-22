/**
 * Unit tests for the @em min and @em max algorithms.
 *
 * @author Louis Dionne
 */

#include <nstl/algorithm/max.h>
#include <nstl/algorithm/min.h>

#include <seatest.h>


typedef nstl_bool (*Compare)(nstl_int a, nstl_int b);

NSTL_INSTANTIATE(NSTL_MAX(nstl_int))
NSTL_INSTANTIATE(NSTL_MAX_CMP(nstl_int, Compare))

NSTL_INSTANTIATE(NSTL_MIN(nstl_int))
NSTL_INSTANTIATE(NSTL_MIN_CMP(nstl_int, Compare))

#define max nstl_max(nstl_int)
#define max_cmp(a, b) \
    nstl_max_cmp(nstl_int, Compare)(a, b, nstl_lt(nstl_int, nstl_int))

#define min nstl_min(nstl_int)
#define min_cmp(a, b) \
    nstl_min_cmp(nstl_int, Compare)(a, b, nstl_lt(nstl_int, nstl_int))

static void test_max_should_pick_greatest(void) {
    nstl_int a = -10, b = 10, c = 30;

    assert_int_equal(max(a, b), max_cmp(a, b));
    assert_int_equal(b, max(a, b));

    assert_int_equal(max(b, c), max_cmp(b, c));
    assert_int_equal(c, max(b, c));

    assert_int_equal(max(c, b), max_cmp(c, b));
    assert_int_equal(c, max(c, b));
}

static void test_min_should_pick_smallest(void) {
    nstl_int a = -10, b = 10, c = 30;

    assert_int_equal(min(a, b), min_cmp(a, b));
    assert_int_equal(a, min(a, b));

    assert_int_equal(min(b, c), min_cmp(b, c));
    assert_int_equal(b, min(b, c));

    assert_int_equal(min(c, b), min_cmp(c, b));
    assert_int_equal(b, min(c, b));
}

#undef max
#undef min
#undef max_cmp
#undef min_cmp

extern void test_fixture_min_max(void) {
    test_fixture_start();

    run_test(test_max_should_pick_greatest);
    run_test(test_min_should_pick_smallest);

    test_fixture_end();
}
