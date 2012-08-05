/**
 * Unit tests for the relational operators.
 */

#include <nstl/utility/relational_operators.h>

#include <seatest.h>


typedef int test_int;

static nstl_bool nstl_lt(test_int, test_int)(test_int a, test_int b) {
    return a < b;
}

static nstl_bool nstl_eq(test_int, test_int)(test_int a, test_int b) {
    return a == b;
}

NSTL_INSTANTIATE(NSTL_RELATIONAL_OPERATORS(test_int))

static void should_implement_ne_correctly(void) {
    test_int a = 0, b = 1;
    assert_true(nstl_ne(test_int, test_int)(a, b));

    a = b;
    assert_false(nstl_ne(test_int, test_int)(a, b));
}

static void should_implement_le_correctly(void) {
    test_int a = 0, b = 1;
    assert_true(nstl_le(test_int, test_int)(a, b));
    assert_false(nstl_le(test_int, test_int)(b, a));

    a = b;
    assert_true(nstl_le(test_int, test_int)(a, b));
}

static void should_implement_ge_correctly(void) {
    test_int a = 0, b = 1;
    assert_true(nstl_ge(test_int, test_int)(b, a));
    assert_false(nstl_ge(test_int, test_int)(a, b));

    a = b;
    assert_true(nstl_ge(test_int, test_int)(a, b));
}

static void should_implement_gt_correctly(void) {
    test_int a = 0, b = 1;
    assert_true(nstl_gt(test_int, test_int)(b, a));
    assert_false(nstl_gt(test_int, test_int)(a, b));

    a = b;
    assert_false(nstl_gt(test_int, test_int)(a, b));
    assert_false(nstl_gt(test_int, test_int)(b, a));
}


extern void test_fixture_relational_operators(void) {
    test_fixture_start();

    run_test(should_implement_ne_correctly);
    run_test(should_implement_le_correctly);
    run_test(should_implement_ge_correctly);
    run_test(should_implement_gt_correctly);

    test_fixture_end();
}
