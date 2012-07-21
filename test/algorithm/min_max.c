/**
 * Unit tests for the @em min and @em max algorithms.
 *
 * @author Louis Dionne
 */

#include <nstl/algorithm/max.h>
#include <nstl/algorithm/min.h>

#include <seatest.h>


typedef nstl_bool (*BinaryPred)(int a, int b);
static nstl_bool inverse_comp(int a, int b) {
    return a > b;
}

NSTL_INSTANTIATE(NSTL_MAX(int))
NSTL_INSTANTIATE(NSTL_MAX_CMP(int, BinaryPred))

NSTL_INSTANTIATE(NSTL_MIN(int))
NSTL_INSTANTIATE(NSTL_MIN_CMP(int, BinaryPred))


static void test_max_should_pick_greatest(void) {
    int a = -10, b = 10, c = 30;
    assert_int_equal(b, nstl_max(int)(a, b));
    assert_int_equal(c, nstl_max(int)(b, c));
    assert_int_equal(c, nstl_max(int)(c, b));
}

static void test_max_cmp_should_pick_chosen_by_predicate(void) {
    int a = -10, b = 10, c = 30;
    assert_int_equal(a, nstl_max_cmp(int, BinaryPred)(a, b, inverse_comp));
    assert_int_equal(b, nstl_max_cmp(int, BinaryPred)(b, c, inverse_comp));
    assert_int_equal(b, nstl_max_cmp(int, BinaryPred)(c, b, inverse_comp));
}

static void test_min_should_pick_smallest(void) {
    int a = -10, b = 10, c = 30;
    assert_int_equal(a, nstl_min(int)(a, b));
    assert_int_equal(b, nstl_min(int)(b, c));
    assert_int_equal(b, nstl_min(int)(c, b));
}

static void test_min_cmp_should_pick_chosen_by_predicate(void) {
    int a = -10, b = 10, c = 30;
    assert_int_equal(b, nstl_min_cmp(int, BinaryPred)(a, b, inverse_comp));
    assert_int_equal(c, nstl_min_cmp(int, BinaryPred)(b, c, inverse_comp));
    assert_int_equal(c, nstl_min_cmp(int, BinaryPred)(c, b, inverse_comp));
}

extern void test_fixture_min_max(void) {
    test_fixture_start();

    run_test(test_max_should_pick_greatest);
    run_test(test_max_cmp_should_pick_chosen_by_predicate);
    run_test(test_min_should_pick_smallest);
    run_test(test_min_cmp_should_pick_chosen_by_predicate);

    test_fixture_end();
}
