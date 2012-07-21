/**
 * Unit tests for the @em min_element algorithm.
 *
 * @author Louis Dionne
 */

#include <nstl/algorithm/min_element.h>

#include <seatest.h>


typedef nstl_bool(*BinaryPred)(int x, int y);
static nstl_bool inverse_comp(int x, int y) {
    return x > y;
}

NSTL_INSTANTIATE(NSTL_MIN_ELEMENT(nstl_pint, nstl_int))
NSTL_INSTANTIATE(NSTL_MIN_ELEMENT_CMP(nstl_pint, nstl_int, BinaryPred))

static void test_should_find_smallest_element_in_sorted_range(void) {
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint min = nstl_min_element(nstl_pint)(array, array + 10);
    assert_int_equal(*min, 0);
}

static void test_should_find_smallest_element_in_non_sorted_range(void) {
    int array[10] = {9, 4, 5, 2, 8, 3, 1, 6, 0, 7};
    nstl_pint min = nstl_min_element(nstl_pint)(array, array + 10);
    assert_int_equal(*min, 0);
}

static void test_should_find_min_element_as_determined_by_cmp_sorted(void) {
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint min = nstl_min_element_cmp(nstl_pint, BinaryPred)(array,
                                                    array + 10, inverse_comp);
    assert_int_equal(*min, 9);
}

static void test_should_find_min_element_as_determined_by_cmp(void) {
    int array[10] = {4, 5, 2, 9, 8, 3, 1, 6, 0, 7};
    nstl_pint min = nstl_min_element_cmp(nstl_pint, BinaryPred)(array,
                                                    array + 10, inverse_comp);
    assert_int_equal(*min, 9);
}

extern void test_fixture_min_element(void) {
    test_fixture_start();

    run_test(test_should_find_smallest_element_in_sorted_range);
    run_test(test_should_find_smallest_element_in_non_sorted_range);
    run_test(test_should_find_min_element_as_determined_by_cmp_sorted);
    run_test(test_should_find_min_element_as_determined_by_cmp);

    test_fixture_end();
}
