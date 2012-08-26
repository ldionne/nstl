/**
 * Unit tests for the iterator traits.
 */

#include <nstl/iterator/traits.h>

#include <chaos/preprocessor/comparison/equal.h>
#include <seatest.h>


#define Incrementable                                                          \
    (traversal_category nstl_incrementable_traversal_tag)                      \
/**/

#define SinglePass                                                             \
    (traversal_category nstl_single_pass_traversal_tag)                        \
/**/

#define Forward                                                                \
    (traversal_category nstl_forward_traversal_tag)                            \
/**/

#define Bidirectional                                                          \
    (traversal_category nstl_bidirectional_traversal_tag)                      \
/**/

#define RandomAccess                                                           \
    (traversal_category nstl_random_access_traversal_tag)                      \
/**/

#define AllTraits                                                              \
    (self_type 1)                                                              \
    (value_traits (self_type 2))                                               \
    (ref_traits (self_type 3))                                                 \
    (ptr_traits (self_type 4))                                                 \
    (diff_traits (self_type 5))                                                \
    (traversal_category nstl_incrementable_iterator_tag)                       \
/**/

extern void test_fixture_iterator_traits(void) {
    test_fixture_start();

    NSTL_STATIC_ASSERT_TRUE(NSTL_IS_INCREMENTABLE_ITERATOR(Incrementable), "")
    NSTL_STATIC_ASSERT_FALSE(NSTL_IS_SINGLE_PASS_ITERATOR(Incrementable), "")
    NSTL_STATIC_ASSERT_FALSE(NSTL_IS_FORWARD_ITERATOR(Incrementable), "")
    NSTL_STATIC_ASSERT_FALSE(NSTL_IS_BIDIRECTIONAL_ITERATOR(Incrementable),"")
    NSTL_STATIC_ASSERT_FALSE(NSTL_IS_RANDOM_ACCESS_ITERATOR(Incrementable),"")

    NSTL_STATIC_ASSERT_TRUE(NSTL_IS_INCREMENTABLE_ITERATOR(SinglePass), "")
    NSTL_STATIC_ASSERT_TRUE(NSTL_IS_SINGLE_PASS_ITERATOR(SinglePass), "")
    NSTL_STATIC_ASSERT_FALSE(NSTL_IS_FORWARD_ITERATOR(SinglePass), "")
    NSTL_STATIC_ASSERT_FALSE(NSTL_IS_BIDIRECTIONAL_ITERATOR(SinglePass),"")
    NSTL_STATIC_ASSERT_FALSE(NSTL_IS_RANDOM_ACCESS_ITERATOR(SinglePass), "")

    NSTL_STATIC_ASSERT_TRUE(NSTL_IS_INCREMENTABLE_ITERATOR(Forward), "")
    NSTL_STATIC_ASSERT_TRUE(NSTL_IS_SINGLE_PASS_ITERATOR(Forward), "")
    NSTL_STATIC_ASSERT_TRUE(NSTL_IS_FORWARD_ITERATOR(Forward), "")
    NSTL_STATIC_ASSERT_FALSE(NSTL_IS_BIDIRECTIONAL_ITERATOR(Forward),"")
    NSTL_STATIC_ASSERT_FALSE(NSTL_IS_RANDOM_ACCESS_ITERATOR(Forward), "")

    NSTL_STATIC_ASSERT_TRUE(NSTL_IS_INCREMENTABLE_ITERATOR(Bidirectional), "")
    NSTL_STATIC_ASSERT_TRUE(NSTL_IS_SINGLE_PASS_ITERATOR(Bidirectional), "")
    NSTL_STATIC_ASSERT_TRUE(NSTL_IS_FORWARD_ITERATOR(Bidirectional), "")
    NSTL_STATIC_ASSERT_TRUE(NSTL_IS_BIDIRECTIONAL_ITERATOR(Bidirectional), "")
    NSTL_STATIC_ASSERT_FALSE(NSTL_IS_RANDOM_ACCESS_ITERATOR(Bidirectional),"")

    NSTL_STATIC_ASSERT_TRUE(NSTL_IS_INCREMENTABLE_ITERATOR(RandomAccess), "")
    NSTL_STATIC_ASSERT_TRUE(NSTL_IS_SINGLE_PASS_ITERATOR(RandomAccess), "")
    NSTL_STATIC_ASSERT_TRUE(NSTL_IS_FORWARD_ITERATOR(RandomAccess), "")
    NSTL_STATIC_ASSERT_TRUE(NSTL_IS_BIDIRECTIONAL_ITERATOR(RandomAccess), "")
    NSTL_STATIC_ASSERT_TRUE(NSTL_IS_RANDOM_ACCESS_ITERATOR(RandomAccess), "")

    NSTL_STATIC_ASSERT_TRUE(CHAOS_PP_EQUAL(
        NSTL_TRAIT_SELF_TYPE(AllTraits), 1), "")
    NSTL_STATIC_ASSERT_TRUE(CHAOS_PP_EQUAL(
        NSTL_TRAIT_VALUE_TYPE(AllTraits), 2), "")
    NSTL_STATIC_ASSERT_TRUE(CHAOS_PP_EQUAL(
        NSTL_TRAIT_REF_TYPE(AllTraits), 3), "")
    NSTL_STATIC_ASSERT_TRUE(CHAOS_PP_EQUAL(
        NSTL_TRAIT_PTR_TYPE(AllTraits), 4), "")
    NSTL_STATIC_ASSERT_TRUE(CHAOS_PP_EQUAL(
        NSTL_TRAIT_DIFF_TYPE(AllTraits), 5), "")
    NSTL_STATIC_ASSERT_TRUE(NSTL_IS_INCREMENTABLE_ITERATOR(AllTraits), "")

    test_fixture_end();
}
