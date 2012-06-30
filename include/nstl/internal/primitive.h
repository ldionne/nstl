/*!
 * Implementation of a primitive type.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_PRIMITIVE_H
#define NSTL_INTERNAL_PRIMITIVE_H

#include <nstl/internal/type.h>

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>


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
                                                                               \
/* Other operators */                                                          \
(new (                                                                         \
static inline T *nstl_new(T)(void)                                             \
{                                                                              \
    return malloc(sizeof(T));                                                  \
}                                                                              \
))                                                                             \
                                                                               \
(delete (                                                                      \
static inline void nstl_delete(T)(T *self)                                     \
{                                                                              \
    free(self);                                                                \
}                                                                              \
))                                                                             \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
cog.outl(nstl.generate_attributes(
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
    'not(T)',       # ~
    'and(R, T)',    # &
    'or(R, T)',     # |
    'xor(R, T)',    # ^
    'lshift(R, T)', # <<
    'rshift(R, T)', # >>

    # Compound assignment operators
    'iadd(R, T)',    # +=
    'isub(R, T)',    # -=
    'imul(R, T)',    # *=
    'idiv(R, T)',    # /=
    'imod(R, T)',    # %=
    'iand(R, T)',    # &=
    'ior(R, T)',     # |=
    'ixor(R, T)',    # ^=
    'ilshift(R, T)', # <<=
    'irshift(R, T)', # >>=

    # Other operators
    'new(T)',    # new
    'delete(T)', # delete

    implement=True, token=True,
))

]]] */
#define NSTL_TOKEN_asg (a s g)
#define NSTL_INSTRUCTION_asg(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, asg, implementation)
#define nstl_asg(R,  T) JOY_CAT5(nstl_mangled_asg, _, R, _,  T)
#define NSTL_TOKEN_add (a d d)
#define NSTL_INSTRUCTION_add(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, add, implementation)
#define nstl_add(R,  T) JOY_CAT5(nstl_mangled_add, _, R, _,  T)
#define NSTL_TOKEN_sub (s u b)
#define NSTL_INSTRUCTION_sub(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, sub, implementation)
#define nstl_sub(R,  T) JOY_CAT5(nstl_mangled_sub, _, R, _,  T)
#define NSTL_TOKEN_mul (m u l)
#define NSTL_INSTRUCTION_mul(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, mul, implementation)
#define nstl_mul(R,  T) JOY_CAT5(nstl_mangled_mul, _, R, _,  T)
#define NSTL_TOKEN_div (d i v)
#define NSTL_INSTRUCTION_div(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, div, implementation)
#define nstl_div(R,  T) JOY_CAT5(nstl_mangled_div, _, R, _,  T)
#define NSTL_TOKEN_mod (m o d)
#define NSTL_INSTRUCTION_mod(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, mod, implementation)
#define nstl_mod(R,  T) JOY_CAT5(nstl_mangled_mod, _, R, _,  T)
#define NSTL_TOKEN_inc (i n c)
#define NSTL_INSTRUCTION_inc(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, inc, implementation)
#define nstl_inc(T) JOY_CAT3(nstl_mangled_inc, _, T)
#define NSTL_TOKEN_inc_ (i n c _)
#define NSTL_INSTRUCTION_inc_(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, inc_, implementation)
#define nstl_inc_(T) JOY_CAT3(nstl_mangled_inc_, _, T)
#define NSTL_TOKEN_dec (d e c)
#define NSTL_INSTRUCTION_dec(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, dec, implementation)
#define nstl_dec(T) JOY_CAT3(nstl_mangled_dec, _, T)
#define NSTL_TOKEN_dec_ (d e c _)
#define NSTL_INSTRUCTION_dec_(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, dec_, implementation)
#define nstl_dec_(T) JOY_CAT3(nstl_mangled_dec_, _, T)
#define NSTL_TOKEN_prom (p r o m)
#define NSTL_INSTRUCTION_prom(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, prom, implementation)
#define nstl_prom(T) JOY_CAT3(nstl_mangled_prom, _, T)
#define NSTL_TOKEN_inv (i n v)
#define NSTL_INSTRUCTION_inv(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, inv, implementation)
#define nstl_inv(T) JOY_CAT3(nstl_mangled_inv, _, T)
#define NSTL_TOKEN_eq (e q)
#define NSTL_INSTRUCTION_eq(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, eq, implementation)
#define nstl_eq(R,  T) JOY_CAT5(nstl_mangled_eq, _, R, _,  T)
#define NSTL_TOKEN_ne (n e)
#define NSTL_INSTRUCTION_ne(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, ne, implementation)
#define nstl_ne(R,  T) JOY_CAT5(nstl_mangled_ne, _, R, _,  T)
#define NSTL_TOKEN_gt (g t)
#define NSTL_INSTRUCTION_gt(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, gt, implementation)
#define nstl_gt(R,  T) JOY_CAT5(nstl_mangled_gt, _, R, _,  T)
#define NSTL_TOKEN_lt (l t)
#define NSTL_INSTRUCTION_lt(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, lt, implementation)
#define nstl_lt(R,  T) JOY_CAT5(nstl_mangled_lt, _, R, _,  T)
#define NSTL_TOKEN_ge (g e)
#define NSTL_INSTRUCTION_ge(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, ge, implementation)
#define nstl_ge(R,  T) JOY_CAT5(nstl_mangled_ge, _, R, _,  T)
#define NSTL_TOKEN_le (l e)
#define NSTL_INSTRUCTION_le(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, le, implementation)
#define nstl_le(R,  T) JOY_CAT5(nstl_mangled_le, _, R, _,  T)
#define NSTL_TOKEN_lognot (l o g n o t)
#define NSTL_INSTRUCTION_lognot(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, lognot, implementation)
#define nstl_lognot(T) JOY_CAT3(nstl_mangled_lognot, _, T)
#define NSTL_TOKEN_logand (l o g a n d)
#define NSTL_INSTRUCTION_logand(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, logand, implementation)
#define nstl_logand(R,  T) JOY_CAT5(nstl_mangled_logand, _, R, _,  T)
#define NSTL_TOKEN_logor (l o g o r)
#define NSTL_INSTRUCTION_logor(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, logor, implementation)
#define nstl_logor(R,  T) JOY_CAT5(nstl_mangled_logor, _, R, _,  T)
#define NSTL_TOKEN_not (n o t)
#define NSTL_INSTRUCTION_not(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, not, implementation)
#define nstl_not(T) JOY_CAT3(nstl_mangled_not, _, T)
#define NSTL_TOKEN_and (a n d)
#define NSTL_INSTRUCTION_and(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, and, implementation)
#define nstl_and(R,  T) JOY_CAT5(nstl_mangled_and, _, R, _,  T)
#define NSTL_TOKEN_or (o r)
#define NSTL_INSTRUCTION_or(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, or, implementation)
#define nstl_or(R,  T) JOY_CAT5(nstl_mangled_or, _, R, _,  T)
#define NSTL_TOKEN_xor (x o r)
#define NSTL_INSTRUCTION_xor(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, xor, implementation)
#define nstl_xor(R,  T) JOY_CAT5(nstl_mangled_xor, _, R, _,  T)
#define NSTL_TOKEN_lshift (l s h i f t)
#define NSTL_INSTRUCTION_lshift(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, lshift, implementation)
#define nstl_lshift(R,  T) JOY_CAT5(nstl_mangled_lshift, _, R, _,  T)
#define NSTL_TOKEN_rshift (r s h i f t)
#define NSTL_INSTRUCTION_rshift(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, rshift, implementation)
#define nstl_rshift(R,  T) JOY_CAT5(nstl_mangled_rshift, _, R, _,  T)
#define NSTL_TOKEN_iadd (i a d d)
#define NSTL_INSTRUCTION_iadd(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, iadd, implementation)
#define nstl_iadd(R,  T) JOY_CAT5(nstl_mangled_iadd, _, R, _,  T)
#define NSTL_TOKEN_isub (i s u b)
#define NSTL_INSTRUCTION_isub(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, isub, implementation)
#define nstl_isub(R,  T) JOY_CAT5(nstl_mangled_isub, _, R, _,  T)
#define NSTL_TOKEN_imul (i m u l)
#define NSTL_INSTRUCTION_imul(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, imul, implementation)
#define nstl_imul(R,  T) JOY_CAT5(nstl_mangled_imul, _, R, _,  T)
#define NSTL_TOKEN_idiv (i d i v)
#define NSTL_INSTRUCTION_idiv(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, idiv, implementation)
#define nstl_idiv(R,  T) JOY_CAT5(nstl_mangled_idiv, _, R, _,  T)
#define NSTL_TOKEN_imod (i m o d)
#define NSTL_INSTRUCTION_imod(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, imod, implementation)
#define nstl_imod(R,  T) JOY_CAT5(nstl_mangled_imod, _, R, _,  T)
#define NSTL_TOKEN_iand (i a n d)
#define NSTL_INSTRUCTION_iand(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, iand, implementation)
#define nstl_iand(R,  T) JOY_CAT5(nstl_mangled_iand, _, R, _,  T)
#define NSTL_TOKEN_ior (i o r)
#define NSTL_INSTRUCTION_ior(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, ior, implementation)
#define nstl_ior(R,  T) JOY_CAT5(nstl_mangled_ior, _, R, _,  T)
#define NSTL_TOKEN_ixor (i x o r)
#define NSTL_INSTRUCTION_ixor(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, ixor, implementation)
#define nstl_ixor(R,  T) JOY_CAT5(nstl_mangled_ixor, _, R, _,  T)
#define NSTL_TOKEN_ilshift (i l s h i f t)
#define NSTL_INSTRUCTION_ilshift(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, ilshift, implementation)
#define nstl_ilshift(R,  T) JOY_CAT5(nstl_mangled_ilshift, _, R, _,  T)
#define NSTL_TOKEN_irshift (i r s h i f t)
#define NSTL_INSTRUCTION_irshift(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, irshift, implementation)
#define nstl_irshift(R,  T) JOY_CAT5(nstl_mangled_irshift, _, R, _,  T)
#define NSTL_TOKEN_new (n e w)
#define NSTL_INSTRUCTION_new(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, new, implementation)
#define nstl_new(T) JOY_CAT3(nstl_mangled_new, _, T)
#define NSTL_TOKEN_delete (d e l e t e)
#define NSTL_INSTRUCTION_delete(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, delete, implementation)
#define nstl_delete(T) JOY_CAT3(nstl_mangled_delete, _, T)
/* [[[end]]] */

#endif /* !NSTL_INTERNAL_PRIMITIVE_H */
