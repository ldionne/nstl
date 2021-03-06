/**
 * Unit tests for the @em max_element and @em max_element_comp algorithms.
 */

#include <nstl/algorithm/max_element.h>

#include <seatest.h>


#define Traits (self_type nstl_pint) (value_traits (self_type nstl_int))

typedef nstl_bool (*Compare)(nstl_int x, nstl_int y);
NSTL_INSTANTIATE(NSTL_MAX_ELEMENT(Traits))
NSTL_INSTANTIATE(NSTL_MAX_ELEMENT_COMP(Traits, Compare))

#define max_element nstl_max_element(nstl_pint)
#define max_element_comp(first, last)                                          \
    nstl_max_element_comp(nstl_pint, Compare)(                                 \
        first, last, nstl_lt(nstl_int, nstl_int)                               \
    )                                                                          \
/**/

static void test_should_find_greatest_element_in_sorted_range(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint max = max_element(array, array + 10);
    nstl_pint max_comp = max_element_comp(array, array + 10);
    assert_true(max == max_comp);
    assert_int_equal(*max, 9);
}

static void test_should_find_greatest_element_in_non_sorted_range(void) {
    nstl_int array[10] = {4, 5, 2, 9, 8, 3, 1, 6, 0, 7};
    nstl_pint max = max_element(array, array + 10);
    nstl_pint max_comp = max_element_comp(array, array + 10);
    assert_true(max == max_comp);
    assert_int_equal(*max, 9);
}

#undef max_element_comp
#undef max_element

extern void test_fixture_max_element(void) {
    test_fixture_start();

    run_test(test_should_find_greatest_element_in_sorted_range);
    run_test(test_should_find_greatest_element_in_non_sorted_range);

    test_fixture_end();
}
