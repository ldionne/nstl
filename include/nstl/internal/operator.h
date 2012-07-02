/*!
 * Definition of the basic operators in C.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_OPERATOR_H
#define NSTL_INTERNAL_OPERATOR_H

#include <nstl/type.h>

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>


#define NSTL_ARITHMETIC_OPERATORS(T)                                           \
NSTL_TYPE(                                                                     \
                                                                               \
(setf asg                                                                      \
static inline T nstl_asg(T, T)(T *self, T other)                               \
{                                                                              \
    return (*self) = other;                                                    \
}                                                                              \
)                                                                              \
                                                                               \
(setf add                                                                      \
static inline T nstl_add(T, T)(T x, T y)                                       \
{                                                                              \
    return x + y;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(setf sub                                                                      \
static inline T nstl_sub(T, T)(T x, T y)                                       \
{                                                                              \
    return x - y;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(setf mul                                                                      \
static inline T nstl_mul(T, T)(T x, T y)                                       \
{                                                                              \
    return x * y;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(setf div                                                                      \
static inline T nstl_div(T, T)(T x, T y)                                       \
{                                                                              \
    return x / y;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(setf mod                                                                      \
static inline T nstl_mod(T, T)(T x, T y)                                       \
{                                                                              \
    return x % y;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(setf inc                                                                      \
static inline T nstl_inc(T)(T *self)                                           \
{                                                                              \
    return ++(*self);                                                          \
}                                                                              \
)                                                                              \
                                                                               \
(setf inc_                                                                     \
static inline T nstl_inc_(T)(T *self)                                          \
{                                                                              \
    return (*self)++;                                                          \
}                                                                              \
)                                                                              \
                                                                               \
(setf dec                                                                      \
static inline T nstl_dec(T)(T *self)                                           \
{                                                                              \
    return --(*self);                                                          \
}                                                                              \
)                                                                              \
                                                                               \
(setf dec_                                                                     \
static inline T nstl_dec_(T)(T *self)                                          \
{                                                                              \
    return (*self)--;                                                          \
}                                                                              \
)                                                                              \
                                                                               \
(setf prom                                                                     \
static inline T nstl_prom(T)(T self)                                           \
{                                                                              \
    return +self;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(setf inv                                                                      \
static inline T nstl_inv(T)(T self)                                            \
{                                                                              \
    return -self;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(setf iadd                                                                     \
static inline T nstl_iadd(T, T)(T *self, T other)                              \
{                                                                              \
    return (*self) += other;                                                   \
}                                                                              \
)                                                                              \
                                                                               \
(setf isub                                                                     \
static inline T nstl_isub(T, T)(T *self, T other)                              \
{                                                                              \
    return (*self) -= other;                                                   \
}                                                                              \
)                                                                              \
                                                                               \
(setf imul                                                                     \
static inline T nstl_imul(T, T)(T *self, T other)                              \
{                                                                              \
    return (*self) *= other;                                                   \
}                                                                              \
)                                                                              \
                                                                               \
(setf idiv                                                                     \
static inline T nstl_idiv(T, T)(T *self, T other)                              \
{                                                                              \
    return (*self) /= other;                                                   \
}                                                                              \
)                                                                              \
                                                                               \
(setf imod                                                                     \
static inline T nstl_imod(T, T)(T *self, T other)                              \
{                                                                              \
    return (*self) %= other;                                                   \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#define NSTL_COMPARISON_OPERATORS(T)                                           \
NSTL_TYPE(                                                                     \
                                                                               \
(setf eq                                                                       \
static inline bool nstl_eq(T, T)(T x, T y)                                     \
{                                                                              \
    return x == y;                                                             \
}                                                                              \
)                                                                              \
                                                                               \
(setf ne                                                                       \
static inline bool nstl_ne(T, T)(T x, T y)                                     \
{                                                                              \
    return x != y;                                                             \
}                                                                              \
)                                                                              \
                                                                               \
(setf gt                                                                       \
static inline bool nstl_gt(T, T)(T x, T y)                                     \
{                                                                              \
    return x > y;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(setf lt                                                                       \
static inline bool nstl_lt(T, T)(T x, T y)                                     \
{                                                                              \
    return x < y;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(setf ge                                                                       \
static inline bool nstl_ge(T, T)(T x, T y)                                     \
{                                                                              \
    return x >= y;                                                             \
}                                                                              \
)                                                                              \
                                                                               \
(setf le                                                                       \
static inline bool nstl_le(T, T)(T x, T y)                                     \
{                                                                              \
    return x <= y;                                                             \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#define NSTL_LOGICAL_OPERATORS(T)                                              \
NSTL_TYPE(                                                                     \
                                                                               \
(setf lognot                                                                   \
static inline bool nstl_lognot(T)(T self)                                      \
{                                                                              \
    return !self;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(setf logand                                                                   \
static inline bool nstl_logand(T, T)(T x, T y)                                 \
{                                                                              \
    return x && y;                                                             \
}                                                                              \
)                                                                              \
                                                                               \
(setf logor                                                                    \
static inline bool nstl_logor(T, T)(T x, T y)                                  \
{                                                                              \
    return x || y;                                                             \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#define NSTL_BITWISE_OPERATORS(T)                                              \
NSTL_TYPE(                                                                     \
                                                                               \
(setf not                                                                      \
static inline T nstl_not(T)(T self)                                            \
{                                                                              \
    return ~self;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(setf and                                                                      \
static inline T nstl_and(T, T)(T x, T y)                                       \
{                                                                              \
    return x & y;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(setf or                                                                       \
static inline T nstl_or(T, T)(T x, T y)                                        \
{                                                                              \
    return x | y;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(setf xor                                                                      \
static inline T nstl_xor(T, T)(T x, T y)                                       \
{                                                                              \
    return x ^ y;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(setf lshift                                                                   \
static inline T nstl_lshift(T, T)(T x, T y)                                    \
{                                                                              \
    return x << y;                                                             \
}                                                                              \
)                                                                              \
                                                                               \
(setf rshift                                                                   \
static inline T nstl_rshift(T, T)(T x, T y)                                    \
{                                                                              \
    return x >> y;                                                             \
}                                                                              \
)                                                                              \
                                                                               \
(setf iand                                                                     \
static inline T nstl_iand(T, T)(T *self, T other)                              \
{                                                                              \
    return (*self) &= other;                                                   \
}                                                                              \
)                                                                              \
                                                                               \
(setf ior                                                                      \
static inline T nstl_ior(T, T)(T *self, T other)                               \
{                                                                              \
    return (*self) |= other;                                                   \
}                                                                              \
)                                                                              \
                                                                               \
(setf ixor                                                                     \
static inline T nstl_ixor(T, T)(T *self, T other)                              \
{                                                                              \
    return (*self) ^= other;                                                   \
}                                                                              \
)                                                                              \
                                                                               \
(setf ilshift                                                                  \
static inline T nstl_ilshift(T, T)(T *self, T other)                           \
{                                                                              \
    return (*self) <<= other;                                                  \
}                                                                              \
)                                                                              \
                                                                               \
(setf irshift                                                                  \
static inline T nstl_irshift(T, T)(T *self, T other)                           \
{                                                                              \
    return (*self) >>= other;                                                  \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#define NSTL_ALLOCATION_OPERATORS(T)                                           \
NSTL_TYPE(                                                                     \
                                                                               \
(setf new                                                                      \
static inline T *nstl_new(T)(void)                                             \
{                                                                              \
    return malloc(sizeof(T));                                                  \
}                                                                              \
)                                                                              \
                                                                               \
(setf delete                                                                   \
static inline void nstl_delete(T)(T *self)                                     \
{                                                                              \
    free(self);                                                                \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
cog.outl(nstl.generate_mangled(
    # Arithmetic operators
    'asg(R, T)',  # =
    'add(R, T)',  # +
    'sub(R, T)',  # -
    'mul(R, T)',  # *
    'div(R, T)',  # /
    'mod(R, T)',  # %
    'inc(T)',     # prefix ++
    'inc_(T)',    # postfix ++
    'dec(T)',     # prefix --
    'dec_(T)',    # postfix --
    'prom(T)',    # unary +
    'inv(T)',     # unary -
    'iadd(R, T)', # +=
    'isub(R, T)', # -=
    'imul(R, T)', # *=
    'idiv(R, T)', # /=
    'imod(R, T)', # %=

    # Comparison operators / relational operators
    'eq(R, T)', # ==
    'ne(R, T)', # !=
    'gt(R, T)', # >
    'lt(R, T)', # <
    'ge(R, T)', # >=
    'le(R, T)', # <=

    # Logical operators
    'lognot(T)',    # !
    'logand(R, T)', # &&
    'logor(R, T)',  # ||

    # Bitwise operators
    'not(T)',        # ~
    'and(R, T)',     # &
    'or(R, T)',      # |
    'xor(R, T)',     # ^
    'lshift(R, T)',  # <<
    'rshift(R, T)',  # >>
    'iand(R, T)',    # &=
    'ior(R, T)',     # |=
    'ixor(R, T)',    # ^=
    'ilshift(R, T)', # <<=
    'irshift(R, T)', # >>=

    # Allocation operators
    'new(T)',    # new
    'delete(T)', # delete
))

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_asg (a s g)
#define nstl_asg(R,  T) JOY_CAT5(nstl_mangled_asg, _, R, _,  T)
#define NSTL_TOKEN_add (a d d)
#define nstl_add(R,  T) JOY_CAT5(nstl_mangled_add, _, R, _,  T)
#define NSTL_TOKEN_sub (s u b)
#define nstl_sub(R,  T) JOY_CAT5(nstl_mangled_sub, _, R, _,  T)
#define NSTL_TOKEN_mul (m u l)
#define nstl_mul(R,  T) JOY_CAT5(nstl_mangled_mul, _, R, _,  T)
#define NSTL_TOKEN_div (d i v)
#define nstl_div(R,  T) JOY_CAT5(nstl_mangled_div, _, R, _,  T)
#define NSTL_TOKEN_mod (m o d)
#define nstl_mod(R,  T) JOY_CAT5(nstl_mangled_mod, _, R, _,  T)
#define NSTL_TOKEN_inc (i n c)
#define nstl_inc(T) JOY_CAT3(nstl_mangled_inc, _, T)
#define NSTL_TOKEN_inc_ (i n c _)
#define nstl_inc_(T) JOY_CAT3(nstl_mangled_inc_, _, T)
#define NSTL_TOKEN_dec (d e c)
#define nstl_dec(T) JOY_CAT3(nstl_mangled_dec, _, T)
#define NSTL_TOKEN_dec_ (d e c _)
#define nstl_dec_(T) JOY_CAT3(nstl_mangled_dec_, _, T)
#define NSTL_TOKEN_prom (p r o m)
#define nstl_prom(T) JOY_CAT3(nstl_mangled_prom, _, T)
#define NSTL_TOKEN_inv (i n v)
#define nstl_inv(T) JOY_CAT3(nstl_mangled_inv, _, T)
#define NSTL_TOKEN_iadd (i a d d)
#define nstl_iadd(R,  T) JOY_CAT5(nstl_mangled_iadd, _, R, _,  T)
#define NSTL_TOKEN_isub (i s u b)
#define nstl_isub(R,  T) JOY_CAT5(nstl_mangled_isub, _, R, _,  T)
#define NSTL_TOKEN_imul (i m u l)
#define nstl_imul(R,  T) JOY_CAT5(nstl_mangled_imul, _, R, _,  T)
#define NSTL_TOKEN_idiv (i d i v)
#define nstl_idiv(R,  T) JOY_CAT5(nstl_mangled_idiv, _, R, _,  T)
#define NSTL_TOKEN_imod (i m o d)
#define nstl_imod(R,  T) JOY_CAT5(nstl_mangled_imod, _, R, _,  T)
#define NSTL_TOKEN_eq (e q)
#define nstl_eq(R,  T) JOY_CAT5(nstl_mangled_eq, _, R, _,  T)
#define NSTL_TOKEN_ne (n e)
#define nstl_ne(R,  T) JOY_CAT5(nstl_mangled_ne, _, R, _,  T)
#define NSTL_TOKEN_gt (g t)
#define nstl_gt(R,  T) JOY_CAT5(nstl_mangled_gt, _, R, _,  T)
#define NSTL_TOKEN_lt (l t)
#define nstl_lt(R,  T) JOY_CAT5(nstl_mangled_lt, _, R, _,  T)
#define NSTL_TOKEN_ge (g e)
#define nstl_ge(R,  T) JOY_CAT5(nstl_mangled_ge, _, R, _,  T)
#define NSTL_TOKEN_le (l e)
#define nstl_le(R,  T) JOY_CAT5(nstl_mangled_le, _, R, _,  T)
#define NSTL_TOKEN_lognot (l o g n o t)
#define nstl_lognot(T) JOY_CAT3(nstl_mangled_lognot, _, T)
#define NSTL_TOKEN_logand (l o g a n d)
#define nstl_logand(R,  T) JOY_CAT5(nstl_mangled_logand, _, R, _,  T)
#define NSTL_TOKEN_logor (l o g o r)
#define nstl_logor(R,  T) JOY_CAT5(nstl_mangled_logor, _, R, _,  T)
#define NSTL_TOKEN_not (n o t)
#define nstl_not(T) JOY_CAT3(nstl_mangled_not, _, T)
#define NSTL_TOKEN_and (a n d)
#define nstl_and(R,  T) JOY_CAT5(nstl_mangled_and, _, R, _,  T)
#define NSTL_TOKEN_or (o r)
#define nstl_or(R,  T) JOY_CAT5(nstl_mangled_or, _, R, _,  T)
#define NSTL_TOKEN_xor (x o r)
#define nstl_xor(R,  T) JOY_CAT5(nstl_mangled_xor, _, R, _,  T)
#define NSTL_TOKEN_lshift (l s h i f t)
#define nstl_lshift(R,  T) JOY_CAT5(nstl_mangled_lshift, _, R, _,  T)
#define NSTL_TOKEN_rshift (r s h i f t)
#define nstl_rshift(R,  T) JOY_CAT5(nstl_mangled_rshift, _, R, _,  T)
#define NSTL_TOKEN_iand (i a n d)
#define nstl_iand(R,  T) JOY_CAT5(nstl_mangled_iand, _, R, _,  T)
#define NSTL_TOKEN_ior (i o r)
#define nstl_ior(R,  T) JOY_CAT5(nstl_mangled_ior, _, R, _,  T)
#define NSTL_TOKEN_ixor (i x o r)
#define nstl_ixor(R,  T) JOY_CAT5(nstl_mangled_ixor, _, R, _,  T)
#define NSTL_TOKEN_ilshift (i l s h i f t)
#define nstl_ilshift(R,  T) JOY_CAT5(nstl_mangled_ilshift, _, R, _,  T)
#define NSTL_TOKEN_irshift (i r s h i f t)
#define nstl_irshift(R,  T) JOY_CAT5(nstl_mangled_irshift, _, R, _,  T)
#define NSTL_TOKEN_new (n e w)
#define nstl_new(T) JOY_CAT3(nstl_mangled_new, _, T)
#define NSTL_TOKEN_delete (d e l e t e)
#define nstl_delete(T) JOY_CAT3(nstl_mangled_delete, _, T)
/* [[[end]]] */

#endif /* !NSTL_INTERNAL_OPERATOR_H */
