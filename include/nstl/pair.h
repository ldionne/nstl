/*!
 * Implementation of a pair template.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_PAIR_H
#define NSTL_PAIR_H

#include <nstl/internal/type.h>

#include <joy/cat.h>


#define nstl_pair(R, T) JOY_CAT4(nstl_pair_, R, _, T)

#define NSTL_TOKEN_make_pair (m a k e _ p a i r)
#define NSTL_INSTRUCTION_make_pair(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, make_pair, implementation)
#define nstl_make_pair(R, T) \
    JOY_CAT4(nstl_attribute_make_pair_, R, _, T)

#define NSTL_PAIR(R, T)                                                        \
NSTL_TYPE(                                                                     \
                                                                               \
(struct (                                                                      \
typedef struct {                                                               \
    R first;                                                                   \
    T second;                                                                  \
} nstl_pair(R, T);                                                             \
))                                                                             \
                                                                               \
(init (                                                                        \
/*!                                                                            \
 * Initialize a pair.                                                          \
 */                                                                            \
static inline void nstl_init(nstl_pair(R, T))(nstl_pair(R, T) *self, R first,  \
                                                                     T second) \
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
static inline void nstl_deinit(nstl_pair(R, T))(nstl_pair(R, T) *self)         \
{                                                                              \
                                                                               \
}                                                                              \
))                                                                             \
                                                                               \
(eq (                                                                          \
/*!                                                                            \
 * Return whether two pairs have equal elements.                               \
 */                                                                            \
static inline bool nstl_eq(nstl_pair(R, T))(nstl_pair(R, T) x,                 \
                                            nstl_pair(R, T) y)                 \
{                                                                              \
    return x.first == y.first && x.second == y.second;                         \
}                                                                              \
))                                                                             \
                                                                               \
(lt (                                                                          \
/*!                                                                            \
 * Return whether a pair is lesser than another.                               \
 */                                                                            \
static inline bool nstl_lt(nstl_pair(R, T))(nstl_pair(R, T) x,                 \
                                            nstl_pair(R, T) y)                 \
{                                                                              \
    return x.first < y.first || (!(y.first < x.first) && x.second < y.second); \
}                                                                              \
))                                                                             \
                                                                               \
(ne (                                                                          \
/*!                                                                            \
 * Return whether two pairs have different elements.                           \
 */                                                                            \
static inline bool nstl_ne(nstl_pair(R, T))(nstl_pair(R, T) x,                 \
                                            nstl_pair(R, T) y)                 \
{                                                                              \
    return !nstl_eq(nstl_pair(R, T))(x, y);                                    \
}                                                                              \
))                                                                             \
                                                                               \
(gt (                                                                          \
/*!                                                                            \
 * Return whether a pair is greater than another.                              \
 */                                                                            \
static inline bool nstl_gt(nstl_pair(R, T))(nstl_pair(R, T) x,                 \
                                            nstl_pair(R, T) y)                 \
{                                                                              \
    return nstl_lt(nstl_pair(R, T))(y, x);                                     \
}                                                                              \
))                                                                             \
                                                                               \
(le (                                                                          \
/*!                                                                            \
 * Return a pair is lesser or equal to another.                                \
 */                                                                            \
static inline bool nstl_le(nstl_pair(R, T))(nstl_pair(R, T) x,                 \
                                            nstl_pair(R, T) y)                 \
{                                                                              \
    return !nstl_lt(nstl_pair(R, T))(y, x);                                    \
}                                                                              \
))                                                                             \
                                                                               \
(ge (                                                                          \
/*!                                                                            \
 * Return whether a pair is greater or equal to another.                       \
 */                                                                            \
static inline bool nstl_ge(nstl_pair(R, T))(nstl_pair(R, T) x,                 \
                                            nstl_pair(R, T) y)                 \
{                                                                              \
    return !nstl_lt(nstl_pair(R, T))(x, y);                                    \
}                                                                              \
))                                                                             \
                                                                               \
(make_pair (                                                                   \
/*!                                                                            \
 * Initialize and return a pair.                                               \
 */                                                                            \
static inline nstl_pair(R, T) nstl_make_pair(R, T)(R first, T second)          \
{                                                                              \
    nstl_pair(R, T) pair;                                                      \
    nstl_init(nstl_pair(R, T))(&pair, first, second);                          \
    return pair;                                                               \
}                                                                              \
))                                                                             \
                                                                               \
)                                                                              \
/**/

#endif /* !NSTL_PAIR_H */
