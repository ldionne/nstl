/**
 * Unit tests for the @em adjacent_find algorithm.
 *
 * @author Louis Dionne
 */

#include <nstl/algorithm/adjacent_find.h>
#include <nstl/internal/pointer.h>
#include <nstl/internal/primitive.h>
#include <seatest.h>
#include <stdbool.h>
#include <stddef.h>


typedef int *intp;
NSTL_INSTANTIATE(NSTL_POINTER(int, intp))
NSTL_INSTANTIATE(NSTL_INT)
NSTL_INSTANTIATE(NSTL_ADJACENT_FIND(intp, int))

#define adjacent_find nstl_adjacent_find(intp, int)

static void test_should_not_find_any_when_none_equal_and_adjacent(void)
{
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    intp found = adjacent_find(array, array + 10);
    assert_true(found == array + 10);
}

static void test_should_not_find_any_when_some_equal_but_not_adjacent(void)
{
    int array[10] = {0, 99, 2, 3, 99, 5, 6, 99, 8, 99};
    intp found = adjacent_find(array, array + 10);
    assert_true(found == array + 10);
}

static void test_should_find_first_when_equal_and_adjacent(void)
{
    int array[10] = {0, 1, 2, 2, 4, 5, 6, 7, 8, 9};
    intp found = adjacent_find(array, array + 10);
    assert_true(found == &array[2]);
}

static void test_should_find_first_of_all_when_many_equal_and_adjacent(void)
{
    int array[10] = {0, 1, 2, 2, 4, 4, 6, 7, 8, 9};
    intp found = adjacent_find(array, array + 10);
    assert_true(found == &array[2]);
}

#undef adjacent_find

extern void test_fixture_adjacent_find(void)
{
    test_fixture_start();

    run_test(test_should_not_find_any_when_none_equal_and_adjacent);
    run_test(test_should_not_find_any_when_some_equal_but_not_adjacent);
    run_test(test_should_find_first_when_equal_and_adjacent);
    run_test(test_should_find_first_of_all_when_many_equal_and_adjacent);

    test_fixture_end();
}
