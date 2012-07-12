/**
 * Test suite for the @em algorithm module of nstl.
 *
 * @author Louis Dionne
 */

#include <seatest.h>


extern void test_fixture_adjacent_find(void);
extern void test_fixture_count_if(void);
extern void test_fixture_find(void);
extern void test_fixture_for_each(void);


extern void test_suite_algorithm(void) {
    test_fixture_adjacent_find();
    test_fixture_count_if();
    test_fixture_find();
    test_fixture_for_each();
}
