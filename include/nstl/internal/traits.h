/**
 * Implementation of a structure capable of holding traits.
 *
 * @see doc/traits.md for information.
 */

#ifndef NSTL_INTERNAL_TRAITS_H
#define NSTL_INTERNAL_TRAITS_H

#include <joy/seq/find_first.h>
#include <joy/string/eq.h>


/*
 * Retrieve the value of a given trait.
 */
#define NSTL_FIND_TRAIT(traits, name)                                          \
    NSTL_I_TRAIT_GET_VALUE(                                                    \
        JOY_SEQ_FIND_FIRST(NSTL_I_TRAIT_EQ, traits, name))                     \
/**/

#define NSTL_I_TRAIT_GET_VALUE(trait_value) \
    NSTL_TOKEN_STRING_TAIL_UNSAFE(trait_value)

#define NSTL_I_TRAIT_EQ(s, trait_value, trait)                                 \
    JOY_STRING_EQ_S(s,                                                         \
        NSTL_TOKEN_TO_STRING(NSTL_TOKEN_STRING_HEAD(trait_value)),             \
        NSTL_TOKEN_TO_STRING(trait)                                            \
    )                                                                          \
/**/

/*
 * Universal trait representing the actual C type described by the traits.
 */
#define NSTL_TRAIT_SELF_TYPE(traits) \
    NSTL_FIND_TRAIT(traits, self_type)


/* [[[cog

import nstl
nstl.generate(cog, 'self_type', token=True)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_self_type (s e l f _ t y p e)
/* [[[end]]] */

#endif /* !NSTL_INTERNAL_TRAITS_H */
