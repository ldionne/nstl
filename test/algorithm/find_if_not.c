/**
 * Unit tests for the @em find_if_not algorithm.
 */

#include <nstl/algorithm/find_if_not.h>

#include <seatest.h>


typedef nstl_bool (*Predicate)(nstl_int x);
NSTL_INSTANTIATE(NSTL_FIND_IF_NOT((self_type nstl_pint), Predicate))

#define find_if_not nstl_find_if_not(nstl_pint, Predicate)

static nstl_bool always_true(nstl_int x) {
    NSTL_SILENCE_UNUSED_VARIABLE_WARNING(x);
    return nstl_true;
}

static nstl_bool neq_to_4(nstl_int x) {
    return x != 4;
}

static void test_should_return_last_when_pred_always_true(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert_true(find_if_not(array, array + 10, always_true) == array + 10);
}

static void test_should_find_when_inverse_of_pred_is_true(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert_true(find_if_not(array, array + 10, neq_to_4) == array + 4);
}

#undef find_if_not

extern void test_fixture_find_if_not(void) {
    test_fixture_start();

    run_test(test_should_return_last_when_pred_always_true);
    run_test(test_should_find_when_inverse_of_pred_is_true);

    test_fixture_end();
}
