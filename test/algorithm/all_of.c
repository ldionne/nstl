/**
 * Unit tests for the @em all_of algorithm.
 *
 * @author Louis Dionne
 */

#include <nstl/algorithm/all_of.h>

#include <seatest.h>


typedef nstl_bool (*Predicate)(nstl_int x);

static nstl_bool return_false(nstl_int x) {
    NSTL_SILENCE_UNUSED_VARIABLE_WARNING(x);
    return nstl_false;
}

static nstl_bool return_true(nstl_int x) {
    NSTL_SILENCE_UNUSED_VARIABLE_WARNING(x);
    return nstl_true;
}

static nstl_bool not_eq_to_4(nstl_int x) {
    return x != 4;
}

NSTL_INSTANTIATE(NSTL_ALL_OF(nstl_pint, Predicate))

#define all_of nstl_all_of(nstl_pint, Predicate)

static void test_should_be_false_with_all_false_input(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert_false(all_of(array, array + 10, return_false));
}

static void test_should_be_false_when_some_false(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert_false(all_of(array, array + 10, not_eq_to_4));
}

static void test_should_be_true_with_all_true(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert_true(all_of(array, array + 10, return_true));
}

#undef all_of

extern void test_fixture_all_of(void) {
    test_fixture_start();

    run_test(test_should_be_false_with_all_false_input);
    run_test(test_should_be_false_when_some_false);
    run_test(test_should_be_true_with_all_true);

    test_fixture_end();
}
