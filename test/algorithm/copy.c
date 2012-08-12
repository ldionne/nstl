/**
 * Unit tests for the @em copy algorithm.
 */

#include <nstl/algorithm/copy.h>

#include <seatest.h>


NSTL_INSTANTIATE(NSTL_I_COPY_DEFAULT(copy, nstl_pint, nstl_pint))
NSTL_INSTANTIATE(NSTL_I_COPY_TRIVIAL(copy_triv, nstl_pint, nstl_pint))
NSTL_INSTANTIATE(
    NSTL_I_COPY_TRIVIAL_NO_OVERLAP(copy_no_over, nstl_pint, nstl_pint))
NSTL_INSTANTIATE(NSTL_I_COPY_RANDOM_ACCESS(copy_rand, nstl_pint, nstl_pint))

static void test_should_return_one_past_last_in_dest_range_def(void) {
    nstl_int source[10];
    nstl_int dest[10];
    nstl_pint it = copy(source, source + 10, dest);
    assert_true(it == dest + 10);
}

static void test_should_return_one_past_last_in_dest_range_rand(void) {
    nstl_int source[10];
    nstl_int dest[10];
    nstl_pint it = copy_rand(source, source + 10, dest);
    assert_true(it == dest + 10);
}

static void test_should_return_one_past_last_in_dest_range_triv(void) {
    nstl_int source[10];
    nstl_int dest[10];
    nstl_pint it = copy_triv(source, source + 10, dest);
    assert_true(it == dest + 10);
}

static void test_should_return_one_past_last_in_dest_range_triv_over(void) {
    nstl_int array[10];
    nstl_pint it = copy_triv(array, array + 10, array);
    assert_true(it == array + 10);
}

static void test_should_return_one_past_last_in_dest_range_no_over(void) {
    nstl_int source[10];
    nstl_int dest[10];
    nstl_pint it = copy_no_over(source, source + 10, dest);
    assert_true(it == dest + 10);
}

static void test_should_copy_content_from_src_to_dst_def(void) {
    nstl_int source[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_int dest[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    nstl_int i;
    copy(source, source + 10, dest);
    for (i = 0; i < 10; ++i) {
        assert_true(source[i] == dest[i]);
    }
}

static void test_should_copy_content_from_src_to_dst_rand(void) {
    nstl_int source[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_int dest[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    nstl_int i;
    copy_rand(source, source + 10, dest);
    for (i = 0; i < 10; ++i) {
        assert_true(source[i] == dest[i]);
    }
}

static void test_should_copy_content_from_src_to_dst_triv(void) {
    nstl_int source[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_int dest[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    nstl_int i;
    copy_triv(source, source + 10, dest);
    for (i = 0; i < 10; ++i) {
        assert_true(source[i] == dest[i]);
    }
}

static void test_should_copy_content_from_src_to_dst_triv_over(void) {
    nstl_int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_int expected[10] = {0, 1, 0, 1, 2, 3, 4, 7, 8, 9};
    nstl_int i;
    copy_triv(array, array + 5, array + 2);
    for (i = 0; i < 10; ++i) {
        assert_true(array[i] == expected[i]);
    }
}

static void test_should_copy_content_from_src_to_dst_no_over(void) {
    nstl_int source[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nstl_int dest[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    nstl_int i;
    copy_no_over(source, source + 10, dest);
    for (i = 0; i < 10; ++i) {
        assert_true(source[i] == dest[i]);
    }
}

extern void test_fixture_copy(void) {
    test_fixture_start();

    run_test(test_should_return_one_past_last_in_dest_range_def);
    run_test(test_should_copy_content_from_src_to_dst_rand);
    run_test(test_should_return_one_past_last_in_dest_range_triv);
    run_test(test_should_return_one_past_last_in_dest_range_triv_over);
    run_test(test_should_return_one_past_last_in_dest_range_no_over);
    run_test(test_should_copy_content_from_src_to_dst_def);
    run_test(test_should_return_one_past_last_in_dest_range_rand);
    run_test(test_should_copy_content_from_src_to_dst_triv);
    run_test(test_should_copy_content_from_src_to_dst_triv_over);
    run_test(test_should_copy_content_from_src_to_dst_no_over);

    test_fixture_end();
}
