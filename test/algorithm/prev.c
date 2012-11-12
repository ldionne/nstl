/**
 * Unit tests for the @em prev and @em prev_n algorithms.
 */

#include <nstl/algorithm/prev.h>

#include <seatest.h>


#define Traits (self_type nstl_pint)                                        \
               (diff_traits (self_type nstl_ptrdiff_t))                     \
               (traversal_category nstl_random_access_traversal_tag)

NSTL_INSTANTIATE(NSTL_PREV(Traits))
NSTL_INSTANTIATE(NSTL_PREV_N(Traits))

#define prev nstl_prev(nstl_pint)
#define prev_n nstl_prev_n(nstl_pint)

static void test_should_return_iterator_to_prev(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint iter = array + 10;
    assert_true(prev(iter) == prev_n(iter, 1));
    assert_true(prev(iter) == array + 9);
}

static void test_should_return_iterator_to_nth_prev(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint iter = array + 10;
    assert_true(prev_n(iter, 5) == array + 5);
}

#undef prev_n
#undef prev

extern void test_fixture_prev(void) {
    test_fixture_start();

    run_test(test_should_return_iterator_to_prev);
    run_test(test_should_return_iterator_to_nth_prev);

    test_fixture_end();
}
