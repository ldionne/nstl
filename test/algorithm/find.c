/**
 * Unit tests for the @em find algorithm.
 *
 * @author Louis Dionne
 */

#include <nstl/algorithm/find.h>

#include <seatest.h>
#include <stddef.h>


NSTL_INSTANTIATE(NSTL_FIND(nstl_pint, int))

static void test_should_return_last_when_not_found(void) {
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint first = array, last = array + 10, iter;

    iter = nstl_find(nstl_pint, int)(first, last, -1);
    assert_true(iter == last);
}

static void test_should_return_iterator_to_found_element_when_found(void) {
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t i;
    nstl_pint first = array, last = array + 10, iter;

    for (i = 0; i < 10; ++i) {
        iter = nstl_find(nstl_pint, int)(first, last, i);
        assert_true(iter == first + i);
        assert_int_equal(*iter, i);
    }
}

extern void test_fixture_find(void) {
    test_fixture_start();

    run_test(test_should_return_last_when_not_found);
    run_test(test_should_return_iterator_to_found_element_when_found);

    test_fixture_end();
}
