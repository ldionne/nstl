/*!
 * Implementation of C pointer types.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_POINTER_H
#define NSTL_INTERNAL_POINTER_H

#include <nstl/operator.h>

#include <stddef.h>


#define NSTL_POINTER(value_type, pointer)                                      \
NSTL_TYPE(                                                                     \
                                                                               \
(inherit (NSTL_ARITHMETIC_OPERATORS(pointer)))                                 \
(drop (mul))                                                                   \
(drop (imul))                                                                  \
(drop (div))                                                                   \
(drop (idiv))                                                                  \
(drop (mod))                                                                   \
(drop (imod))                                                                  \
(drop (prom))                                                                  \
(drop (inv))                                                                   \
(add (                                                                         \
static inline pointer nstl_add(pointer, ptrdiff_t)(pointer self, ptrdiff_t n)  \
{                                                                              \
    return self + n;                                                           \
}                                                                              \
))                                                                             \
(iadd (                                                                        \
static inline pointer nstl_iadd(pointer, ptrdiff_t)(pointer *self, ptrdiff_t n) \
{                                                                              \
    return (*self) += n;                                                       \
}                                                                              \
))                                                                             \
(sub (                                                                         \
static inline ptrdiff_t nstl_sub(pointer, pointer)(pointer x, pointer y)       \
{                                                                              \
    return x - y;                                                              \
}                                                                              \
                                                                               \
static inline pointer nstl_sub(pointer, ptrdiff_t)(pointer self, ptrdiff_t n)  \
{                                                                              \
    return self - n;                                                           \
}                                                                              \
))                                                                             \
(isub (                                                                        \
static inline pointer nstl_isub(pointer, ptrdiff_t)(pointer *self, ptrdiff_t n) \
{                                                                              \
    return (*self) -= n;                                                       \
}                                                                              \
))                                                                             \
                                                                               \
(inherit (NSTL_COMPARISON_OPERATORS(pointer)))                                 \
(inherit (NSTL_LOGICAL_OPERATORS(pointer)))                                    \
(inherit (NSTL_ALLOCATION_OPERATORS(pointer)))                                 \
                                                                               \
(deref (                                                                       \
static inline value_type nstl_deref(pointer)(pointer self)                     \
{                                                                              \
    return *self;                                                              \
}                                                                              \
))                                                                             \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
cog.outl(nstl.generate_attributes(
    'deref(pointer)',

    implement=True, token=True,
))

]]] */
#define NSTL_TOKEN_deref (d e r e f)
#define NSTL_INSTRUCTION_deref(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, deref, implementation)
#define nstl_deref(pointer) JOY_CAT3(nstl_mangled_deref, _, pointer)
/* [[[end]]] */

#endif /* !NSTL_INTERNAL_POINTER_H */
