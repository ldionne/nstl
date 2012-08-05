/**
 * Test suite for the @em utility module of nstl.
 */

#include <seatest.h>


extern void test_fixture_pair(void);
extern void test_fixture_relational_operators(void);


extern void test_suite_utility(void) {
    test_fixture_pair();
    test_fixture_relational_operators();
}
