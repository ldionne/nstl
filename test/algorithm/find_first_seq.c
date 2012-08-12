/**
 * Unit tests for the @em find_first_seq and @em find_first_seq_comp
 * algorithms.
 */

#include <nstl/algorithm/find_first_seq.h>

#include <seatest.h>


typedef nstl_bool (*Compare)(nstl_int x, nstl_int y);
NSTL_INSTANTIATE(NSTL_FIND_FIRST_SEQ(nstl_pint, nstl_pint, nstl_int))
NSTL_INSTANTIATE(
    NSTL_FIND_FIRST_SEQ_COMP(nstl_pint, nstl_pint, Compare, nstl_int))

#define find_first_seq nstl_find_first_seq(nstl_pint, nstl_pint)
#define find_first_seq_comp(first1, last1, first2, last2)                      \
    nstl_find_first_seq_comp(nstl_pint, nstl_pint, Compare)(                   \
        first1, last1, first2, last2, nstl_eq(nstl_int, nstl_int)              \
    )                                                                          \
/**/

static void test_should_return_first_when_searching_empty_range(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint first1 = array, last1 = array + 10;
    nstl_pint first2 = array, last2 = array;
    nstl_pint found = find_first_seq(first1, last1, first2, last2);
    nstl_pint found_comp = find_first_seq_comp(first1, last1, first2, last2);
    assert_true(found == found_comp);
    assert_true(found == first1);
}

static void test_should_return_last_when_no_subsequence_not_found(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_int subsequence[3] = {5, 5, 5};
    nstl_pint first1 = array, last1 = array + 10;
    nstl_pint first2 = subsequence, last2 = subsequence + 3;
    nstl_pint found = find_first_seq(first1, last1, first2, last2);
    nstl_pint found_comp = find_first_seq_comp(first1, last1, first2, last2);
    assert_true(found == found_comp);
    assert_true(found == last1);
}

static void test_should_return_first_of_subsequence_overlapping(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint first1 = array, last1 = array + 10;
    nstl_pint first2 = array + 3, last2 = array + 6;
    nstl_pint found = find_first_seq(first1, last1, first2, last2);
    nstl_pint found_comp = find_first_seq_comp(first1, last1, first2, last2);
    assert_true(found == found_comp);
    assert_true(found == first2);
}

static void test_should_return_first_of_subsequence_non_overlapping(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_int subsequence[3] = {3, 4, 5};
    nstl_pint first1 = array, last1 = array + 10;
    nstl_pint first2 = subsequence, last2 = subsequence + 3;
    nstl_pint found = find_first_seq(first1, last1, first2, last2);
    nstl_pint found_comp = find_first_seq_comp(first1, last1, first2, last2);
    assert_true(found == found_comp);
    assert_true(found == first1 + 3);
}

static void test_with_subsequence_of_length_1(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint first1 = array, last1 = array + 10;
    nstl_pint first2 = array + 3, last2 = array + 4;
    nstl_pint found = find_first_seq(first1, last1, first2, last2);
    nstl_pint found_comp = find_first_seq_comp(first1, last1, first2, last2);
    assert_true(found == found_comp);
    assert_true(found == first2);
}

static void test_with_subsequence_stopping_at_last(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint first1 = array, last1 = array + 10;
    nstl_pint first2 = array + 7, last2 = array + 10;
    nstl_pint found = find_first_seq(first1, last1, first2, last2);
    nstl_pint found_comp = find_first_seq_comp(first1, last1, first2, last2);
    assert_true(found == found_comp);
    assert_true(found == first2);
}

static void test_with_subsequence_starting_at_first(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint first1 = array, last1 = array + 10;
    nstl_pint first2 = array, last2 = array + 3;
    nstl_pint found = find_first_seq(first1, last1, first2, last2);
    nstl_pint found_comp = find_first_seq_comp(first1, last1, first2, last2);
    assert_true(found == found_comp);
    assert_true(found == first2);
}

static void test_with_subsequence_matching_searched_range(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_pint first1 = array, last1 = array + 10;
    nstl_pint first2 = array, last2 = array + 10;
    nstl_pint found = find_first_seq(first1, last1, first2, last2);
    nstl_pint found_comp = find_first_seq_comp(first1, last1, first2, last2);
    assert_true(found == found_comp);
    assert_true(found == first2);
}

#undef find_first_seq_comp
#undef find_first_seq

extern void test_fixture_find_first_seq(void) {
    test_fixture_start();

    run_test(test_should_return_first_when_searching_empty_range);
    run_test(test_should_return_last_when_no_subsequence_not_found);
    run_test(test_should_return_first_of_subsequence_overlapping);
    run_test(test_should_return_first_of_subsequence_non_overlapping);
    run_test(test_with_subsequence_of_length_1);
    run_test(test_with_subsequence_stopping_at_last);
    run_test(test_with_subsequence_starting_at_first);
    run_test(test_with_subsequence_matching_searched_range);

    test_fixture_end();
}
