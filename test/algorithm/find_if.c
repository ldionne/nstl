/**
 * Unit tests for the @em find_if algorithm.
 *
 * @author Alexandre Girard
 */

#include <nstl/algorithm/find_if.h>

#include <seatest.h>
#include <stddef.h>

typedef nstl_bool (*Predicate) (int elem);

static nstl_bool is_odd(int i) {
    return ((i % 2) != 0);
}

NSTL_INSTANTIATE(NSTL_FIND_IF(nstl_pint, Predicate))

static nstl_bool always_false(int elem) {
    NSTL_SILENCE_UNUSED_VARIABLE_WARNING(elem);
    return nstl_false;
}

static nstl_bool always_true(int elem) {
    NSTL_SILENCE_UNUSED_VARIABLE_WARNING(elem);
    return nstl_true;
}

static void test_should_return_last_when_not_found(void) {
    int array[5] = {4, 3, 2, 1, 0};
    nstl_pint n = nstl_find_if(nstl_pint, Predicate)(array, array + 5, 
                                                        always_false);
    assert_true(n == array + 5);
    assert_int_equal(*n, 0);
}

static void test_should_return_iterator_to_found_element_when_found(void) {
    int array[5] = {0, 1, 2, 3, 4};
    nstl_pint n = nstl_find_if(nstl_pint, Predicate)
                                                (array, array + 5, is_odd);
    assert_true(n = array + 1);
    assert_int_equal(*n, 1);
}

extern void test_fixture_find_if(void) {
    test_fixture_start();

    run_test(test_should_return_last_when_not_found);
    run_test(test_should_return_iterator_to_found_element_when_found);

    test_fixture_end();
}
