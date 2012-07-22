/**
 * Unit tests for the vector template.
 *
 * @author Louis Dionne
 */

#include <nstl/container/vector.h>

#include <seatest.h>


#define test_vector nstl_vector(nstl_int)
NSTL_INSTANTIATE(NSTL_VECTOR(nstl_int))

static void test_initital_state(void) {
    test_vector vector;
    nstl_ctor(test_vector)(&vector);

    assert_true(nstl_empty(test_vector)(&vector));
    assert_true(nstl_size(test_vector)(&vector) == 0);
    assert_true(nstl_capacity(test_vector)(&vector) == 0);
}

static void test_state_after_reserve(void) {
    test_vector vector;
    nstl_ctor(test_vector)(&vector);
    nstl_reserve(test_vector)(&vector, 10);

    assert_true(nstl_empty(test_vector)(&vector));
    assert_true(nstl_size(test_vector)(&vector) == 0);
    assert_true(nstl_capacity(test_vector)(&vector) == 10);
}

#undef test_vector

extern void test_fixture_vector(void) {
    test_fixture_start();

    run_test(test_initital_state);
    run_test(test_state_after_reserve);

    test_fixture_end();
}
