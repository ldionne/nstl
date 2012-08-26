/**
 * Definition of type traits for iterators.
 */

#ifndef NSTL_ITERATOR_TRAITS_H
#define NSTL_ITERATOR_TRAITS_H

#include <nstl/internal.h>

#include <chaos/preprocessor/comparison/greater_equal.h>
#include <chaos/preprocessor/comparison/less_equal.h>


/*
 * The following macros retrieve information from the traits of an iterator.
 */
#define NSTL_TRAIT_VALUE_TRAITS(traits) \
    NSTL_FIND_TRAIT(traits, value_traits)

#define NSTL_TRAIT_REF_TRAITS(traits) \
    NSTL_FIND_TRAIT(traits, ref_traits)

#define NSTL_TRAIT_PTR_TRAITS(traits) \
    NSTL_FIND_TRAIT(traits, ptr_traits)

#define NSTL_TRAIT_DIFF_TRAITS(traits) \
    NSTL_FIND_TRAIT(traits, diff_traits)


#define NSTL_TRAIT_VALUE_TYPE(traits) \
    NSTL_TRAIT_SELF_TYPE(NSTL_TRAIT_VALUE_TRAITS(traits))

#define NSTL_TRAIT_REF_TYPE(traits) \
    NSTL_TRAIT_SELF_TYPE(NSTL_TRAIT_REF_TRAITS(traits))

#define NSTL_TRAIT_PTR_TYPE(traits) \
    NSTL_TRAIT_SELF_TYPE(NSTL_TRAIT_PTR_TRAITS(traits))

#define NSTL_TRAIT_DIFF_TYPE(traits) \
    NSTL_TRAIT_SELF_TYPE(NSTL_TRAIT_DIFF_TRAITS(traits))

/*
 * Iterator traversal categories.
 */
#define nstl_incrementable_traversal_tag 0
#define nstl_single_pass_traversal_tag   1
#define nstl_forward_traversal_tag       2
#define nstl_bidirectional_traversal_tag 3
#define nstl_random_access_traversal_tag 4

/*
 * The following macros retrieve information about the traversal category of
 * an iterator type whose iterator traits are defined.
 */
#define NSTL_ITERATOR_TRAITS_TRAVERSAL_CATEGORY(traits)                        \
    NSTL_I_ITERATOR_TRAITS_TRAVERSAL_CATEGORY(                                 \
        NSTL_FIND_TRAIT(traits, traversal_category)                            \
    )                                                                          \
/**/

#define NSTL_I_ITERATOR_TRAITS_TRAVERSAL_CATEGORY(Cat)                         \
    NSTL_STATIC_ASSERT(NSTL_I_IS_VALID_CATEGORY(Cat),                          \
                       "invalid iterator traversal category.") Cat             \
/**/

#define NSTL_I_IS_VALID_CATEGORY(Cat) \
    CHAOS_PP_LESS_EQUAL(Cat, nstl_random_access_traversal_tag)

#define NSTL_I_TRAV_CATEGORY_AT_LEAST(traits, Cat)                             \
    NSTL_STATIC_ASSERT(NSTL_I_IS_VALID_CATEGORY(Cat),                          \
                       "invalid iterator traversal category.")                 \
    CHAOS_PP_GREATER_EQUAL(                                                    \
        NSTL_ITERATOR_TRAITS_TRAVERSAL_CATEGORY(traits), Cat                   \
    )                                                                          \
/**/

#define NSTL_IS_INCREMENTABLE_ITERATOR(traits) \
    NSTL_I_TRAV_CATEGORY_AT_LEAST(traits, nstl_incrementable_traversal_tag)

#define NSTL_IS_SINGLE_PASS_ITERATOR(traits) \
    NSTL_I_TRAV_CATEGORY_AT_LEAST(traits, nstl_single_pass_traversal_tag)

#define NSTL_IS_FORWARD_ITERATOR(traits) \
    NSTL_I_TRAV_CATEGORY_AT_LEAST(traits, nstl_forward_traversal_tag)

#define NSTL_IS_BIDIRECTIONAL_ITERATOR(traits) \
    NSTL_I_TRAV_CATEGORY_AT_LEAST(traits, nstl_bidirectional_traversal_tag)

#define NSTL_IS_RANDOM_ACCESS_ITERATOR(traits) \
    NSTL_I_TRAV_CATEGORY_AT_LEAST(traits, nstl_random_access_traversal_tag)


/* [[[cog

import nstl
nstl.generate(cog,

'value_traits',
'ref_traits',
'ptr_traits',
'diff_traits',
'traversal_category',

token=True)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_value_traits (v a l u e _ t r a i t s)
#define NSTL_TOKEN_ref_traits (r e f _ t r a i t s)
#define NSTL_TOKEN_ptr_traits (p t r _ t r a i t s)
#define NSTL_TOKEN_diff_traits (d i f f _ t r a i t s)
#define NSTL_TOKEN_traversal_category (t r a v e r s a l _ c a t e g o r y)
/* [[[end]]] */

#endif /* !NSTL_ITERATOR_TRAITS_H */
