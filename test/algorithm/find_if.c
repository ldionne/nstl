/**
 * Unit tests for the @em find_if algorithm.
 */

#include <nstl/algorithm/find_if.h>

#include <seatest.h>


typedef nstl_bool (*Predicate) (nstl_int elem);
NSTL_INSTANTIATE(NSTL_FIND_IF(nstl_pint, Predicate))

#define find_if nstl_find_if(nstl_pint, Predicate)

static nstl_bool is_odd(nstl_int i) {
    return i % 2 != 0;
}

static nstl_bool always_false(nstl_int elem) {
    NSTL_SILENCE_UNUSED_VARIABLE_WARNING(elem);
    return nstl_false;
}

static void test_should_return_last_when_not_found(void) {
    nstl_int array[10];
    nstl_pint it = find_if(array, array + 10, always_false);
    assert_true(it == array + 10);
}

static void test_should_return_iterator_to_found_element_when_found(void) {
    nstl_int array[5] = {0, 1, 2, 3, 4};
    nstl_pint it = find_if(array, array + 5, is_odd);
    assert_true(it == array + 1);
    assert_int_equal(*it, 1);
}

#undef find_if

extern void test_fixture_find_if(void) {
    test_fixture_start();

    run_test(test_should_return_last_when_not_found);
    run_test(test_should_return_iterator_to_found_element_when_found);

    test_fixture_end();
}
