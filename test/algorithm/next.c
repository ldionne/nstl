/**
 * Unit tests for the @em next and @em next_n algorithms.
 */

#include <nstl/algorithm/next.h>

#include <seatest.h>


NSTL_INSTANTIATE(NSTL_NEXT(nstl_pint))
NSTL_INSTANTIATE(NSTL_NEXT_N(nstl_pint, nstl_ptrdiff_t))

#define next nstl_next(nstl_pint)
#define next_n nstl_next_n(nstl_pint, nstl_ptrdiff_t)

static void test_should_return_iterator_to_next(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint iter = array;
    assert_true(next(iter) == next_n(iter, 1));
    assert_true(next(iter) == array + 1);
}

static void test_should_return_iterator_to_nth_next(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint iter = array;
    assert_true(next_n(iter, 5) == array + 5);
}

#undef next_n
#undef next

extern void test_fixture_next(void) {
    test_fixture_start();

    run_test(test_should_return_iterator_to_next);
    run_test(test_should_return_iterator_to_nth_next);

    test_fixture_end();
}
