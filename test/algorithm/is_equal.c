/**
 * Unit tests for the @em is_equal and @em is_equal_comp algorithms.
 *
 * @author Louis Dionne
 */

#include <nstl/algorithm/is_equal.h>

#include <seatest.h>


typedef nstl_bool (*Compare) (nstl_int x, nstl_int y);
NSTL_INSTANTIATE(NSTL_IS_EQUAL(nstl_pint, nstl_pint, nstl_int))
NSTL_INSTANTIATE(NSTL_IS_EQUAL_COMP(nstl_pint, nstl_pint, Compare))

#define is_equal nstl_is_equal(nstl_pint, nstl_pint)
#define is_equal_comp(first1, last1, first2)                                   \
    nstl_is_equal_comp(nstl_pint, nstl_pint, Compare)(                         \
        first1, last1, first2, nstl_eq(nstl_int, nstl_int)                     \
    )                                                                          \
/**/

static void test_should_be_equal_when_each_element_equal(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_bool is_eq = is_equal(array, array + 10, array);
    nstl_bool is_eq_comp = is_equal_comp(array, array + 10, array);
    assert_true(is_eq == is_eq_comp);
    assert_true(is_eq);
}

static void test_should_not_be_equal_when_at_least_one_elem_differs(void) {
    nstl_int array1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_int array2[10] = {0, 1, 2, 4, 4, 5, 6, 7, 8, 9};
    nstl_bool is_eq = is_equal(array1, array1 + 10, array2);
    nstl_bool is_eq_comp = is_equal_comp(array1, array1 + 10, array2);
    assert_true(is_eq == is_eq_comp);
    assert_false(is_eq);
}

#undef is_equal_comp
#undef is_equal

extern void test_fixture_is_equal(void) {
    test_fixture_start();

    run_test(test_should_be_equal_when_each_element_equal);
    run_test(test_should_not_be_equal_when_at_least_one_elem_differs);

    test_fixture_end();
}
