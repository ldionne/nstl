/**
 * Unit tests for the @em binary_search and @em binary_search_comp algorithms.
 *
 * @author Louis Dionne
 */

#include <nstl/algorithm/advance.h>
#include <nstl/algorithm/binary_search.h>
#include <nstl/algorithm/distance.h>
#include <nstl/algorithm/lower_bound.h>

#include <seatest.h>


typedef nstl_bool (*Compare)(nstl_int x, nstl_int y);

NSTL_INSTANTIATE(NSTL_ADVANCE(nstl_pint, nstl_ptrdiff_t))
NSTL_INSTANTIATE(NSTL_DISTANCE(nstl_pint))
NSTL_INSTANTIATE(NSTL_LOWER_BOUND(nstl_pint, nstl_int))
NSTL_INSTANTIATE(NSTL_LOWER_BOUND_COMP(nstl_pint, nstl_int, Compare))

NSTL_INSTANTIATE(NSTL_BINARY_SEARCH(nstl_pint, nstl_int))
NSTL_INSTANTIATE(NSTL_BINARY_SEARCH_COMP(nstl_pint, nstl_int, Compare))

#define binary_search nstl_binary_search(nstl_pint)
#define binary_search_comp(first, last, value)                                 \
    nstl_binary_search_comp(nstl_pint, Compare)(                               \
        first, last, value, nstl_lt(nstl_int, nstl_int)                        \
    )                                                                          \
/**/

static void test_should_return_false_when_not_contained(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_bool found = binary_search(array, array + 10, 20);
    nstl_bool found_comp = binary_search_comp(array, array + 10, 20);
    assert_true(found == found_comp);
    assert_false(found);
}

static void test_should_return_true_when_contained_no_duplicates(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_bool found = binary_search(array, array + 10, 6);
    nstl_bool found_comp = binary_search_comp(array, array + 10, 6);
    assert_true(found == found_comp);
    assert_true(found);
}

static void test_should_return_true_when_contained_with_duplicates(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 6, 8, 9};
    nstl_bool found = binary_search(array, array + 10, 6);
    nstl_bool found_comp = binary_search_comp(array, array + 10, 6);
    assert_true(found == found_comp);
    assert_true(found);
}

#undef binary_search_comp
#undef binary_search

extern void test_fixture_binary_search(void) {
    test_fixture_start();

    run_test(test_should_return_false_when_not_contained);
    run_test(test_should_return_true_when_contained_no_duplicates);
    run_test(test_should_return_true_when_contained_with_duplicates);

    test_fixture_end();
}
