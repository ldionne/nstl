/**
 * Unit tests for the @em for_each algorithm.
 */

#include <nstl/algorithm/for_each.h>

#include <seatest.h>


typedef void (*Function) (nstl_int elem);
NSTL_INSTANTIATE(NSTL_FOR_EACH_NAMED(for_each,(self_type nstl_pint),Function))

/**
 * Global structure used to collect information when a test is run.
 */
struct {
    nstl_bool was_called;
    nstl_size_t elements_processed;
    nstl_int first_elem;
    nstl_int last_elem;
} test_info;

/**
 * Function called at the beginning of each test. It resets the information
 * gathered during the last test so the tests are independent.
 */
static void set_up(void) {
    test_info.was_called = nstl_false;
    test_info.elements_processed = 0;
    test_info.first_elem = test_info.last_elem = -1;
}

/**
 * Function called on each element within a range during the tests. It saves
 * information to the gloval test_info structure.
 */
static void func(nstl_int elem) {
    if (!test_info.was_called)
        test_info.first_elem = elem;
    test_info.last_elem = elem;
    test_info.was_called = nstl_true;
    test_info.elements_processed++;
}

static void should_return_function(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Function f;

    f = for_each(array, array + 10, func);
    assert_true(f == func);
}

static void should_process_all_elements(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for_each(array, array + 10, func);
    assert_int_equal(test_info.elements_processed, 10);
}

static void should_not_be_called_when_range_is_empty(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for_each(array, array, func);
    assert_false(test_info.was_called);
}

static void should_process_elements_in_right_order(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for_each(array, array + 10, func);
    assert_int_equal(test_info.first_elem, 0);
    assert_int_equal(test_info.last_elem, 9);
}

#undef for_each

extern void test_fixture_for_each(void) {
    test_fixture_start();
    fixture_setup(set_up);

    run_test(should_return_function);
    run_test(should_process_all_elements);
    run_test(should_not_be_called_when_range_is_empty);
    run_test(should_process_elements_in_right_order);

    test_fixture_end();
}
