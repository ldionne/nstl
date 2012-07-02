/*!
 * Unit tests for the @em for_each algorithm.
 *
 * @author Louis Dionne
 */

#include <nstl/algorithm/for_each.h>
#include <nstl/internal/pointer.h>
#include <seatest.h>
#include <stdbool.h>
#include <stddef.h>


typedef int *intp;
NSTL_IMPLEMENT(NSTL_POINTER(int, intp))

typedef void (*callback_type) (int elem);
NSTL_IMPLEMENT(NSTL_FOR_EACH(intp, callback_type))

#define for_each nstl_for_each(intp, callback_type)


/*!
 * Global structure used to collect information when a test is run.
 */
struct {
    bool was_called;
    size_t elements_processed;
    int first_elem;
    int last_elem;
} test_info;

/*!
 * Function called at the beginning of each test. It resets the information
 * gathered during the last test so the tests are independent.
 */
static void set_up(void)
{
    test_info.was_called = false;
    test_info.elements_processed = 0;
    test_info.first_elem = test_info.last_elem = -1;
}

/*!
 * Function called on each element within a range during the tests. It saves
 * information to the gloval test_info structure.
 */
static void func(int elem)
{
    if (!test_info.was_called)
        test_info.first_elem = elem;
    test_info.last_elem = elem;
    test_info.was_called = true;
    test_info.elements_processed++;
}

static void should_return_function(void)
{
    int container[10];
    size_t i;
    callback_type f;
    for(i = 0; i < 10; ++i)
        container[i] = i;

    f = for_each(container, container + 10, func);
    assert_true(f == func);
}

static void should_process_all_elements(void)
{
    int container[10];
    size_t i;
    for(i = 0; i < 10; ++i)
        container[i] = i;

    for_each(container, container + 10, func);
    assert_int_equal(test_info.elements_processed, 10);
}

static void should_not_be_called_when_range_is_empty(void)
{
    int container[10];

    for_each(container, container, func);
    assert_false(test_info.was_called);
}

static void should_process_elements_in_right_order(void)
{
    int container[10];
    size_t i;
    for(i = 0; i < 10; ++i)
        container[i] = i;

    for_each(container, container + 10, func);
    assert_int_equal(test_info.first_elem, 0);
    assert_int_equal(test_info.last_elem, 9);
}

#undef for_each

extern void test_fixture_for_each(void)
{
    test_fixture_start();
    fixture_setup(set_up);

    run_test(should_return_function);
    run_test(should_process_all_elements);
    run_test(should_not_be_called_when_range_is_empty);
    run_test(should_process_elements_in_right_order);

    test_fixture_end();
}
