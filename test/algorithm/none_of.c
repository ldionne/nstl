/**
 * Unit tests for the @em none_of algorithm.
 */

#include <nstl/algorithm/none_of.h>

#include <seatest.h>


typedef nstl_bool (*Predicate)(nstl_int x);
NSTL_INSTANTIATE(NSTL_NONE_OF(nstl_pint, Predicate))

#define none_of nstl_none_of(nstl_pint, Predicate)

static nstl_bool return_false(nstl_int x) {
    NSTL_SILENCE_UNUSED_VARIABLE_WARNING(x);
    return nstl_false;
}

static nstl_bool return_true(nstl_int x) {
    NSTL_SILENCE_UNUSED_VARIABLE_WARNING(x);
    return nstl_true;
}

static nstl_bool eq_to_4(nstl_int x) {
    return x == 4;
}

static void test_should_be_true_with_all_false_input(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert_true(none_of(array, array + 10, return_false));
}

static void test_should_be_false_when_some_true(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert_false(none_of(array, array + 10, eq_to_4));
}

#undef none_of

extern void test_fixture_none_of(void) {
    test_fixture_start();

    run_test(test_should_be_true_with_all_false_input);
    run_test(test_should_be_false_when_some_true);

    test_fixture_end();
}
