/**
 * Unit tests for the @em copy_n algorithm.
 */

#include <nstl/algorithm/copy_n.h>

#include <seatest.h>


NSTL_INSTANTIATE(NSTL_I_COPY_N_DEFAULT(
                            copy_n_def, nstl_pint, nstl_size_t, nstl_pint))
NSTL_INSTANTIATE(NSTL_I_COPY_N_RANDOM_ACCESS(
                            copy_n_rand, nstl_pint, nstl_size_t, nstl_pint))

static void test_should_copy_n_for_any_n_def(void) {
    nstl_int n;
    for (n = 0; n < 10; ++n) {
        nstl_int source[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        nstl_int dest[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        nstl_int i;
        nstl_pint last = copy_n_def(source, n, dest);
        assert_true(last == dest + n);

        for (i = 0; i < 10; ++i) {
            assert_true(source[i] == 1);
            if (i < n)
                assert_true(dest[i] == 1);
            else
                assert_true(dest[i] == 0);
        }
    }
}

static void test_should_copy_n_for_any_n_random_access(void) {
    nstl_int n;
    for (n = 0; n < 10; ++n) {
        nstl_int source[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        nstl_int dest[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        nstl_int i;
        nstl_pint last = copy_n_rand(source, n, dest);
        assert_true(last == dest + n);

        for (i = 0; i < 10; ++i) {
            assert_true(source[i] == 1);
            if (i < n)
                assert_true(dest[i] == 1);
            else
                assert_true(dest[i] == 0);
        }
    }
}

extern void test_fixture_copy_n(void) {
    test_fixture_start();

    run_test(test_should_copy_n_for_any_n_def);
    run_test(test_should_copy_n_for_any_n_random_access);

    test_fixture_end();
}
