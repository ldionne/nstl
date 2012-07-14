/**
 * Implementation of a pair template.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_PAIR_H
#define NSTL_PAIR_H

#include <nstl/internal.h>

#include <stdbool.h>


#define NSTL_PAIR(T1, T2)                                                      \
    NSTL_PAIR_INHERIT(                                                         \
        nstl_pair(T1, T2), T1, T2                                              \
    )                                                                          \
/**/

#define NSTL_PAIR_INHERIT(pair, T1, T2)                                        \
NSTL_TYPE(                                                                     \
                                                                               \
(defstruct                                                                     \
struct pair {                                                                  \
    T1 first;                                                                  \
    T2 second;                                                                 \
};                                                                             \
typedef struct pair pair;                                                      \
)                                                                              \
                                                                               \
(defun ctor                                                                    \
/**                                                                            \
 * Initialize a pair.                                                          \
 */                                                                            \
static NSTL_INLINE void nstl_ctor(pair)(pair *self, T1 first, T2 second) {     \
    nstl_copy_ctor(T1)(&self->first, first);                                   \
    nstl_copy_ctor(T2)(&self->second, second);                                 \
}                                                                              \
)                                                                              \
                                                                               \
(defun copy_ctor                                                               \
static NSTL_INLINE void nstl_copy_ctor(pair)(pair *self, pair other) {         \
    nstl_ctor(pair)(self, other.first, other.second);                          \
}                                                                              \
)                                                                              \
                                                                               \
(defun dtor                                                                    \
/**                                                                            \
 * Uninitialize a pair.                                                        \
 */                                                                            \
static NSTL_INLINE void nstl_dtor(pair)(pair *self) {                          \
    nstl_dtor(T1)(&self->first);                                               \
    nstl_dtor(T2)(&self->second);                                              \
}                                                                              \
)                                                                              \
                                                                               \
(defun eq                                                                      \
/**                                                                            \
 * Return whether two pairs are equal.                                         \
 *                                                                             \
 * Two pairs compare equal if the first elements in both pairs compare equal   \
 * to each other and both second elements also compare equal to each other.    \
 */                                                                            \
static NSTL_INLINE bool nstl_eq(pair, pair)(pair x, pair y) {                  \
    return nstl_eq(T1, T1)(x.first, y.first) &&                                \
           nstl_eq(T2, T2)(x.second, y.second);                                \
}                                                                              \
)                                                                              \
                                                                               \
(defun lt                                                                      \
/**                                                                            \
 * Return whether a pair is lesser than another.                               \
 *                                                                             \
 * The first elements are compared first, and only if the inequality           \
 * comparison is not true for them, the second elements are compared.          \
 */                                                                            \
static NSTL_INLINE bool nstl_lt(pair, pair)(pair x, pair y) {                  \
    return nstl_lt(T1, T1)(x.first, y.first) ||                                \
                (!(nstl_lt(T1, T1)(y.first, x.first)) &&                       \
                nstl_lt(T2, T2)(x.second, y.second));                          \
}                                                                              \
)                                                                              \
                                                                               \
(defun ne                                                                      \
/**                                                                            \
 * Return whether two pairs have different elements.                           \
 */                                                                            \
static NSTL_INLINE bool nstl_ne(pair, pair)(pair x, pair y) {                  \
    return !nstl_eq(pair, pair)(x, y);                                         \
}                                                                              \
)                                                                              \
                                                                               \
(defun gt                                                                      \
/**                                                                            \
 * Return whether a pair is greater than another.                              \
 *                                                                             \
 * The first elements are compared first, and only if the inequality           \
 * comparison is not true for them, the second elements are compared.          \
 */                                                                            \
static NSTL_INLINE bool nstl_gt(pair, pair)(pair x, pair y) {                  \
    return nstl_lt(pair, pair)(y, x);                                          \
}                                                                              \
)                                                                              \
                                                                               \
(defun le                                                                      \
/**                                                                            \
 * Return a pair is lesser or equal to another.                                \
 */                                                                            \
static NSTL_INLINE bool nstl_le(pair, pair)(pair x, pair y) {                  \
    return !nstl_lt(pair, pair)(y, x);                                         \
}                                                                              \
)                                                                              \
                                                                               \
(defun ge                                                                      \
/**                                                                            \
 * Return whether a pair is greater or equal to another.                       \
 */                                                                            \
static NSTL_INLINE bool nstl_ge(pair, pair)(pair x, pair y) {                  \
    return !nstl_lt(pair, pair)(x, y);                                         \
}                                                                              \
)                                                                              \
                                                                               \
(defun make_pair                                                               \
/**                                                                            \
 * Initialize and return a pair.                                               \
 */                                                                            \
static NSTL_INLINE pair nstl_make_pair(T1, T2)(T1 first, T2 second) {          \
    pair self;                                                                 \
    nstl_ctor(pair)(&self, first, second);                                     \
    return self;                                                               \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
nstl.generate(cog,
    'make_pair(T1, T2)',

    token=True, mangle=True,
)

nstl.generate(cog,
    'pair(T1, T2)',

    mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_make_pair (m a k e _ p a i r)
#define nstl_make_pair(T1,  T2) JOY_CAT5(nstl_mangled_make_pair, _, T1, _,  T2)
#include <joy/cat.h>
#define nstl_pair(T1,  T2) JOY_CAT5(nstl_mangled_pair, _, T1, _,  T2)
/* [[[end]]] */

#endif /* !NSTL_PAIR_H */
