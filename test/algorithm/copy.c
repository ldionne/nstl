/**
 * Unit tests for the @em copy algorithm.
 */

#include <nstl/algorithm/copy.h>

#include <seatest.h>


NSTL_INSTANTIATE(NSTL_I_COPY_DEFAULT(copy, nstl_pint, nstl_pint))
NSTL_INSTANTIATE(NSTL_I_COPY_TRIVIAL(copy_triv, nstl_pint, nstl_pint))

static void test_should_return_one_past_last_in_dest_range_def(void) {
    nstl_int source[10];
    nstl_int dest[10];
    nstl_pint it = copy(source, source + 10, dest);
    assert_true(it == dest + 10);
}

static void test_should_copy_content_from_one_range_to_another_def(void) {
    nstl_int source[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_int dest[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    nstl_int i;
    copy(source, source + 10, dest);
    for (i = 0; i < 10; ++i) {
        assert_true(source[i] == dest[i]);
    }
}

static void test_should_return_one_past_last_in_dest_range_triv(void) {
    nstl_int source[10];
    nstl_int dest[10];
    nstl_pint it = copy_triv(source, source + 10, dest);
    assert_true(it == dest + 10);
}

static void test_should_copy_content_from_one_range_to_another_triv(void) {
    nstl_int source[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_int dest[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    nstl_int i;
    copy_triv(source, source + 10, dest);
    for (i = 0; i < 10; ++i) {
        assert_true(source[i] == dest[i]);
    }
}

extern void test_fixture_copy(void) {
    test_fixture_start();

    run_test(test_should_return_one_past_last_in_dest_range_def);
    run_test(test_should_copy_content_from_one_range_to_another_def);
    run_test(test_should_return_one_past_last_in_dest_range_triv);
    run_test(test_should_copy_content_from_one_range_to_another_triv);

    test_fixture_end();
}
