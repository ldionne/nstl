/**
 * Unit tests for the @em max_element algorithm.
 *
 * @author Louis Dionne
 */

#include <nstl/algorithm/max_element.h>

#include <seatest.h>


typedef nstl_bool(*BinaryPred)(int x, int y);
static nstl_bool inverse_comp(int x, int y) {
    return x > y;
}

NSTL_INSTANTIATE(NSTL_MAX_ELEMENT(nstl_pint, nstl_int))
NSTL_INSTANTIATE(NSTL_MAX_ELEMENT_CMP(nstl_pint, nstl_int, BinaryPred))

static void test_should_find_greatest_element_in_sorted_range(void) {
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint max = nstl_max_element(nstl_pint)(array, array + 10);
    assert_int_equal(*max, 9);
}

static void test_should_find_greatest_element_in_non_sorted_range(void) {
    int array[10] = {4, 5, 2, 9, 8, 3, 1, 6, 0, 7};
    nstl_pint max = nstl_max_element(nstl_pint)(array, array + 10);
    assert_int_equal(*max, 9);
}

static void test_should_find_max_element_as_determined_by_cmp_sorted(void) {
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint max = nstl_max_element_cmp(nstl_pint, BinaryPred)(array,
                                                    array + 10, inverse_comp);
    assert_int_equal(*max, 0);
}

static void test_should_find_max_element_as_determined_by_cmp(void) {
    int array[10] = {4, 5, 2, 9, 8, 3, 1, 6, 0, 7};
    nstl_pint max = nstl_max_element_cmp(nstl_pint, BinaryPred)(array,
                                                    array + 10, inverse_comp);
    assert_int_equal(*max, 0);
}

extern void test_fixture_max_element(void) {
    test_fixture_start();

    run_test(test_should_find_greatest_element_in_sorted_range);
    run_test(test_should_find_greatest_element_in_non_sorted_range);
    run_test(test_should_find_max_element_as_determined_by_cmp_sorted);
    run_test(test_should_find_max_element_as_determined_by_cmp);

    test_fixture_end();
}
