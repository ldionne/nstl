/**
 * Unit tests for the @em find and @em find_comp algorithms.
 */

#include <nstl/algorithm/find.h>

#include <seatest.h>


typedef nstl_bool (*Compare)(nstl_char x, nstl_char y);
NSTL_INSTANTIATE(
    NSTL_I_FIND_COMP_SINGLE_PASS(find_sp, nstl_pchar, nstl_char, Compare))
NSTL_INSTANTIATE(
    NSTL_I_FIND_COMP_RANDOM_ACCESS(find_ra, nstl_pchar, nstl_char, Compare))
NSTL_INSTANTIATE(NSTL_I_FIND_BYTE(find_byte, nstl_pchar, nstl_char))

/* We only need to test the instantiation of this one because it forwards the
 * work to other find variants.
 */
NSTL_INSTANTIATE(NSTL_I_FIND_DEFAULT(find, nstl_pchar, nstl_char))

#define find_ra(first, last, value) \
    find_ra(first, last, value, nstl_eq(nstl_char, nstl_char))
#define find_sp(first, last, value) \
    find_sp(first, last, value, nstl_eq(nstl_char, nstl_char))

static void test_should_return_last_when_not_found(void) {
    nstl_char array[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    nstl_pchar first = array, last = array + 10, iter_ra, iter_sp, iter_byte;

    iter_ra = find_ra(first, last, 'a');
    iter_sp = find_sp(first, last, 'a');
    iter_byte = find_byte(first, last, 'a');
    assert_true(iter_ra == iter_sp);
    assert_true(iter_ra == iter_byte);
    assert_true(iter_ra == last);
}

static void test_should_return_iterator_to_found_element_when_found(void) {
    nstl_char array[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    nstl_char c;
    nstl_pchar first = array, last = array + 10, iter_ra, iter_sp, iter_byte;

    for (c = '0'; c <= '9'; ++c) {
        iter_ra = find_ra(first, last, c);
        iter_sp = find_sp(first, last, c);
        iter_byte = find_byte(first, last, c);
        assert_true(iter_ra == iter_sp);
        assert_true(iter_ra == iter_byte);
        assert_true(iter_ra == first + (c - '0'));
        assert_true(*iter_ra == c);
    }
}

#undef find_sp
#undef find_ra

extern void test_fixture_find(void) {
    test_fixture_start();

    run_test(test_should_return_last_when_not_found);
    run_test(test_should_return_iterator_to_found_element_when_found);

    test_fixture_end();
}
