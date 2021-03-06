/**
 * Unit tests for the @em all_of algorithm.
 */

#include <nstl/algorithm/all_of.h>

#include <seatest.h>


typedef nstl_bool (*Predicate)(nstl_int x);
#define Default (self_type nstl_pint)


NSTL_INSTANTIATE(NSTL_ALL_OF_NAMED(def_all_of, Default, Predicate))

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

static void test_should_be_false_with_all_false_input(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert_false(def_all_of(array, array + 10, return_false));
}

static void test_should_be_false_when_some_false(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert_false(def_all_of(array, array + 10, not_eq_to_4));
}

static void test_should_be_true_with_all_true(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert_true(def_all_of(array, array + 10, return_true));
}

extern void test_fixture_all_of(void) {
    test_fixture_start();

    run_test(test_should_be_false_with_all_false_input);
    run_test(test_should_be_false_when_some_false);
    run_test(test_should_be_true_with_all_true);

    test_fixture_end();
}
