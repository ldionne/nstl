/**
 * Test suite for the @em algorithm module of nstl.
 */

extern void test_fixture_advance(void);
extern void test_fixture_all_of(void);
extern void test_fixture_any_of(void);
extern void test_fixture_binary_search(void);
extern void test_fixture_copy(void);
extern void test_fixture_copy_if(void);
extern void test_fixture_copy_n(void);
extern void test_fixture_count(void);
extern void test_fixture_count_if(void);
extern void test_fixture_distance(void);
extern void test_fixture_equal_range(void);
extern void test_fixture_find(void);
extern void test_fixture_find_adjacent(void);
extern void test_fixture_find_first_seq(void);
extern void test_fixture_find_if(void);
extern void test_fixture_find_if_not(void);
extern void test_fixture_find_mismatch(void);
extern void test_fixture_for_each(void);
extern void test_fixture_is_equal(void);
extern void test_fixture_lower_bound(void);
extern void test_fixture_max(void);
extern void test_fixture_max_element(void);
extern void test_fixture_min(void);
extern void test_fixture_min_element(void);
extern void test_fixture_next(void);
extern void test_fixture_none_of(void);
extern void test_fixture_prev(void);
extern void test_fixture_swap(void);
extern void test_fixture_upper_bound(void);


extern void test_suite_algorithm(void) {
    test_fixture_advance();
    test_fixture_all_of();
    test_fixture_any_of();
    test_fixture_binary_search();
    test_fixture_copy();
    test_fixture_copy_if();
    test_fixture_copy_n();
    test_fixture_count();
    test_fixture_count_if();
    test_fixture_distance();
    test_fixture_equal_range();
    test_fixture_find();
    test_fixture_find_adjacent();
    test_fixture_find_first_seq();
    test_fixture_find_if();
    test_fixture_find_if_not();
    test_fixture_find_mismatch();
    test_fixture_for_each();
    test_fixture_is_equal();
    test_fixture_lower_bound();
    test_fixture_max();
    test_fixture_max_element();
    test_fixture_min();
    test_fixture_min_element();
    test_fixture_next();
    test_fixture_none_of();
    test_fixture_prev();
    test_fixture_swap();
    test_fixture_upper_bound();
}
