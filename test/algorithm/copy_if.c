/**
 * Unit tests for the @em copy_if algorithm.
 */

#include <nstl/algorithm/copy_if.h>

#include <seatest.h>


typedef nstl_bool (*Predicate)(nstl_int x);
NSTL_INSTANTIATE(NSTL_COPY_IF(nstl_pint, nstl_pint, Predicate))

#define copy_if nstl_copy_if(nstl_pint, nstl_pint, Predicate)

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

static void test_should_return_one_past_last_in_dest_range(void) {
    nstl_int source[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_int dest[10];
    nstl_pint it = copy_if(source, source + 10, dest, always_true);
    assert_true(it == dest + 10);
}

static void test_should_copy_only_elements_for_which_pred_is_true(void) {
    nstl_int source[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_int dest[5] = {0, 0, 0, 0, 0};
    nstl_int expected[5] = {0, 2, 4, 6, 8};
    nstl_pint it = copy_if(source, source + 10, dest, is_even);
    nstl_size_t i;

    assert_true(it == dest + 5);
    for (i = 0; i < 5; ++i) {
        assert_true(dest[i] == expected[i]);
    }
}

static void test_should_copy_everything_if_always_true(void) {
    nstl_int source[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_int dest[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    nstl_pint it = copy_if(source, source + 10, dest, always_true);
    nstl_size_t i;

    assert_true(it == dest + 10);
    for (i = 0; i < 10; ++i) {
        assert_true(dest[i] == source[i]);
    }
}

static void test_should_copy_nothing_if_always_false(void) {
    nstl_int source[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_int dest[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    nstl_pint it = copy_if(source, source + 10, dest, always_false);
    nstl_size_t i;

    assert_true(it == dest);
    for (i = 0; i < 10; ++i) {
        assert_true(dest[i] == 0);
    }
}

#undef copy_if

extern void test_fixture_copy_if(void) {
    test_fixture_start();

    run_test(test_should_return_one_past_last_in_dest_range);
    run_test(test_should_copy_only_elements_for_which_pred_is_true);
    run_test(test_should_copy_everything_if_always_true);
    run_test(test_should_copy_nothing_if_always_false);

    test_fixture_end();
}
