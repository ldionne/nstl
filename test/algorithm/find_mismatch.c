/**
 * Unit tests for the @em find_mismatch and @em find_mismatch_comp algorithms.
 */

#include <nstl/algorithm/find_mismatch.h>

#include <seatest.h>


NSTL_INSTANTIATE(NSTL_PAIR(nstl_pint, nstl_pint))
typedef nstl_bool (*Compare) (nstl_int x, nstl_int y);
NSTL_INSTANTIATE(NSTL_FIND_MISMATCH(nstl_pint, nstl_pint, nstl_int))
NSTL_INSTANTIATE(NSTL_FIND_MISMATCH_COMP(nstl_pint, nstl_pint, Compare))

#define find_mismatch nstl_find_mismatch(nstl_pint, nstl_pint)
#define find_mismatch_comp(first1, last1, first2)                              \
    nstl_find_mismatch_comp(nstl_pint, nstl_pint, Compare)(                    \
        first1, last1, first2, nstl_eq(nstl_int, nstl_int)                     \
    )                                                                          \
/**/
#define ret_type nstl_pair(nstl_pint, nstl_pint)

static void test_should_return_last1_and_corresponding_if_no_mismatch(void) {
    nstl_int array1[5] = {0, 0, 0, 0, 0};
    nstl_int array2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    ret_type mismatch, mismatch_comp, expected;
    mismatch = find_mismatch(array1, array1 + 5, array2);
    mismatch_comp = find_mismatch_comp(array1, array1 + 5, array2);
    expected = nstl_make_pair(nstl_pint, nstl_pint)(array1 + 5, array2 + 5);
    assert_true(nstl_eq(ret_type, ret_type)(mismatch, mismatch_comp));
    assert_true(nstl_eq(ret_type, ret_type)(mismatch, expected));
}

static void test_should_return_iter_to_first_non_equal_elements(void) {
    nstl_int array1[10] = {0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
    nstl_int array2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    ret_type mismatch, mismatch_comp, expected;
    mismatch = find_mismatch(array1, array1 + 10, array2);
    mismatch_comp = find_mismatch_comp(array1, array1 + 10, array2);
    expected = nstl_make_pair(nstl_pint, nstl_pint)(array1 + 5, array2 + 5);
    assert_true(nstl_eq(ret_type, ret_type)(mismatch, mismatch_comp));
    assert_true(nstl_eq(ret_type, ret_type)(mismatch, expected));
}

static void test_with_mismatch_at_first_elements(void) {
    nstl_int array1[10] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    nstl_int array2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    ret_type mismatch, mismatch_comp, expected;
    mismatch = find_mismatch(array1, array1 + 10, array2);
    mismatch_comp = find_mismatch_comp(array1, array1 + 10, array2);
    expected = nstl_make_pair(nstl_pint, nstl_pint)(array1, array2);
    assert_true(nstl_eq(ret_type, ret_type)(mismatch, mismatch_comp));
    assert_true(nstl_eq(ret_type, ret_type)(mismatch, expected));
}

static void test_with_mismatch_at_last_elements(void) {
    nstl_int array1[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    nstl_int array2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    ret_type mismatch, mismatch_comp, expected;
    mismatch = find_mismatch(array1, array1 + 10, array2);
    mismatch_comp = find_mismatch_comp(array1, array1 + 10, array2);
    expected = nstl_make_pair(nstl_pint, nstl_pint)(array1 + 9, array2 + 9);
    assert_true(nstl_eq(ret_type, ret_type)(mismatch, mismatch_comp));
    assert_true(nstl_eq(ret_type, ret_type)(mismatch, expected));
}

#undef ret_type
#undef find_mismatch_comp
#undef find_mismatch

extern void test_fixture_find_mismatch(void) {
    test_fixture_start();

    run_test(test_should_return_last1_and_corresponding_if_no_mismatch);
    run_test(test_should_return_iter_to_first_non_equal_elements);
    run_test(test_with_mismatch_at_first_elements);
    run_test(test_with_mismatch_at_last_elements);

    test_fixture_end();
}
