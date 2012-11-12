/**
 * Unit tests for the @em min_element and @em min_element_comp algorithms.
 */

#include <nstl/algorithm/min_element.h>

#include <seatest.h>


#define Traits (self_type nstl_pint) (value_traits (self_type nstl_int))

typedef nstl_bool (*Compare)(nstl_int x, nstl_int y);
NSTL_INSTANTIATE(NSTL_MIN_ELEMENT(Traits))
NSTL_INSTANTIATE(NSTL_MIN_ELEMENT_COMP(Traits, Compare))

#define min_element nstl_min_element(nstl_pint)
#define min_element_comp(first, last)                                          \
    nstl_min_element_comp(nstl_pint, Compare)(                                 \
        first, last, nstl_lt(nstl_int, nstl_int)                               \
    )                                                                          \
/**/

static void test_should_find_smallest_element_in_sorted_range(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint min = min_element(array, array + 10);
    nstl_pint min_comp = min_element_comp(array, array + 10);
    assert_true(min == min_comp);
    assert_int_equal(*min, 0);
}

static void test_should_find_smallest_element_in_non_sorted_range(void) {
    nstl_int array[10] = {9, 4, 5, 2, 8, 3, 1, 6, 0, 7};
    nstl_pint min = min_element(array, array + 10);
    nstl_pint min_comp = min_element_comp(array, array + 10);
    assert_true(min == min_comp);
    assert_int_equal(*min, 0);
}

#undef min_element_comp
#undef min_element

extern void test_fixture_min_element(void) {
    test_fixture_start();

    run_test(test_should_find_smallest_element_in_sorted_range);
    run_test(test_should_find_smallest_element_in_non_sorted_range);

    test_fixture_end();
}
