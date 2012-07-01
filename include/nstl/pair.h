/*!
 * Implementation of a pair template.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_PAIR_H
#define NSTL_PAIR_H

#include <nstl/type.h>
#include <nstl/operator.h>

#include <stdbool.h>


#define NSTL_PAIR(T1, T2)                                                      \
    NSTL_PAIR_INHERIT(                                                         \
        nstl_pair(T1, T2),                                                     \
        T1,                                                                    \
        T2                                                                     \
    )                                                                          \
/**/

#define NSTL_PAIR_INHERIT(pair, T1, T2)                                        \
NSTL_TYPE(                                                                     \
                                                                               \
(struct (                                                                      \
typedef struct {                                                               \
    T1 first;                                                                  \
    T2 second;                                                                 \
} pair;                                                                        \
))                                                                             \
                                                                               \
(init (                                                                        \
/*!                                                                            \
 * Initialize a pair.                                                          \
 */                                                                            \
static inline void nstl_init(pair)(pair *self, T1 first, T2 second)            \
{                                                                              \
    self->first = first;                                                       \
    self->second = second;                                                     \
}                                                                              \
))                                                                             \
                                                                               \
(deinit (                                                                      \
/*!                                                                            \
 * Uninitialize a pair.                                                        \
 */                                                                            \
static inline void nstl_deinit(pair)(pair *self)                               \
{                                                                              \
                                                                               \
}                                                                              \
))                                                                             \
                                                                               \
(eq (                                                                          \
/*!                                                                            \
 * Return whether two pairs are equal.                                         \
 *                                                                             \
 * Two pairs compare equal if the first elements in both pairs compare equal   \
 * to each other and both second elements also compare equal to each other.    \
 */                                                                            \
static inline bool nstl_eq(pair, pair)(pair x, pair y)                         \
{                                                                              \
    return x.first == y.first && x.second == y.second;                         \
}                                                                              \
))                                                                             \
                                                                               \
(lt (                                                                          \
/*!                                                                            \
 * Return whether a pair is lesser than another.                               \
 *                                                                             \
 * The first elements are compared first, and only if the inequality comparison \
 * is not true for them, the second elements are compared.                     \
 */                                                                            \
static inline bool nstl_lt(pair, pair)(pair x, pair y)                         \
{                                                                              \
    return x.first < y.first || (!(y.first < x.first) && x.second < y.second); \
}                                                                              \
))                                                                             \
                                                                               \
(ne (                                                                          \
/*!                                                                            \
 * Return whether two pairs have different elements.                           \
 */                                                                            \
static inline bool nstl_ne(pair, pair)(pair x, pair y)                         \
{                                                                              \
    return !nstl_eq(pair, pair)(x, y);                                         \
}                                                                              \
))                                                                             \
                                                                               \
(gt (                                                                          \
/*!                                                                            \
 * Return whether a pair is greater than another.                              \
 *                                                                             \
 * The first elements are compared first, and only if the inequality comparison \
 * is not true for them, the second elements are compared.                     \
 */                                                                            \
static inline bool nstl_gt(pair, pair)(pair x, pair y)                         \
{                                                                              \
    return nstl_lt(pair, pair)(y, x);                                          \
}                                                                              \
))                                                                             \
                                                                               \
(le (                                                                          \
/*!                                                                            \
 * Return a pair is lesser or equal to another.                                \
 */                                                                            \
static inline bool nstl_le(pair, pair)(pair x, pair y)                         \
{                                                                              \
    return !nstl_lt(pair, pair)(y, x);                                         \
}                                                                              \
))                                                                             \
                                                                               \
(ge (                                                                          \
/*!                                                                            \
 * Return whether a pair is greater or equal to another.                       \
 */                                                                            \
static inline bool nstl_ge(pair, pair)(pair x, pair y)                         \
{                                                                              \
    return !nstl_lt(pair, pair)(x, y);                                         \
}                                                                              \
))                                                                             \
                                                                               \
(make_pair (                                                                   \
/*!                                                                            \
 * Initialize and return a pair.                                               \
 */                                                                            \
static inline pair nstl_make_pair(T1, T2)(T1 first, T2 second)                 \
{                                                                              \
    pair self;                                                                 \
    nstl_init(pair)(&self, first, second);                                     \
    return self;                                                               \
}                                                                              \
))                                                                             \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
cog.outl(nstl.generate_attributes(
    'make_pair(T1, T2)',
    'init(T2)',
    'deinit(T2)',
    'struct',

    implement=True, token=True,
))

cog.outl(nstl.generate_attributes(
    'pair(T1, T2)',

    implement=False, token=False,
))

]]] */
#define NSTL_TOKEN_make_pair (m a k e _ p a i r)
#define NSTL_INSTRUCTION_make_pair(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, make_pair, implementation)
#define nstl_make_pair(T1,  T2) JOY_CAT5(nstl_mangled_make_pair, _, T1, _,  T2)
#define NSTL_TOKEN_init (i n i t)
#define NSTL_INSTRUCTION_init(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, init, implementation)
#define nstl_init(T2) JOY_CAT3(nstl_mangled_init, _, T2)
#define NSTL_TOKEN_deinit (d e i n i t)
#define NSTL_INSTRUCTION_deinit(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, deinit, implementation)
#define nstl_deinit(T2) JOY_CAT3(nstl_mangled_deinit, _, T2)
#define NSTL_TOKEN_struct (s t r u c t)
#define NSTL_INSTRUCTION_struct(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, struct, implementation)
#define nstl_struct nstl_mangled_struct
#define nstl_pair(T1,  T2) JOY_CAT5(nstl_mangled_pair, _, T1, _,  T2)
/* [[[end]]] */

#endif /* !NSTL_PAIR_H */
