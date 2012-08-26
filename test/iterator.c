/**
 * Test suite for the @em iterator module of nstl.
 */

#include <seatest.h>


extern void test_fixture_iterator_traits(void);


extern void test_suite_iterator(void) {
    test_fixture_iterator_traits();
}
