/**
 * Unit tests for the @em count_if algorithm.
 */

#include <nstl/algorithm/count_if.h>

#include <seatest.h>


typedef nstl_bool (*Predicate) (nstl_int elem);
NSTL_INSTANTIATE(NSTL_COUNT_IF(nstl_pint, Predicate))

#define count_if nstl_count_if(nstl_pint, Predicate)

static nstl_bool always_false(nstl_int elem) {
    NSTL_SILENCE_UNUSED_VARIABLE_WARNING(elem);
    return nstl_false;
}

static nstl_bool always_true(nstl_int elem) {
    NSTL_SILENCE_UNUSED_VARIABLE_WARNING(elem);
    return nstl_true;
}

static nstl_bool is_even(nstl_int n) {
    return n % 2 == 0;
}

static void test_should_count_0_if_predicate_always_false(void) {
    nstl_int array[10];
    nstl_ptrdiff_t n = count_if(array, array + 10, always_false);
    assert_true(n == 0);
}

static void test_should_count_all_if_predicate_always_true(void) {
    nstl_int array[10];
    nstl_ptrdiff_t n = count_if(array, array + 10, always_true);
    assert_true(n == 10);
}

static void test_should_count_only_those_for_which_pred_is_true(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_ptrdiff_t n;

    n = count_if(array, array + 10, is_even);
    assert_true(n == 5);
}

#undef count_if

extern void test_fixture_count_if(void) {
    test_fixture_start();

    run_test(test_should_count_0_if_predicate_always_false);
    run_test(test_should_count_all_if_predicate_always_true);
    run_test(test_should_count_only_those_for_which_pred_is_true);

    test_fixture_end();
}
