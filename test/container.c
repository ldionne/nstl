/**
 * Test suite for the @em container module of nstl.
 *
 * @author Louis Dionne
 */

#include <seatest.h>


extern void test_fixture_vector(void);


extern void test_suite_container(void) {
    test_fixture_vector();
}
