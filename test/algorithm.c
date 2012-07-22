/**
 * Test suite for the @em algorithm module of nstl.
 *
 * @author Louis Dionne
 */

#include <seatest.h>


extern void test_fixture_adjacent_find(void);
extern void test_fixture_count(void);
extern void test_fixture_count_if(void);
extern void test_fixture_distance(void);
extern void test_fixture_find(void);
extern void test_fixture_for_each(void);
extern void test_fixture_max_element(void);
extern void test_fixture_min_element(void);
extern void test_fixture_min_max(void);
extern void test_fixture_swap(void);


extern void test_suite_algorithm(void) {
    test_fixture_adjacent_find();
    test_fixture_count();
    test_fixture_count_if();
    test_fixture_distance();
    test_fixture_find();
    test_fixture_for_each();
    test_fixture_max_element();
    test_fixture_min_element();
    test_fixture_min_max();
    test_fixture_swap();
}
