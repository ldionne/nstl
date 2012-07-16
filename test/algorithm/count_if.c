/**
 * Unit tests for the @em count_if algorithm.
 *
 * @author Louis Dionne
 */

#include <nstl/algorithm/count_if.h>

#include <seatest.h>
#include <stddef.h>


typedef nstl_bool (*Predicate) (int elem);
NSTL_INSTANTIATE(NSTL_COUNT_IF(nstl_pint, Predicate))

#define count_if nstl_count_if(nstl_pint, Predicate)

static nstl_bool always_false(int elem) {
    NSTL_SILENCE_UNUSED_VARIABLE_WARNING(elem);
    return nstl_false;
}

static nstl_bool always_true(int elem) {
    NSTL_SILENCE_UNUSED_VARIABLE_WARNING(elem);
    return nstl_true;
}

static nstl_bool is_even(int n) {
    return n % 2 == 0;
}

static void test_should_count_0_if_predicate_always_false(void) {
    int array[10];
    ptrdiff_t n = count_if(array, array + 10, always_false);
    assert_true(n == 0);
}

static void test_should_count_all_if_predicate_always_true(void) {
    int array[10];
    ptrdiff_t n = count_if(array, array + 10, always_true);
    assert_true(n == 10);
}

static void test_should_count_only_those_for_which_pred_is_true(void) {
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ptrdiff_t n;

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
