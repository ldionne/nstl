/*!
 * Implementation of a pair template.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_PAIR_H
#define NSTL_PAIR_H

#include <nstl/type.h>

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
(setf struct                                                                   \
typedef struct {                                                               \
    T1 first;                                                                  \
    T2 second;                                                                 \
} pair;                                                                        \
)                                                                              \
                                                                               \
(setf init                                                                     \
/*!                                                                            \
 * Initialize a pair.                                                          \
 */                                                                            \
static inline void nstl_init(pair)(pair *self, T1 first, T2 second)            \
{                                                                              \
    self->first = first;                                                       \
    self->second = second;                                                     \
}                                                                              \
)                                                                              \
                                                                               \
(setf deinit                                                                   \
/*!                                                                            \
 * Uninitialize a pair.                                                        \
 */                                                                            \
static inline void nstl_deinit(pair)(pair *self)                               \
{                                                                              \
                                                                               \
}                                                                              \
)                                                                              \
                                                                               \
(setf eq                                                                       \
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
)                                                                              \
                                                                               \
(setf lt                                                                       \
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
)                                                                              \
                                                                               \
(setf ne                                                                       \
/*!                                                                            \
 * Return whether two pairs have different elements.                           \
 */                                                                            \
static inline bool nstl_ne(pair, pair)(pair x, pair y)                         \
{                                                                              \
    return !nstl_eq(pair, pair)(x, y);                                         \
}                                                                              \
)                                                                              \
                                                                               \
(setf gt                                                                       \
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
)                                                                              \
                                                                               \
(setf le                                                                       \
/*!                                                                            \
 * Return a pair is lesser or equal to another.                                \
 */                                                                            \
static inline bool nstl_le(pair, pair)(pair x, pair y)                         \
{                                                                              \
    return !nstl_lt(pair, pair)(y, x);                                         \
}                                                                              \
)                                                                              \
                                                                               \
(setf ge                                                                       \
/*!                                                                            \
 * Return whether a pair is greater or equal to another.                       \
 */                                                                            \
static inline bool nstl_ge(pair, pair)(pair x, pair y)                         \
{                                                                              \
    return !nstl_lt(pair, pair)(x, y);                                         \
}                                                                              \
)                                                                              \
                                                                               \
(setf make_pair                                                                \
/*!                                                                            \
 * Initialize and return a pair.                                               \
 */                                                                            \
static inline pair nstl_make_pair(T1, T2)(T1 first, T2 second)                 \
{                                                                              \
    pair self;                                                                 \
    nstl_init(pair)(&self, first, second);                                     \
    return self;                                                               \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
cog.outl(nstl.generate_mangled(
    'make_pair(T1, T2)',
))

cog.outl(nstl.generate_mangled(
    'pair(T1, T2)',

    token=False,
))

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_make_pair (m a k e _ p a i r)
#define nstl_make_pair(T1,  T2) JOY_CAT5(nstl_mangled_make_pair, _, T1, _,  T2)
#include <joy/cat.h>
#define nstl_pair(T1,  T2) JOY_CAT5(nstl_mangled_pair, _, T1, _,  T2)
/* [[[end]]] */

#endif /* !NSTL_PAIR_H */
