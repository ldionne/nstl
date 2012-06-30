/*!
 * Implementation of a pair template.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_PAIR_H
#define NSTL_PAIR_H

#include <nstl/internal/type.h>
#include <nstl/internal/primitive.h>

#include <stdbool.h>


#define NSTL_PAIR(R, T) NSTL_PAIR_INHERIT(nstl_pair(R, T), R, T)

#define NSTL_PAIR_INHERIT(pair_type, R, T)                                     \
NSTL_TYPE(                                                                     \
                                                                               \
(struct (                                                                      \
typedef struct {                                                               \
    R first;                                                                   \
    T second;                                                                  \
} pair_type;                                                                   \
))                                                                             \
                                                                               \
(init (                                                                        \
/*!                                                                            \
 * Initialize a pair.                                                          \
 */                                                                            \
static inline void nstl_init(pair_type)(pair_type *self, R first, T second)    \
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
static inline void nstl_deinit(pair_type)(pair_type *self)                     \
{                                                                              \
                                                                               \
}                                                                              \
))                                                                             \
                                                                               \
(eq (                                                                          \
/*!                                                                            \
 * Return whether two pairs have equal elements.                               \
 */                                                                            \
static inline bool nstl_eq(pair_type, pair_type)(pair_type x, pair_type y)     \
{                                                                              \
    return x.first == y.first && x.second == y.second;                         \
}                                                                              \
))                                                                             \
                                                                               \
(lt (                                                                          \
/*!                                                                            \
 * Return whether a pair is lesser than another.                               \
 */                                                                            \
static inline bool nstl_lt(pair_type, pair_type)(pair_type x, pair_type y)     \
{                                                                              \
    return x.first < y.first || (!(y.first < x.first) && x.second < y.second); \
}                                                                              \
))                                                                             \
                                                                               \
(ne (                                                                          \
/*!                                                                            \
 * Return whether two pairs have different elements.                           \
 */                                                                            \
static inline bool nstl_ne(pair_type, pair_type)(pair_type x, pair_type y)     \
{                                                                              \
    return !nstl_eq(pair_type, pair_type)(x, y);                               \
}                                                                              \
))                                                                             \
                                                                               \
(gt (                                                                          \
/*!                                                                            \
 * Return whether a pair is greater than another.                              \
 */                                                                            \
static inline bool nstl_gt(pair_type, pair_type)(pair_type x, pair_type y)     \
{                                                                              \
    return nstl_lt(pair_type, pair_type)(y, x);                                \
}                                                                              \
))                                                                             \
                                                                               \
(le (                                                                          \
/*!                                                                            \
 * Return a pair is lesser or equal to another.                                \
 */                                                                            \
static inline bool nstl_le(pair_type, pair_type)(pair_type x, pair_type y)     \
{                                                                              \
    return !nstl_lt(pair_type, pair_type)(y, x);                               \
}                                                                              \
))                                                                             \
                                                                               \
(ge (                                                                          \
/*!                                                                            \
 * Return whether a pair is greater or equal to another.                       \
 */                                                                            \
static inline bool nstl_ge(pair_type, pair_type)(pair_type x, pair_type y)     \
{                                                                              \
    return !nstl_lt(pair_type, pair_type)(x, y);                               \
}                                                                              \
))                                                                             \
                                                                               \
(make_pair (                                                                   \
/*!                                                                            \
 * Initialize and return a pair.                                               \
 */                                                                            \
static inline pair_type nstl_make_pair(R, T)(R first, T second)                \
{                                                                              \
    pair_type pair;                                                            \
    nstl_init(pair_type)(&pair, first, second);                                \
    return pair;                                                               \
}                                                                              \
))                                                                             \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
cog.outl(nstl.generate_attributes(
    'make_pair(R, T)',
    'init(T)',
    'deinit(T)',
    'struct',

    implement=True, token=True,
))

cog.outl(nstl.generate_attributes(
    'pair(R, T)',

    implement=False, token=False,
))

]]] */
#define NSTL_TOKEN_make_pair (m a k e _ p a i r)
#define NSTL_INSTRUCTION_make_pair(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, make_pair, implementation)
#define nstl_make_pair(R,  T) JOY_CAT5(nstl_mangled_make_pair, _, R, _,  T)
#define NSTL_TOKEN_init (i n i t)
#define NSTL_INSTRUCTION_init(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, init, implementation)
#define nstl_init(T) JOY_CAT3(nstl_mangled_init, _, T)
#define NSTL_TOKEN_deinit (d e i n i t)
#define NSTL_INSTRUCTION_deinit(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, deinit, implementation)
#define nstl_deinit(T) JOY_CAT3(nstl_mangled_deinit, _, T)
#define NSTL_TOKEN_struct (s t r u c t)
#define NSTL_INSTRUCTION_struct(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, struct, implementation)
#define nstl_struct nstl_mangled_struct
#define nstl_pair(R,  T) JOY_CAT5(nstl_mangled_pair, _, R, _,  T)
/* [[[end]]] */

#endif /* !NSTL_PAIR_H */
