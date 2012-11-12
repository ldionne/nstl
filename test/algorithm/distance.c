/**
 * Unit tests for the @em distance algorithm.
 */

#include <nstl/algorithm/distance.h>

#include <seatest.h>


#define DefaultTraits (self_type nstl_pint)                                 \
                      (diff_traits (self_type nstl_ptrdiff_t))              \
                      (traversal_category nstl_incrementable_traversal_tag)

#define RandomAccessTraits (self_type nstl_pint)                            \
                           (diff_traits (self_type nstl_ptrdiff_t))         \
                         (traversal_category nstl_random_access_traversal_tag)


NSTL_INSTANTIATE(NSTL_DISTANCE_NAMED(distance, DefaultTraits))
NSTL_INSTANTIATE(NSTL_DISTANCE_NAMED(distance_rand, RandomAccessTraits))

static void test_should_have_distance_of_0_when_same_iter(void) {
    nstl_int array[10];
    assert_true(distance(array, array) == distance_rand(array, array));
    assert_true(distance(array, array) == 0);
}

static void test_should_be_number_of_elements_between_both_iters(void) {
    nstl_int array[10];
    nstl_pint first = array, last = array + 6;
    assert_true(distance(first, last) == distance_rand(first, last));
    assert_true(distance(first, last) == 6);
}

extern void test_fixture_distance(void) {
    test_fixture_start();

    run_test(test_should_have_distance_of_0_when_same_iter);
    run_test(test_should_be_number_of_elements_between_both_iters);

    test_fixture_end();
}
