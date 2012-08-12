/**
 * Unit tests for the @em find and @em find_comp algorithms.
 */

#include <nstl/algorithm/find.h>

#include <seatest.h>


typedef nstl_bool (*Compare)(nstl_int x, nstl_int y);
NSTL_INSTANTIATE(NSTL_FIND(nstl_pint, nstl_int))
NSTL_INSTANTIATE(NSTL_FIND_COMP(nstl_pint, nstl_int, Compare))

#define find nstl_find(nstl_pint)
#define find_comp(first, last, value)                                          \
    nstl_find_comp(nstl_pint, Compare)(                                        \
        first, last, value, nstl_eq(nstl_int, nstl_int)                        \
    )                                                                          \
/**/

static void test_should_return_last_when_not_found(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint first = array, last = array + 10, iter, iter_comp;

    iter = find(first, last, -1);
    iter_comp = find_comp(first, last, -1);
    assert_true(iter == iter_comp);
    assert_true(iter == last);
}

static void test_should_return_iterator_to_found_element_when_found(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_size_t i;
    nstl_pint first = array, last = array + 10, iter, iter_comp;

    for (i = 0; i < 10; ++i) {
        iter = find(first, last, i);
        iter_comp = find_comp(first, last, i);
        assert_true(iter == iter_comp);
        assert_true(iter == first + i);
        assert_int_equal(*iter, i);
    }
}

#undef find_comp
#undef find

extern void test_fixture_find(void) {
    test_fixture_start();

    run_test(test_should_return_last_when_not_found);
    run_test(test_should_return_iterator_to_found_element_when_found);

    test_fixture_end();
}
