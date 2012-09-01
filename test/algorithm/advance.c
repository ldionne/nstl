/**
 * Unit tests for the @em advance algorithm.
 */

#include <nstl/algorithm/advance.h>

#include <seatest.h>


#define Default (self_type nstl_pint)                                          \
                (diff_traits (self_type nstl_ptrdiff_t))                       \
                (traversal_category nstl_incrementable_traversal_tag)          \
/**/

#define Bidirectional (self_type nstl_pint)                                    \
                      (diff_traits (self_type nstl_ptrdiff_t))                 \
                      (traversal_category nstl_bidirectional_traversal_tag)    \
/**/

#define RandomAccess (self_type nstl_pint)                                     \
                     (diff_traits (self_type nstl_ptrdiff_t))                  \
                     (traversal_category nstl_random_access_traversal_tag)     \
/**/


NSTL_INSTANTIATE(NSTL_ADVANCE_NAMED(def_advance, Default))
NSTL_INSTANTIATE(NSTL_ADVANCE_NAMED(bidir_advance, Bidirectional))
NSTL_INSTANTIATE(NSTL_ADVANCE_NAMED(rand_advance, RandomAccess))

static void test_should_not_advance_when_distance_is_0(void) {
    nstl_int array[10];
    nstl_pint def_iter = array, bidir_iter = array, rand_iter = array;
    def_advance(&def_iter, 0);
    bidir_advance(&bidir_iter, 0);
    rand_advance(&rand_iter, 0);
    assert_true(def_iter == bidir_iter);
    assert_true(def_iter == rand_iter);
    assert_true(def_iter == array);
}

static void test_should_advance_by_the_distance_given(void) {
    nstl_int array[10];
    nstl_pint def_iter = array, bidir_iter = array, rand_iter = array;
    def_advance(&def_iter, 5);
    bidir_advance(&bidir_iter, 5);
    rand_advance(&rand_iter, 5);
    assert_true(def_iter == bidir_iter);
    assert_true(def_iter == rand_iter);
    assert_true(def_iter == array + 5);
}

static void test_should_rewind_by_the_distance_given(void) {
    nstl_int array[10];
    nstl_pint bidir_iter = array + 10, rand_iter = array + 10;
    bidir_advance(&bidir_iter, -5);
    rand_advance(&rand_iter, -5);
    assert_true(bidir_iter == rand_iter);
    assert_true(bidir_iter == array + 5);
}

extern void test_fixture_advance(void) {
    test_fixture_start();

    run_test(test_should_not_advance_when_distance_is_0);
    run_test(test_should_advance_by_the_distance_given);
    run_test(test_should_rewind_by_the_distance_given);

    test_fixture_end();
}
