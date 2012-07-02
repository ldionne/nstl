/*!
 * Unit tests for the @em find algorithm.
 *
 * @author Louis Dionne
 */

#include <nstl/algorithm/find.h>
#include <nstl/internal/pointer.h>
#include <nstl/primitive.h>
#include <seatest.h>
#include <stdbool.h>
#include <stddef.h>


typedef int *intp;
NSTL_IMPLEMENT(NSTL_POINTER(int, intp))
NSTL_IMPLEMENT(NSTL_INT)

NSTL_IMPLEMENT(NSTL_FIND(intp, int))


static void test_should_return_last_when_not_found(void)
{
    int array[10];
    size_t i;
    intp first = array, last = array + 10, iter;

    for (i = 0; i < 10; ++i)
        array[i] = i;

    iter = nstl_find(intp, int)(first, last, -1);
    assert_true(iter == last);
}

static void test_should_return_iterator_to_found_element_when_found(void)
{
    int array[10];
    size_t i;
    intp first = array, last = array + 10, iter;

    for (i = 0; i < 10; ++i)
        array[i] = i;

    for (i = 0; i < 10; ++i) {
        iter = nstl_find(intp, int)(first, last, i);
        assert_true(iter == first + i);
        assert_int_equal(*iter, i);
    }
}


extern void test_fixture_find(void)
{
    test_fixture_start();

    run_test(test_should_return_last_when_not_found);
    run_test(test_should_return_iterator_to_found_element_when_found);

    test_fixture_end();
}
