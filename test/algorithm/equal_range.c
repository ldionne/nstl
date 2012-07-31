/**
 * Unit tests for the @em equal_range and @em equal_range_comp algorithms.
 *
 * @author Louis Dionne
 */

#include <nstl/algorithm/equal_range.h>
#include <nstl/pair.h>

#include <seatest.h>


typedef nstl_bool (*Compare)(nstl_int x, nstl_int y);
NSTL_INSTANTIATE(NSTL_PAIR(nstl_pint, nstl_pint))
NSTL_INSTANTIATE(NSTL_EQUAL_RANGE(nstl_pint, nstl_int))
NSTL_INSTANTIATE(NSTL_EQUAL_RANGE_COMP(nstl_pint, nstl_int, Compare))

#define equal_range nstl_equal_range(nstl_pint)
#define equal_range_comp(first, last, value)                                   \
    nstl_equal_range_comp(nstl_pint, Compare)(                                 \
        first, last, value, nstl_lt(nstl_int, nstl_int)                        \
    )                                                                          \
/**/
#define pair nstl_pair(nstl_pint, nstl_pint)

static void test_should_return_last_if_value_greater_than_all(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    pair iter = equal_range(array, array + 10, 20);
    pair comp_iter = equal_range_comp(array, array + 10, 20);
    assert_true(nstl_eq(pair, pair)(iter, comp_iter));
    assert_true(iter.first == iter.second);
    assert_true(iter.first == array + 10);
}

static void test_should_return_nearest_greater_than_value_if_not_found(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    pair iter = equal_range(array, array + 10, 5);
    pair comp_iter = equal_range_comp(array, array + 10, 5);
    assert_true(nstl_eq(pair, pair)(iter, comp_iter));
    assert_true(iter.first == iter.second);
    assert_true(iter.first == array + 5);
}

static void test_should_return_bounds_even_when_just_1(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    pair iter = equal_range(array, array + 10, 5);
    pair comp_iter = equal_range_comp(array, array + 10, 5);
    assert_true(nstl_eq(pair, pair)(iter, comp_iter));
    assert_true(iter.first == array + 5);
    assert_true(iter.second == array + 6);
}

static void test_should_return_bounds_even_when_just_1_off_by_one1(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    pair iter = equal_range(array, array + 10, 0);
    pair comp_iter = equal_range_comp(array, array + 10, 0);
    assert_true(nstl_eq(pair, pair)(iter, comp_iter));
    assert_true(iter.first == array);
    assert_true(iter.second == array + 1);
}

static void test_should_return_bounds_even_when_just_1_off_by_one2(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    pair iter = equal_range(array, array + 10, 9);
    pair comp_iter = equal_range_comp(array, array + 10, 9);
    assert_true(nstl_eq(pair, pair)(iter, comp_iter));
    assert_true(iter.first == array + 9);
    assert_true(iter.second == array + 10);
}

static void test_should_return_bounds_of_largest_subrange(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 5, 5, 8, 9};
    pair iter = equal_range(array, array + 10, 5);
    pair comp_iter = equal_range_comp(array, array + 10, 5);
    assert_true(nstl_eq(pair, pair)(iter, comp_iter));
    assert_true(iter.first == array + 5);
    assert_true(iter.second == array + 8);
}

static void test_should_return_bounds_of_largest_subrange_off_by_one1(void) {
    nstl_int array[10] = {0, 0, 0, 3, 4, 5, 6, 7, 8, 9};
    pair iter = equal_range(array, array + 10, 0);
    pair comp_iter = equal_range_comp(array, array + 10, 0);
    assert_true(nstl_eq(pair, pair)(iter, comp_iter));
    assert_true(iter.first == array);
    assert_true(iter.second == array + 3);
}

static void test_should_return_bounds_of_largest_subrange_off_by_one2(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 9, 9, 9};
    pair iter = equal_range(array, array + 10, 9);
    pair comp_iter = equal_range_comp(array, array + 10, 9);
    assert_true(nstl_eq(pair, pair)(iter, comp_iter));
    assert_true(iter.first == array + 7);
    assert_true(iter.second == array + 10);
}

#undef pair
#undef equal_range_comp
#undef equal_range

extern void test_fixture_equal_range(void) {
    test_fixture_start();

    run_test(test_should_return_last_if_value_greater_than_all);
    run_test(test_should_return_nearest_greater_than_value_if_not_found);
    run_test(test_should_return_bounds_even_when_just_1);
    run_test(test_should_return_bounds_even_when_just_1_off_by_one1);
    run_test(test_should_return_bounds_even_when_just_1_off_by_one2);
    run_test(test_should_return_bounds_of_largest_subrange);
    run_test(test_should_return_bounds_of_largest_subrange_off_by_one1);
    run_test(test_should_return_bounds_of_largest_subrange_off_by_one2);

    test_fixture_end();
}
