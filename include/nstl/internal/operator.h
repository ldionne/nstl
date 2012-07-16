/**
 * Definition of the basic operators in C, and definition
 * of commonly used tokens.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_OPERATOR_H
#define NSTL_INTERNAL_OPERATOR_H

#include <nstl/internal/boolean.h>
#include <nstl/internal/config.h>
#include <nstl/internal/type.h>
#include <nstl/internal/workaround.h>

#include <stddef.h>
#include <stdlib.h>


#define NSTL_INITIALIZATION_OPERATORS(T)                                       \
NSTL_TYPE(nstl_initialization_operators_ ## T,                                 \
                                                                               \
(defun ctor                                                                    \
static NSTL_INLINE void nstl_ctor(T)(T *self) {                                \
    NSTL_SILENCE_UNUSED_VARIABLE_WARNING(self);                                \
}                                                                              \
)                                                                              \
                                                                               \
(defun def_ctor                                                                \
static NSTL_INLINE void nstl_def_ctor(T)(T *self) {                            \
    NSTL_SILENCE_UNUSED_VARIABLE_WARNING(self);                                \
}                                                                              \
)                                                                              \
                                                                               \
(defun copy_ctor                                                               \
static NSTL_INLINE void nstl_copy_ctor(T)(T *self, T other) {                  \
    *self = other;                                                             \
}                                                                              \
)                                                                              \
                                                                               \
(defun dtor                                                                    \
static NSTL_INLINE void nstl_dtor(T)(T *self) {                                \
    NSTL_SILENCE_UNUSED_VARIABLE_WARNING(self);                                \
}                                                                              \
)                                                                              \
                                                                               \
(defun new                                                                     \
static NSTL_INLINE T *nstl_new(T)(void) {                                      \
    return malloc(sizeof(T));                                                  \
}                                                                              \
)                                                                              \
                                                                               \
(defun delete                                                                  \
static NSTL_INLINE void nstl_delete(T)(T *self) {                              \
    free(self);                                                                \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#define NSTL_ARITHMETIC_OPERATORS(T)                                           \
NSTL_TYPE(nstl_arithmetic_operators_ ## T,                                     \
                                                                               \
(defun asg                                                                     \
static NSTL_INLINE T nstl_asg(T, T)(T *self, T other) {                        \
    return (*self) = other;                                                    \
}                                                                              \
)                                                                              \
                                                                               \
(defun add                                                                     \
static NSTL_INLINE T nstl_add(T, T)(T x, T y) {                                \
    return x + y;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(defun sub                                                                     \
static NSTL_INLINE T nstl_sub(T, T)(T x, T y) {                                \
    return x - y;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(defun mul                                                                     \
static NSTL_INLINE T nstl_mul(T, T)(T x, T y) {                                \
    return x * y;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(defun div                                                                     \
static NSTL_INLINE T nstl_div(T, T)(T x, T y) {                                \
    return x / y;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(defun mod                                                                     \
static NSTL_INLINE T nstl_mod(T, T)(T x, T y) {                                \
    return x % y;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(defun inc                                                                     \
static NSTL_INLINE T nstl_inc(T)(T *self) {                                    \
    return ++(*self);                                                          \
}                                                                              \
)                                                                              \
                                                                               \
(defun inc_                                                                    \
static NSTL_INLINE T nstl_inc_(T)(T *self) {                                   \
    return (*self)++;                                                          \
}                                                                              \
)                                                                              \
                                                                               \
(defun dec                                                                     \
static NSTL_INLINE T nstl_dec(T)(T *self) {                                    \
    return --(*self);                                                          \
}                                                                              \
)                                                                              \
                                                                               \
(defun dec_                                                                    \
static NSTL_INLINE T nstl_dec_(T)(T *self) {                                   \
    return (*self)--;                                                          \
}                                                                              \
)                                                                              \
                                                                               \
(defun prom                                                                    \
static NSTL_INLINE T nstl_prom(T)(T self) {                                    \
    return +self;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(defun inv                                                                     \
static NSTL_INLINE T nstl_inv(T)(T self) {                                     \
    return -self;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(defun iadd                                                                    \
static NSTL_INLINE T nstl_iadd(T, T)(T *self, T other) {                       \
    return (*self) += other;                                                   \
}                                                                              \
)                                                                              \
                                                                               \
(defun isub                                                                    \
static NSTL_INLINE T nstl_isub(T, T)(T *self, T other) {                       \
    return (*self) -= other;                                                   \
}                                                                              \
)                                                                              \
                                                                               \
(defun imul                                                                    \
static NSTL_INLINE T nstl_imul(T, T)(T *self, T other) {                       \
    return (*self) *= other;                                                   \
}                                                                              \
)                                                                              \
                                                                               \
(defun idiv                                                                    \
static NSTL_INLINE T nstl_idiv(T, T)(T *self, T other) {                       \
    return (*self) /= other;                                                   \
}                                                                              \
)                                                                              \
                                                                               \
(defun imod                                                                    \
static NSTL_INLINE T nstl_imod(T, T)(T *self, T other) {                       \
    return (*self) %= other;                                                   \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#define NSTL_COMPARISON_OPERATORS(T)                                           \
NSTL_TYPE(nstl_comparison_operators_ ## T,                                     \
                                                                               \
(defun eq                                                                      \
static NSTL_INLINE nstl_bool nstl_eq(T, T)(T x, T y) {                         \
    return x == y;                                                             \
}                                                                              \
)                                                                              \
                                                                               \
(defun ne                                                                      \
static NSTL_INLINE nstl_bool nstl_ne(T, T)(T x, T y) {                         \
    return x != y;                                                             \
}                                                                              \
)                                                                              \
                                                                               \
(defun gt                                                                      \
static NSTL_INLINE nstl_bool nstl_gt(T, T)(T x, T y) {                         \
    return x > y;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(defun lt                                                                      \
static NSTL_INLINE nstl_bool nstl_lt(T, T)(T x, T y) {                         \
    return x < y;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(defun ge                                                                      \
static NSTL_INLINE nstl_bool nstl_ge(T, T)(T x, T y) {                         \
    return x >= y;                                                             \
}                                                                              \
)                                                                              \
                                                                               \
(defun le                                                                      \
static NSTL_INLINE nstl_bool nstl_le(T, T)(T x, T y) {                         \
    return x <= y;                                                             \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#define NSTL_LOGICAL_OPERATORS(T)                                              \
NSTL_TYPE(nstl_logical_operators_ ## T,                                        \
                                                                               \
(defun not                                                                     \
static NSTL_INLINE nstl_bool nstl_not(T)(T self) {                             \
    return !self;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#define NSTL_BITWISE_OPERATORS(T)                                              \
NSTL_TYPE(nstl_bitwise_operators_ ## T,                                        \
                                                                               \
(defun compl                                                                   \
static NSTL_INLINE T nstl_compl(T)(T self) {                                   \
    return ~self;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(defun and                                                                     \
static NSTL_INLINE T nstl_and(T, T)(T x, T y) {                                \
    return x & y;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(defun or                                                                      \
static NSTL_INLINE T nstl_or(T, T)(T x, T y) {                                 \
    return x | y;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(defun xor                                                                     \
static NSTL_INLINE T nstl_xor(T, T)(T x, T y) {                                \
    return x ^ y;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(defun lshift                                                                  \
static NSTL_INLINE T nstl_lshift(T, T)(T x, T y) {                             \
    return x << y;                                                             \
}                                                                              \
)                                                                              \
                                                                               \
(defun rshift                                                                  \
static NSTL_INLINE T nstl_rshift(T, T)(T x, T y) {                             \
    return x >> y;                                                             \
}                                                                              \
)                                                                              \
                                                                               \
(defun iand                                                                    \
static NSTL_INLINE T nstl_iand(T, T)(T *self, T other) {                       \
    return (*self) &= other;                                                   \
}                                                                              \
)                                                                              \
                                                                               \
(defun ior                                                                     \
static NSTL_INLINE T nstl_ior(T, T)(T *self, T other) {                        \
    return (*self) |= other;                                                   \
}                                                                              \
)                                                                              \
                                                                               \
(defun ixor                                                                    \
static NSTL_INLINE T nstl_ixor(T, T)(T *self, T other) {                       \
    return (*self) ^= other;                                                   \
}                                                                              \
)                                                                              \
                                                                               \
(defun ilshift                                                                 \
static NSTL_INLINE T nstl_ilshift(T, T)(T *self, T other) {                    \
    return (*self) <<= other;                                                  \
}                                                                              \
)                                                                              \
                                                                               \
(defun irshift                                                                 \
static NSTL_INLINE T nstl_irshift(T, T)(T *self, T other) {                    \
    return (*self) >>= other;                                                  \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl

NSTL_OPERATORS = [
    # Initialization / deinitialization / allocation operators
    'ctor(T)',      # Principal constructor (most useful)
    'def_ctor(T)',  # T()
    'copy_ctor(T)', # T(T other)
    'dtor(T)',      # ~T
    'new(T)',       # new
    'delete(T)',    # delete

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
    'lt(R, T)', # <
    'ge(R, T)', # >=
    'le(R, T)', # <=

    # Logical operators
    'not(T)', # !

    # Bitwise operators
    'compl(T)',      # ~
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
]

NSTL_COMMON_FIELDS = [
    # Extended initialization / deinitialization
    'size_ctor(T)',
    'fill_ctor(T)',
    'range_ctor(T, InputIter)',

    # Iterators
    'begin(T)',
    'end(T)',
    'rbegin(T)',
    'rend(T)',

    # Element access
    'at(T)',
    'front(T)',
    'back(T)',

    # Capacity
    'empty(T)',
    'size(T)',
    'max_size(T)',
    'capacity(T)',
    'reserve(T)',

    # Modification
    'push_back(T)',
    'pop_back(T)',
    'clear(T)',
]

ALPHANUM = list(
            '_0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ')

C_CPP_KEYWORDS = [
    '_Bool', '_Complex', '_Imaginary',
    'alignas', 'alignof', 'and', 'and_eq', 'asm', 'auto',
    'bitand', 'bitor', 'bool', 'break',
    'case', 'catch', 'char', 'char16_t', 'char32_t', 'class', 'compl',
    'const', 'constexpr', 'const_cast', 'continue',
    'decltype', 'default', 'delete', 'do', 'double', 'dynamic_cast',
    'else', 'enum', 'explicit', 'export', 'extern',
    'false', 'final', 'float', 'for', 'friend',
    'goto',
    'if', 'inline', 'int',
    'long',
    'mutable',
    'namespace', 'new', 'noexcept', 'not', 'not_eq', 'nullptr',
    'operator', 'or', 'or_eq', 'override',
    'private', 'protected', 'public',
    'register', 'reinterpret_cast', 'restrict', 'return',
    'short', 'signed', 'sizeof', 'static', 'static_assert', 'static_cast',
    'struct', 'switch',
    'template', 'this', 'thread_local', 'throw', 'true', 'try', 'typedef',
    'typeid', 'typename',
    'union', 'unsigned', 'using',
    'virtual', 'void', 'volatile',
    'wchar_t', 'while',
    'xor', 'xor_eq',
]

nstl.generate(cog,
    *set(NSTL_OPERATORS + NSTL_COMMON_FIELDS + ALPHANUM + C_CPP_KEYWORDS),
                                                                token=True)

nstl.generate(cog,
    *set(NSTL_OPERATORS + NSTL_COMMON_FIELDS), mangle=True)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_iadd (i a d d)
#define NSTL_TOKEN_rbegin (r b e g i n)
#define NSTL_TOKEN_mod (m o d)
#define NSTL_TOKEN_clear (c l e a r)
#define NSTL_TOKEN_using (u s i n g)
#define NSTL_TOKEN_le (l e)
#define NSTL_TOKEN_bitor (b i t o r)
#define NSTL_TOKEN_ctor (c t o r)
#define NSTL_TOKEN_eq (e q)
#define NSTL_TOKEN_reserve (r e s e r v e)
#define NSTL_TOKEN_imul (i m u l)
#define NSTL_TOKEN_static_assert (s t a t i c _ a s s e r t)
#define NSTL_TOKEN_const (c o n s t)
#define NSTL_TOKEN_struct (s t r u c t)
#define NSTL_TOKEN_true (t r u e)
#define NSTL_TOKEN_thread_local (t h r e a d _ l o c a l)
#define NSTL_TOKEN_unsigned (u n s i g n e d)
#define NSTL_TOKEN_alignas (a l i g n a s)
#define NSTL_TOKEN_0 (0)
#define NSTL_TOKEN_4 (4)
#define NSTL_TOKEN_dec_ (d e c _)
#define NSTL_TOKEN_override (o v e r r i d e)
#define NSTL_TOKEN_8 (8)
#define NSTL_TOKEN_typedef (t y p e d e f)
#define NSTL_TOKEN_asg (a s g)
#define NSTL_TOKEN_do (d o)
#define NSTL_TOKEN_return (r e t u r n)
#define NSTL_TOKEN_D (D)
#define NSTL_TOKEN_H (H)
#define NSTL_TOKEN_imod (i m o d)
#define NSTL_TOKEN_L (L)
#define NSTL_TOKEN_break (b r e a k)
#define NSTL_TOKEN_P (P)
#define NSTL_TOKEN_capacity (c a p a c i t y)
#define NSTL_TOKEN_ilshift (i l s h i f t)
#define NSTL_TOKEN_T (T)
#define NSTL_TOKEN_not (n o t)
#define NSTL_TOKEN_X (X)
#define NSTL_TOKEN_front (f r o n t)
#define NSTL_TOKEN_d (d)
#define NSTL_TOKEN_auto (a u t o)
#define NSTL_TOKEN_h (h)
#define NSTL_TOKEN_nullptr (n u l l p t r)
#define NSTL_TOKEN_l (l)
#define NSTL_TOKEN_prom (p r o m)
#define NSTL_TOKEN_p (p)
#define NSTL_TOKEN_continue (c o n t i n u e)
#define NSTL_TOKEN_t (t)
#define NSTL_TOKEN_x (x)
#define NSTL_TOKEN_char32_t (c h a r 3 2 _ t)
#define NSTL_TOKEN_idiv (i d i v)
#define NSTL_TOKEN_inc_ (i n c _)
#define NSTL_TOKEN_inv (i n v)
#define NSTL_TOKEN_rend (r e n d)
#define NSTL_TOKEN_dec (d e c)
#define NSTL_TOKEN_export (e x p o r t)
#define NSTL_TOKEN_sizeof (s i z e o f)
#define NSTL_TOKEN_size_ctor (s i z e _ c t o r)
#define NSTL_TOKEN_try (t r y)
#define NSTL_TOKEN_decltype (d e c l t y p e)
#define NSTL_TOKEN_end (e n d)
#define NSTL_TOKEN_and (a n d)
#define NSTL_TOKEN_add (a d d)
#define NSTL_TOKEN_I (I)
#define NSTL_TOKEN_3 (3)
#define NSTL_TOKEN_protected (p r o t e c t e d)
#define NSTL_TOKEN_ne (n e)
#define NSTL_TOKEN_7 (7)
#define NSTL_TOKEN_char16_t (c h a r 1 6 _ t)
#define NSTL_TOKEN_new (n e w)
#define NSTL_TOKEN_dynamic_cast (d y n a m i c _ c a s t)
#define NSTL_TOKEN_template (t e m p l a t e)
#define NSTL_TOKEN_public (p u b l i c)
#define NSTL_TOKEN__Complex (_ C o m p l e x)
#define NSTL_TOKEN_C (C)
#define NSTL_TOKEN_sub (s u b)
#define NSTL_TOKEN_goto (g o t o)
#define NSTL_TOKEN_G (G)
#define NSTL_TOKEN_M (M)
#define NSTL_TOKEN_K (K)
#define NSTL_TOKEN_enum (e n u m)
#define NSTL_TOKEN_xor (x o r)
#define NSTL_TOKEN_O (O)
#define NSTL_TOKEN_pop_back (p o p _ b a c k)
#define NSTL_TOKEN_constexpr (c o n s t e x p r)
#define NSTL_TOKEN_S (S)
#define NSTL_TOKEN_W (W)
#define NSTL_TOKEN_not_eq (n o t _ e q)
#define NSTL_TOKEN_throw (t h r o w)
#define NSTL_TOKEN__ (_)
#define NSTL_TOKEN_c (c)
#define NSTL_TOKEN_volatile (v o l a t i l e)
#define NSTL_TOKEN_g (g)
#define NSTL_TOKEN_def_ctor (d e f _ c t o r)
#define NSTL_TOKEN_copy_ctor (c o p y _ c t o r)
#define NSTL_TOKEN_k (k)
#define NSTL_TOKEN_bitand (b i t a n d)
#define NSTL_TOKEN_o (o)
#define NSTL_TOKEN_s (s)
#define NSTL_TOKEN_iand (i a n d)
#define NSTL_TOKEN_w (w)
#define NSTL_TOKEN_lshift (l s h i f t)
#define NSTL_TOKEN_explicit (e x p l i c i t)
#define NSTL_TOKEN_this (t h i s)
#define NSTL_TOKEN__Bool (_ B o o l)
#define NSTL_TOKEN_float (f l o a t)
#define NSTL_TOKEN_private (p r i v a t e)
#define NSTL_TOKEN_restrict (r e s t r i c t)
#define NSTL_TOKEN_extern (e x t e r n)
#define NSTL_TOKEN_not (n o t)
#define NSTL_TOKEN_operator (o p e r a t o r)
#define NSTL_TOKEN_false (f a l s e)
#define NSTL_TOKEN_bool (b o o l)
#define NSTL_TOKEN_fill_ctor (f i l l _ c t o r)
#define NSTL_TOKEN__Imaginary (_ I m a g i n a r y)
#define NSTL_TOKEN_ixor (i x o r)
#define NSTL_TOKEN_const_cast (c o n s t _ c a s t)
#define NSTL_TOKEN_static_cast (s t a t i c _ c a s t)
#define NSTL_TOKEN_union (u n i o n)
#define NSTL_TOKEN_long (l o n g)
#define NSTL_TOKEN_begin (b e g i n)
#define NSTL_TOKEN_2 (2)
#define NSTL_TOKEN_asm (a s m)
#define NSTL_TOKEN_6 (6)
#define NSTL_TOKEN_empty (e m p t y)
#define NSTL_TOKEN_final (f i n a l)
#define NSTL_TOKEN_friend (f r i e n d)
#define NSTL_TOKEN_B (B)
#define NSTL_TOKEN_dtor (d t o r)
#define NSTL_TOKEN_J (J)
#define NSTL_TOKEN_N (N)
#define NSTL_TOKEN_div (d i v)
#define NSTL_TOKEN_V (V)
#define NSTL_TOKEN_catch (c a t c h)
#define NSTL_TOKEN_Z (Z)
#define NSTL_TOKEN_max_size (m a x _ s i z e)
#define NSTL_TOKEN_case (c a s e)
#define NSTL_TOKEN_b (b)
#define NSTL_TOKEN_reinterpret_cast (r e i n t e r p r e t _ c a s t)
#define NSTL_TOKEN_f (f)
#define NSTL_TOKEN_default (d e f a u l t)
#define NSTL_TOKEN_double (d o u b l e)
#define NSTL_TOKEN_noexcept (n o e x c e p t)
#define NSTL_TOKEN_j (j)
#define NSTL_TOKEN_signed (s i g n e d)
#define NSTL_TOKEN_n (n)
#define NSTL_TOKEN_typename (t y p e n a m e)
#define NSTL_TOKEN_while (w h i l e)
#define NSTL_TOKEN_r (r)
#define NSTL_TOKEN_wchar_t (w c h a r _ t)
#define NSTL_TOKEN_v (v)
#define NSTL_TOKEN_static (s t a t i c)
#define NSTL_TOKEN_gt (g t)
#define NSTL_TOKEN_z (z)
#define NSTL_TOKEN_new (n e w)
#define NSTL_TOKEN_delete (d e l e t e)
#define NSTL_TOKEN_and (a n d)
#define NSTL_TOKEN_or (o r)
#define NSTL_TOKEN_int (i n t)
#define NSTL_TOKEN_back (b a c k)
#define NSTL_TOKEN_ior (i o r)
#define NSTL_TOKEN_char (c h a r)
#define NSTL_TOKEN_lt (l t)
#define NSTL_TOKEN_push_back (p u s h _ b a c k)
#define NSTL_TOKEN_R (R)
#define NSTL_TOKEN_irshift (i r s h i f t)
#define NSTL_TOKEN_if (i f)
#define NSTL_TOKEN_F (F)
#define NSTL_TOKEN_xor_eq (x o r _ e q)
#define NSTL_TOKEN_range_ctor (r a n g e _ c t o r)
#define NSTL_TOKEN_namespace (n a m e s p a c e)
#define NSTL_TOKEN_virtual (v i r t u a l)
#define NSTL_TOKEN_1 (1)
#define NSTL_TOKEN_5 (5)
#define NSTL_TOKEN_delete (d e l e t e)
#define NSTL_TOKEN_9 (9)
#define NSTL_TOKEN_mutable (m u t a b l e)
#define NSTL_TOKEN_or_eq (o r _ e q)
#define NSTL_TOKEN_isub (i s u b)
#define NSTL_TOKEN_void (v o i d)
#define NSTL_TOKEN_A (A)
#define NSTL_TOKEN_and_eq (a n d _ e q)
#define NSTL_TOKEN_E (E)
#define NSTL_TOKEN_alignof (a l i g n o f)
#define NSTL_TOKEN_mul (m u l)
#define NSTL_TOKEN_compl (c o m p l)
#define NSTL_TOKEN_compl (c o m p l)
#define NSTL_TOKEN_inc (i n c)
#define NSTL_TOKEN_Q (Q)
#define NSTL_TOKEN_size (s i z e)
#define NSTL_TOKEN_U (U)
#define NSTL_TOKEN_at (a t)
#define NSTL_TOKEN_Y (Y)
#define NSTL_TOKEN_xor (x o r)
#define NSTL_TOKEN_else (e l s e)
#define NSTL_TOKEN_class (c l a s s)
#define NSTL_TOKEN_a (a)
#define NSTL_TOKEN_typeid (t y p e i d)
#define NSTL_TOKEN_short (s h o r t)
#define NSTL_TOKEN_e (e)
#define NSTL_TOKEN_for (f o r)
#define NSTL_TOKEN_i (i)
#define NSTL_TOKEN_register (r e g i s t e r)
#define NSTL_TOKEN_m (m)
#define NSTL_TOKEN_or (o r)
#define NSTL_TOKEN_q (q)
#define NSTL_TOKEN_switch (s w i t c h)
#define NSTL_TOKEN_ge (g e)
#define NSTL_TOKEN_u (u)
#define NSTL_TOKEN_rshift (r s h i f t)
#define NSTL_TOKEN_y (y)
#define NSTL_TOKEN_inline (i n l i n e)
#include <joy/cat.h>
#define nstl_inc_(T) JOY_CAT3(nstl_mangled_inc_, _, T)
#define nstl_or(R,  T) JOY_CAT5(nstl_mangled_or, _, R, _,  T)
#define nstl_rbegin(T) JOY_CAT3(nstl_mangled_rbegin, _, T)
#define nstl_inv(T) JOY_CAT3(nstl_mangled_inv, _, T)
#define nstl_back(T) JOY_CAT3(nstl_mangled_back, _, T)
#define nstl_ior(R,  T) JOY_CAT5(nstl_mangled_ior, _, R, _,  T)
#define nstl_range_ctor(T,  InputIter) JOY_CAT5(nstl_mangled_range_ctor, _, T, _,  InputIter)
#define nstl_mod(R,  T) JOY_CAT5(nstl_mangled_mod, _, R, _,  T)
#define nstl_clear(T) JOY_CAT3(nstl_mangled_clear, _, T)
#define nstl_rend(T) JOY_CAT3(nstl_mangled_rend, _, T)
#define nstl_not(T) JOY_CAT3(nstl_mangled_not, _, T)
#define nstl_dec(T) JOY_CAT3(nstl_mangled_dec, _, T)
#define nstl_push_back(T) JOY_CAT3(nstl_mangled_push_back, _, T)
#define nstl_le(R,  T) JOY_CAT5(nstl_mangled_le, _, R, _,  T)
#define nstl_ctor(T) JOY_CAT3(nstl_mangled_ctor, _, T)
#define nstl_iadd(R,  T) JOY_CAT5(nstl_mangled_iadd, _, R, _,  T)
#define nstl_reserve(T) JOY_CAT3(nstl_mangled_reserve, _, T)
#define nstl_imul(R,  T) JOY_CAT5(nstl_mangled_imul, _, R, _,  T)
#define nstl_ixor(R,  T) JOY_CAT5(nstl_mangled_ixor, _, R, _,  T)
#define nstl_end(T) JOY_CAT3(nstl_mangled_end, _, T)
#define nstl_and(R,  T) JOY_CAT5(nstl_mangled_and, _, R, _,  T)
#define nstl_add(R,  T) JOY_CAT5(nstl_mangled_add, _, R, _,  T)
#define nstl_size(T) JOY_CAT3(nstl_mangled_size, _, T)
#define nstl_eq(R,  T) JOY_CAT5(nstl_mangled_eq, _, R, _,  T)
#define nstl_size_ctor(T) JOY_CAT3(nstl_mangled_size_ctor, _, T)
#define nstl_begin(T) JOY_CAT3(nstl_mangled_begin, _, T)
#define nstl_ge(R,  T) JOY_CAT5(nstl_mangled_ge, _, R, _,  T)
#define nstl_ne(R,  T) JOY_CAT5(nstl_mangled_ne, _, R, _,  T)
#define nstl_delete(T) JOY_CAT3(nstl_mangled_delete, _, T)
#define nstl_isub(R,  T) JOY_CAT5(nstl_mangled_isub, _, R, _,  T)
#define nstl_asg(R,  T) JOY_CAT5(nstl_mangled_asg, _, R, _,  T)
#define nstl_iand(R,  T) JOY_CAT5(nstl_mangled_iand, _, R, _,  T)
#define nstl_sub(R,  T) JOY_CAT5(nstl_mangled_sub, _, R, _,  T)
#define nstl_dtor(T) JOY_CAT3(nstl_mangled_dtor, _, T)
#define nstl_mul(R,  T) JOY_CAT5(nstl_mangled_mul, _, R, _,  T)
#define nstl_imod(R,  T) JOY_CAT5(nstl_mangled_imod, _, R, _,  T)
#define nstl_dec_(T) JOY_CAT3(nstl_mangled_dec_, _, T)
#define nstl_compl(T) JOY_CAT3(nstl_mangled_compl, _, T)
#define nstl_xor(R,  T) JOY_CAT5(nstl_mangled_xor, _, R, _,  T)
#define nstl_inc(T) JOY_CAT3(nstl_mangled_inc, _, T)
#define nstl_empty(T) JOY_CAT3(nstl_mangled_empty, _, T)
#define nstl_div(R,  T) JOY_CAT5(nstl_mangled_div, _, R, _,  T)
#define nstl_fill_ctor(T) JOY_CAT3(nstl_mangled_fill_ctor, _, T)
#define nstl_at(T) JOY_CAT3(nstl_mangled_at, _, T)
#define nstl_front(T) JOY_CAT3(nstl_mangled_front, _, T)
#define nstl_pop_back(T) JOY_CAT3(nstl_mangled_pop_back, _, T)
#define nstl_max_size(T) JOY_CAT3(nstl_mangled_max_size, _, T)
#define nstl_ilshift(R,  T) JOY_CAT5(nstl_mangled_ilshift, _, R, _,  T)
#define nstl_def_ctor(T) JOY_CAT3(nstl_mangled_def_ctor, _, T)
#define nstl_copy_ctor(T) JOY_CAT3(nstl_mangled_copy_ctor, _, T)
#define nstl_capacity(T) JOY_CAT3(nstl_mangled_capacity, _, T)
#define nstl_prom(T) JOY_CAT3(nstl_mangled_prom, _, T)
#define nstl_lt(R,  T) JOY_CAT5(nstl_mangled_lt, _, R, _,  T)
#define nstl_rshift(R,  T) JOY_CAT5(nstl_mangled_rshift, _, R, _,  T)
#define nstl_lshift(R,  T) JOY_CAT5(nstl_mangled_lshift, _, R, _,  T)
#define nstl_irshift(R,  T) JOY_CAT5(nstl_mangled_irshift, _, R, _,  T)
#define nstl_gt(R,  T) JOY_CAT5(nstl_mangled_gt, _, R, _,  T)
#define nstl_idiv(R,  T) JOY_CAT5(nstl_mangled_idiv, _, R, _,  T)
#define nstl_new(T) JOY_CAT3(nstl_mangled_new, _, T)
/* [[[end]]] */

#endif /* !NSTL_INTERNAL_OPERATOR_H */
