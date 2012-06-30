/*!
 * Implementation of a primitive type.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_PRIMITIVE_H
#define NSTL_INTERNAL_PRIMITIVE_H

#include <nstl/internal/type.h>

#include <stdbool.h>


#define NSTL_PRIMITIVE(T)                                                      \
NSTL_TYPE(                                                                     \
                                                                               \
/* Arithmetic operators */                                                     \
(asg (                                                                         \
static inline T nstl_asg(T, T)(T *self, T other)                               \
{                                                                              \
    return (*self) = other;                                                    \
}                                                                              \
))                                                                             \
                                                                               \
(add (                                                                         \
static inline T nstl_add(T, T)(T x, T y)                                       \
{                                                                              \
    return x + y;                                                              \
}                                                                              \
))                                                                             \
                                                                               \
(sub (                                                                         \
static inline T nstl_sub(T, T)(T x, T y)                                       \
{                                                                              \
    return x - y;                                                              \
}                                                                              \
))                                                                             \
                                                                               \
(mul (                                                                         \
static inline T nstl_mul(T, T)(T x, T y)                                       \
{                                                                              \
    return x * y;                                                              \
}                                                                              \
))                                                                             \
                                                                               \
(div (                                                                         \
static inline T nstl_div(T, T)(T x, T y)                                       \
{                                                                              \
    return x / y;                                                              \
}                                                                              \
))                                                                             \
                                                                               \
(mod (                                                                         \
static inline T nstl_mod(T, T)(T x, T y)                                       \
{                                                                              \
    return x % y;                                                              \
}                                                                              \
))                                                                             \
                                                                               \
(inc (                                                                         \
static inline T nstl_inc(T)(T *self)                                           \
{                                                                              \
    return ++(*self);                                                          \
}                                                                              \
))                                                                             \
                                                                               \
(inc_ (                                                                        \
static inline T nstl_inc_(T)(T *self)                                          \
{                                                                              \
    return (*self)++;                                                          \
}                                                                              \
))                                                                             \
                                                                               \
(dec (                                                                         \
static inline T nstl_dec(T)(T *self)                                           \
{                                                                              \
    return --(*self);                                                          \
}                                                                              \
))                                                                             \
                                                                               \
(dec_ (                                                                        \
static inline T nstl_dec_(T)(T *self)                                          \
{                                                                              \
    return (*self)--;                                                          \
}                                                                              \
))                                                                             \
                                                                               \
(prom (                                                                        \
static inline T nstl_prom(T)(T self)                                           \
{                                                                              \
    return +self;                                                              \
}                                                                              \
))                                                                             \
                                                                               \
(inv (                                                                         \
static inline T nstl_inv(T)(T self)                                            \
{                                                                              \
    return -self;                                                              \
}                                                                              \
))                                                                             \
                                                                               \
/* Comparison operators / relational operators */                              \
(eq (                                                                          \
static inline bool nstl_eq(T, T)(T x, T y)                                     \
{                                                                              \
    return x == y;                                                             \
}                                                                              \
))                                                                             \
                                                                               \
(ne (                                                                          \
static inline bool nstl_ne(T, T)(T x, T y)                                     \
{                                                                              \
    return x != y;                                                             \
}                                                                              \
))                                                                             \
                                                                               \
(gt (                                                                          \
static inline bool nstl_gt(T, T)(T x, T y)                                     \
{                                                                              \
    return x > y;                                                              \
}                                                                              \
))                                                                             \
                                                                               \
(lt (                                                                          \
static inline bool nstl_lt(T, T)(T x, T y)                                     \
{                                                                              \
    return x < y;                                                              \
}                                                                              \
))                                                                             \
                                                                               \
(ge (                                                                          \
static inline bool nstl_ge(T, T)(T x, T y)                                     \
{                                                                              \
    return x >= y;                                                             \
}                                                                              \
))                                                                             \
                                                                               \
(le (                                                                          \
static inline bool nstl_le(T, T)(T x, T y)                                     \
{                                                                              \
    return x <= y;                                                             \
}                                                                              \
))                                                                             \
                                                                               \
/* Logical operators */                                                        \
(lognot (                                                                      \
static inline bool nstl_lognot(T)(T self)                                      \
{                                                                              \
    return !self;                                                              \
}                                                                              \
))                                                                             \
                                                                               \
(logand (                                                                      \
static inline bool nstl_logand(T, T)(T x, T y)                                 \
{                                                                              \
    return x && y;                                                             \
}                                                                              \
))                                                                             \
                                                                               \
(logor (                                                                       \
static inline bool nstl_logor(T, T)(T x, T y)                                  \
{                                                                              \
    return x || y;                                                             \
}                                                                              \
))                                                                             \
                                                                               \
/* Bitwise operators */                                                        \
(not (                                                                         \
static inline T nstl_not(T)(T self)                                            \
{                                                                              \
    return ~self;                                                              \
}                                                                              \
))                                                                             \
                                                                               \
(and (                                                                         \
static inline T nstl_and(T, T)(T x, T y)                                       \
{                                                                              \
    return x & y;                                                              \
}                                                                              \
))                                                                             \
                                                                               \
(or (                                                                          \
static inline T nstl_or(T, T)(T x, T y)                                        \
{                                                                              \
    return x | y;                                                              \
}                                                                              \
))                                                                             \
                                                                               \
(xor (                                                                         \
static inline T nstl_xor(T, T)(T x, T y)                                       \
{                                                                              \
    return x ^ y;                                                              \
}                                                                              \
))                                                                             \
                                                                               \
(lshift (                                                                      \
static inline T nstl_lshift(T, T)(T x, T y)                                    \
{                                                                              \
    return x << y;                                                             \
}                                                                              \
))                                                                             \
                                                                               \
(rshift (                                                                      \
static inline T nstl_rshift(T, T)(T x, T y)                                    \
{                                                                              \
    return x >> y;                                                             \
}                                                                              \
))                                                                             \
                                                                               \
/* Compound assignment operators */                                            \
(iadd (                                                                        \
static inline T nstl_iadd(T, T)(T *self, T other)                              \
{                                                                              \
    return (*self) += other;                                                   \
}                                                                              \
))                                                                             \
                                                                               \
(isub (                                                                        \
static inline T nstl_isub(T, T)(T *self, T other)                              \
{                                                                              \
    return (*self) -= other;                                                   \
}                                                                              \
))                                                                             \
                                                                               \
(imul (                                                                        \
static inline T nstl_imul(T, T)(T *self, T other)                              \
{                                                                              \
    return (*self) *= other;                                                   \
}                                                                              \
))                                                                             \
                                                                               \
(idiv (                                                                        \
static inline T nstl_idiv(T, T)(T *self, T other)                              \
{                                                                              \
    return (*self) /= other;                                                   \
}                                                                              \
))                                                                             \
                                                                               \
(iand (                                                                        \
static inline T nstl_iand(T, T)(T *self, T other)                              \
{                                                                              \
    return (*self) &= other;                                                   \
}                                                                              \
))                                                                             \
                                                                               \
(ior (                                                                         \
static inline T nstl_ior(T, T)(T *self, T other)                               \
{                                                                              \
    return (*self) |= other;                                                   \
}                                                                              \
))                                                                             \
                                                                               \
(ixor (                                                                        \
static inline T nstl_ixor(T, T)(T *self, T other)                              \
{                                                                              \
    return (*self) ^= other;                                                   \
}                                                                              \
))                                                                             \
                                                                               \
(ilshift (                                                                     \
static inline T nstl_ilshift(T, T)(T *self, T other)                           \
{                                                                              \
    return (*self) <<= other;                                                  \
}                                                                              \
))                                                                             \
                                                                               \
(irshift (                                                                     \
static inline T nstl_irshift(T, T)(T *self, T other)                           \
{                                                                              \
    return (*self) >>= other;                                                  \
}                                                                              \
))                                                                             \
)                                                                              \
/**/

#endif /* !NSTL_INTERNAL_PRIMITIVE_H */
