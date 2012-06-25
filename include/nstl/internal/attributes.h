/*!
 * Automatic generation of nstl type attributes.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_ATTRIBUTES_H
#define NSTL_INTERNAL_ATTRIBUTES_H

#include <chaos/preprocessor.h>
#include <joy/object.h>
#include <joy/map/to_seq.h>
#include <joy/cat.h>


#define CHAOS_IP_STRING_drop (drop)
#define NSTL_INSTRUCTION_drop(s, self, method) \
    JOY_OBJECT_DELATTR_S(s, self, NSTL_ATTRIBUTE(method))

#define CHAOS_IP_STRING_implement (implement)
#define NSTL_INSTRUCTION_implement(s, self, attr, implementation) \
    JOY_OBJECT_SETATTR_S(s, self, NSTL_ATTRIBUTE(attr), implementation)

#define CHAOS_IP_STRING_inherit (inherit)
#define NSTL_INSTRUCTION_inherit(s, self, base_type) \
    JOY_OBJECT_CLONE_S(s, base_type, JOY_MAP_TO_SEQ_S(s, self))


/* [[[cog

TYPES = [
    'value_type',
    'pointer', 'const_pointer',
    'reference', 'const_reference',
    'size_type', 'difference_type',
    'iterator', 'const_iterator',
    'reverse_iterator', 'const_reverse_iterator'
]

OPERATORS = [
    # Arithmetic operators
    'asg',  # =
    'add',  # +
    'sub',  # -
    'mul',  # *
    'div',  # /
    'mod',  # %
    'inc',  # prefix ++
    'inc_', # postfix ++
    'dec',  # prefix --
    'dec_', # postfix --
    'prom', # unary +
    'inv',  # unary -

    # Comparison operators / relational operators
    'eq', # ==
    'ne', # !=
    'gt', # >
    'lt', # <
    'ge', # >=
    'le', # <=

    # Logical operators
    'lognot', # !
    'logand', # &&
    'logor',  # ||

    # Bitwise operators
    'not',    # ~
    'and',    # &
    'or',     # |
    'xor',    # ^
    'lshift', # <<
    'rshift', # >>

    # Compound assignment operators
    'iadd',    # +=
    'isub',    # -=
    'imul',    # *=
    'idiv',    # /=
    'imod',    # %=
    'iand',    # &=
    'ior',     # |=
    'ixor',    # ^=
    'ilshift', # <<=
    'irshift', # >>=

    # Member and pointer operators
    'subscript',  # [ ]
    'deref',      # *

    # Other operators
    'call',    # ( )
    'sizeof',  # sizeof
    'alignof', # alignof
    'new',     # new
    'delete',  # delete
]

METHODS = [
    'init',    # ctor
    'init_cp', # copy_ctor
    'deinit',  # dtor

    'init_n', 'init_range',

    'begin', 'end',
    'rbegin', 'rend',

    'push_back', 'push_front'
]

MISC = [
    'other', 'struct',
]

ATTRIBUTES = TYPES + OPERATORS + METHODS + MISC


def as_attribute(attr):
    return "#define NSTL_ATTRIBUTE_{} {}".format(attr, " ".join(attr))

def as_instruction(attr):
    return """#define NSTL_INSTRUCTION_{0}(s, self, implementation) \\
    NSTL_INSTRUCTION_implement(s, self, {0}, implementation)""".format(attr)

def as_pp_string(attr):
    return "#define CHAOS_IP_STRING_{0} ({0})".format(attr)

def mangled(attr):
    return """#define nstl_{0}(x) \\
    JOY_CAT3(nstl_attribute_{0}, _, x)""".format(attr)


TRANSFORMATIONS = [as_attribute, as_instruction, as_pp_string, mangled]

f = lambda trans, coll: cog.outl("\n".join(map(trans, coll)))
for trans in TRANSFORMATIONS:
    f(trans, ATTRIBUTES)

]]] */
#define NSTL_ATTRIBUTE_value_type v a l u e _ t y p e
#define NSTL_ATTRIBUTE_pointer p o i n t e r
#define NSTL_ATTRIBUTE_const_pointer c o n s t _ p o i n t e r
#define NSTL_ATTRIBUTE_reference r e f e r e n c e
#define NSTL_ATTRIBUTE_const_reference c o n s t _ r e f e r e n c e
#define NSTL_ATTRIBUTE_size_type s i z e _ t y p e
#define NSTL_ATTRIBUTE_difference_type d i f f e r e n c e _ t y p e
#define NSTL_ATTRIBUTE_iterator i t e r a t o r
#define NSTL_ATTRIBUTE_const_iterator c o n s t _ i t e r a t o r
#define NSTL_ATTRIBUTE_reverse_iterator r e v e r s e _ i t e r a t o r
#define NSTL_ATTRIBUTE_const_reverse_iterator c o n s t _ r e v e r s e _ i t e r a t o r
#define NSTL_ATTRIBUTE_asg a s g
#define NSTL_ATTRIBUTE_add a d d
#define NSTL_ATTRIBUTE_sub s u b
#define NSTL_ATTRIBUTE_mul m u l
#define NSTL_ATTRIBUTE_div d i v
#define NSTL_ATTRIBUTE_mod m o d
#define NSTL_ATTRIBUTE_inc i n c
#define NSTL_ATTRIBUTE_inc_ i n c _
#define NSTL_ATTRIBUTE_dec d e c
#define NSTL_ATTRIBUTE_dec_ d e c _
#define NSTL_ATTRIBUTE_prom p r o m
#define NSTL_ATTRIBUTE_inv i n v
#define NSTL_ATTRIBUTE_eq e q
#define NSTL_ATTRIBUTE_ne n e
#define NSTL_ATTRIBUTE_gt g t
#define NSTL_ATTRIBUTE_lt l t
#define NSTL_ATTRIBUTE_ge g e
#define NSTL_ATTRIBUTE_le l e
#define NSTL_ATTRIBUTE_lognot l o g n o t
#define NSTL_ATTRIBUTE_logand l o g a n d
#define NSTL_ATTRIBUTE_logor l o g o r
#define NSTL_ATTRIBUTE_not n o t
#define NSTL_ATTRIBUTE_and a n d
#define NSTL_ATTRIBUTE_or o r
#define NSTL_ATTRIBUTE_xor x o r
#define NSTL_ATTRIBUTE_lshift l s h i f t
#define NSTL_ATTRIBUTE_rshift r s h i f t
#define NSTL_ATTRIBUTE_iadd i a d d
#define NSTL_ATTRIBUTE_isub i s u b
#define NSTL_ATTRIBUTE_imul i m u l
#define NSTL_ATTRIBUTE_idiv i d i v
#define NSTL_ATTRIBUTE_imod i m o d
#define NSTL_ATTRIBUTE_iand i a n d
#define NSTL_ATTRIBUTE_ior i o r
#define NSTL_ATTRIBUTE_ixor i x o r
#define NSTL_ATTRIBUTE_ilshift i l s h i f t
#define NSTL_ATTRIBUTE_irshift i r s h i f t
#define NSTL_ATTRIBUTE_subscript s u b s c r i p t
#define NSTL_ATTRIBUTE_deref d e r e f
#define NSTL_ATTRIBUTE_call c a l l
#define NSTL_ATTRIBUTE_sizeof s i z e o f
#define NSTL_ATTRIBUTE_alignof a l i g n o f
#define NSTL_ATTRIBUTE_new n e w
#define NSTL_ATTRIBUTE_delete d e l e t e
#define NSTL_ATTRIBUTE_init i n i t
#define NSTL_ATTRIBUTE_init_cp i n i t _ c p
#define NSTL_ATTRIBUTE_deinit d e i n i t
#define NSTL_ATTRIBUTE_init_n i n i t _ n
#define NSTL_ATTRIBUTE_init_range i n i t _ r a n g e
#define NSTL_ATTRIBUTE_begin b e g i n
#define NSTL_ATTRIBUTE_end e n d
#define NSTL_ATTRIBUTE_rbegin r b e g i n
#define NSTL_ATTRIBUTE_rend r e n d
#define NSTL_ATTRIBUTE_push_back p u s h _ b a c k
#define NSTL_ATTRIBUTE_push_front p u s h _ f r o n t
#define NSTL_ATTRIBUTE_other o t h e r
#define NSTL_ATTRIBUTE_struct s t r u c t
#define NSTL_INSTRUCTION_value_type(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, value_type, implementation)
#define NSTL_INSTRUCTION_pointer(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, pointer, implementation)
#define NSTL_INSTRUCTION_const_pointer(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, const_pointer, implementation)
#define NSTL_INSTRUCTION_reference(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, reference, implementation)
#define NSTL_INSTRUCTION_const_reference(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, const_reference, implementation)
#define NSTL_INSTRUCTION_size_type(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, size_type, implementation)
#define NSTL_INSTRUCTION_difference_type(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, difference_type, implementation)
#define NSTL_INSTRUCTION_iterator(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, iterator, implementation)
#define NSTL_INSTRUCTION_const_iterator(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, const_iterator, implementation)
#define NSTL_INSTRUCTION_reverse_iterator(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, reverse_iterator, implementation)
#define NSTL_INSTRUCTION_const_reverse_iterator(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, const_reverse_iterator, implementation)
#define NSTL_INSTRUCTION_asg(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, asg, implementation)
#define NSTL_INSTRUCTION_add(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, add, implementation)
#define NSTL_INSTRUCTION_sub(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, sub, implementation)
#define NSTL_INSTRUCTION_mul(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, mul, implementation)
#define NSTL_INSTRUCTION_div(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, div, implementation)
#define NSTL_INSTRUCTION_mod(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, mod, implementation)
#define NSTL_INSTRUCTION_inc(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, inc, implementation)
#define NSTL_INSTRUCTION_inc_(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, inc_, implementation)
#define NSTL_INSTRUCTION_dec(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, dec, implementation)
#define NSTL_INSTRUCTION_dec_(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, dec_, implementation)
#define NSTL_INSTRUCTION_prom(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, prom, implementation)
#define NSTL_INSTRUCTION_inv(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, inv, implementation)
#define NSTL_INSTRUCTION_eq(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, eq, implementation)
#define NSTL_INSTRUCTION_ne(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, ne, implementation)
#define NSTL_INSTRUCTION_gt(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, gt, implementation)
#define NSTL_INSTRUCTION_lt(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, lt, implementation)
#define NSTL_INSTRUCTION_ge(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, ge, implementation)
#define NSTL_INSTRUCTION_le(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, le, implementation)
#define NSTL_INSTRUCTION_lognot(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, lognot, implementation)
#define NSTL_INSTRUCTION_logand(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, logand, implementation)
#define NSTL_INSTRUCTION_logor(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, logor, implementation)
#define NSTL_INSTRUCTION_not(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, not, implementation)
#define NSTL_INSTRUCTION_and(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, and, implementation)
#define NSTL_INSTRUCTION_or(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, or, implementation)
#define NSTL_INSTRUCTION_xor(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, xor, implementation)
#define NSTL_INSTRUCTION_lshift(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, lshift, implementation)
#define NSTL_INSTRUCTION_rshift(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, rshift, implementation)
#define NSTL_INSTRUCTION_iadd(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, iadd, implementation)
#define NSTL_INSTRUCTION_isub(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, isub, implementation)
#define NSTL_INSTRUCTION_imul(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, imul, implementation)
#define NSTL_INSTRUCTION_idiv(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, idiv, implementation)
#define NSTL_INSTRUCTION_imod(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, imod, implementation)
#define NSTL_INSTRUCTION_iand(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, iand, implementation)
#define NSTL_INSTRUCTION_ior(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, ior, implementation)
#define NSTL_INSTRUCTION_ixor(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, ixor, implementation)
#define NSTL_INSTRUCTION_ilshift(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, ilshift, implementation)
#define NSTL_INSTRUCTION_irshift(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, irshift, implementation)
#define NSTL_INSTRUCTION_subscript(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, subscript, implementation)
#define NSTL_INSTRUCTION_deref(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, deref, implementation)
#define NSTL_INSTRUCTION_call(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, call, implementation)
#define NSTL_INSTRUCTION_sizeof(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, sizeof, implementation)
#define NSTL_INSTRUCTION_alignof(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, alignof, implementation)
#define NSTL_INSTRUCTION_new(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, new, implementation)
#define NSTL_INSTRUCTION_delete(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, delete, implementation)
#define NSTL_INSTRUCTION_init(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, init, implementation)
#define NSTL_INSTRUCTION_init_cp(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, init_cp, implementation)
#define NSTL_INSTRUCTION_deinit(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, deinit, implementation)
#define NSTL_INSTRUCTION_init_n(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, init_n, implementation)
#define NSTL_INSTRUCTION_init_range(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, init_range, implementation)
#define NSTL_INSTRUCTION_begin(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, begin, implementation)
#define NSTL_INSTRUCTION_end(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, end, implementation)
#define NSTL_INSTRUCTION_rbegin(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, rbegin, implementation)
#define NSTL_INSTRUCTION_rend(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, rend, implementation)
#define NSTL_INSTRUCTION_push_back(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, push_back, implementation)
#define NSTL_INSTRUCTION_push_front(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, push_front, implementation)
#define NSTL_INSTRUCTION_other(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, other, implementation)
#define NSTL_INSTRUCTION_struct(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, struct, implementation)
#define CHAOS_IP_STRING_value_type (value_type)
#define CHAOS_IP_STRING_pointer (pointer)
#define CHAOS_IP_STRING_const_pointer (const_pointer)
#define CHAOS_IP_STRING_reference (reference)
#define CHAOS_IP_STRING_const_reference (const_reference)
#define CHAOS_IP_STRING_size_type (size_type)
#define CHAOS_IP_STRING_difference_type (difference_type)
#define CHAOS_IP_STRING_iterator (iterator)
#define CHAOS_IP_STRING_const_iterator (const_iterator)
#define CHAOS_IP_STRING_reverse_iterator (reverse_iterator)
#define CHAOS_IP_STRING_const_reverse_iterator (const_reverse_iterator)
#define CHAOS_IP_STRING_asg (asg)
#define CHAOS_IP_STRING_add (add)
#define CHAOS_IP_STRING_sub (sub)
#define CHAOS_IP_STRING_mul (mul)
#define CHAOS_IP_STRING_div (div)
#define CHAOS_IP_STRING_mod (mod)
#define CHAOS_IP_STRING_inc (inc)
#define CHAOS_IP_STRING_inc_ (inc_)
#define CHAOS_IP_STRING_dec (dec)
#define CHAOS_IP_STRING_dec_ (dec_)
#define CHAOS_IP_STRING_prom (prom)
#define CHAOS_IP_STRING_inv (inv)
#define CHAOS_IP_STRING_eq (eq)
#define CHAOS_IP_STRING_ne (ne)
#define CHAOS_IP_STRING_gt (gt)
#define CHAOS_IP_STRING_lt (lt)
#define CHAOS_IP_STRING_ge (ge)
#define CHAOS_IP_STRING_le (le)
#define CHAOS_IP_STRING_lognot (lognot)
#define CHAOS_IP_STRING_logand (logand)
#define CHAOS_IP_STRING_logor (logor)
#define CHAOS_IP_STRING_not (not)
#define CHAOS_IP_STRING_and (and)
#define CHAOS_IP_STRING_or (or)
#define CHAOS_IP_STRING_xor (xor)
#define CHAOS_IP_STRING_lshift (lshift)
#define CHAOS_IP_STRING_rshift (rshift)
#define CHAOS_IP_STRING_iadd (iadd)
#define CHAOS_IP_STRING_isub (isub)
#define CHAOS_IP_STRING_imul (imul)
#define CHAOS_IP_STRING_idiv (idiv)
#define CHAOS_IP_STRING_imod (imod)
#define CHAOS_IP_STRING_iand (iand)
#define CHAOS_IP_STRING_ior (ior)
#define CHAOS_IP_STRING_ixor (ixor)
#define CHAOS_IP_STRING_ilshift (ilshift)
#define CHAOS_IP_STRING_irshift (irshift)
#define CHAOS_IP_STRING_subscript (subscript)
#define CHAOS_IP_STRING_deref (deref)
#define CHAOS_IP_STRING_call (call)
#define CHAOS_IP_STRING_sizeof (sizeof)
#define CHAOS_IP_STRING_alignof (alignof)
#define CHAOS_IP_STRING_new (new)
#define CHAOS_IP_STRING_delete (delete)
#define CHAOS_IP_STRING_init (init)
#define CHAOS_IP_STRING_init_cp (init_cp)
#define CHAOS_IP_STRING_deinit (deinit)
#define CHAOS_IP_STRING_init_n (init_n)
#define CHAOS_IP_STRING_init_range (init_range)
#define CHAOS_IP_STRING_begin (begin)
#define CHAOS_IP_STRING_end (end)
#define CHAOS_IP_STRING_rbegin (rbegin)
#define CHAOS_IP_STRING_rend (rend)
#define CHAOS_IP_STRING_push_back (push_back)
#define CHAOS_IP_STRING_push_front (push_front)
#define CHAOS_IP_STRING_other (other)
#define CHAOS_IP_STRING_struct (struct)
#define nstl_value_type(x) \
    JOY_CAT3(nstl_attribute_value_type, _, x)
#define nstl_pointer(x) \
    JOY_CAT3(nstl_attribute_pointer, _, x)
#define nstl_const_pointer(x) \
    JOY_CAT3(nstl_attribute_const_pointer, _, x)
#define nstl_reference(x) \
    JOY_CAT3(nstl_attribute_reference, _, x)
#define nstl_const_reference(x) \
    JOY_CAT3(nstl_attribute_const_reference, _, x)
#define nstl_size_type(x) \
    JOY_CAT3(nstl_attribute_size_type, _, x)
#define nstl_difference_type(x) \
    JOY_CAT3(nstl_attribute_difference_type, _, x)
#define nstl_iterator(x) \
    JOY_CAT3(nstl_attribute_iterator, _, x)
#define nstl_const_iterator(x) \
    JOY_CAT3(nstl_attribute_const_iterator, _, x)
#define nstl_reverse_iterator(x) \
    JOY_CAT3(nstl_attribute_reverse_iterator, _, x)
#define nstl_const_reverse_iterator(x) \
    JOY_CAT3(nstl_attribute_const_reverse_iterator, _, x)
#define nstl_asg(x) \
    JOY_CAT3(nstl_attribute_asg, _, x)
#define nstl_add(x) \
    JOY_CAT3(nstl_attribute_add, _, x)
#define nstl_sub(x) \
    JOY_CAT3(nstl_attribute_sub, _, x)
#define nstl_mul(x) \
    JOY_CAT3(nstl_attribute_mul, _, x)
#define nstl_div(x) \
    JOY_CAT3(nstl_attribute_div, _, x)
#define nstl_mod(x) \
    JOY_CAT3(nstl_attribute_mod, _, x)
#define nstl_inc(x) \
    JOY_CAT3(nstl_attribute_inc, _, x)
#define nstl_inc_(x) \
    JOY_CAT3(nstl_attribute_inc_, _, x)
#define nstl_dec(x) \
    JOY_CAT3(nstl_attribute_dec, _, x)
#define nstl_dec_(x) \
    JOY_CAT3(nstl_attribute_dec_, _, x)
#define nstl_prom(x) \
    JOY_CAT3(nstl_attribute_prom, _, x)
#define nstl_inv(x) \
    JOY_CAT3(nstl_attribute_inv, _, x)
#define nstl_eq(x) \
    JOY_CAT3(nstl_attribute_eq, _, x)
#define nstl_ne(x) \
    JOY_CAT3(nstl_attribute_ne, _, x)
#define nstl_gt(x) \
    JOY_CAT3(nstl_attribute_gt, _, x)
#define nstl_lt(x) \
    JOY_CAT3(nstl_attribute_lt, _, x)
#define nstl_ge(x) \
    JOY_CAT3(nstl_attribute_ge, _, x)
#define nstl_le(x) \
    JOY_CAT3(nstl_attribute_le, _, x)
#define nstl_lognot(x) \
    JOY_CAT3(nstl_attribute_lognot, _, x)
#define nstl_logand(x) \
    JOY_CAT3(nstl_attribute_logand, _, x)
#define nstl_logor(x) \
    JOY_CAT3(nstl_attribute_logor, _, x)
#define nstl_not(x) \
    JOY_CAT3(nstl_attribute_not, _, x)
#define nstl_and(x) \
    JOY_CAT3(nstl_attribute_and, _, x)
#define nstl_or(x) \
    JOY_CAT3(nstl_attribute_or, _, x)
#define nstl_xor(x) \
    JOY_CAT3(nstl_attribute_xor, _, x)
#define nstl_lshift(x) \
    JOY_CAT3(nstl_attribute_lshift, _, x)
#define nstl_rshift(x) \
    JOY_CAT3(nstl_attribute_rshift, _, x)
#define nstl_iadd(x) \
    JOY_CAT3(nstl_attribute_iadd, _, x)
#define nstl_isub(x) \
    JOY_CAT3(nstl_attribute_isub, _, x)
#define nstl_imul(x) \
    JOY_CAT3(nstl_attribute_imul, _, x)
#define nstl_idiv(x) \
    JOY_CAT3(nstl_attribute_idiv, _, x)
#define nstl_imod(x) \
    JOY_CAT3(nstl_attribute_imod, _, x)
#define nstl_iand(x) \
    JOY_CAT3(nstl_attribute_iand, _, x)
#define nstl_ior(x) \
    JOY_CAT3(nstl_attribute_ior, _, x)
#define nstl_ixor(x) \
    JOY_CAT3(nstl_attribute_ixor, _, x)
#define nstl_ilshift(x) \
    JOY_CAT3(nstl_attribute_ilshift, _, x)
#define nstl_irshift(x) \
    JOY_CAT3(nstl_attribute_irshift, _, x)
#define nstl_subscript(x) \
    JOY_CAT3(nstl_attribute_subscript, _, x)
#define nstl_deref(x) \
    JOY_CAT3(nstl_attribute_deref, _, x)
#define nstl_call(x) \
    JOY_CAT3(nstl_attribute_call, _, x)
#define nstl_sizeof(x) \
    JOY_CAT3(nstl_attribute_sizeof, _, x)
#define nstl_alignof(x) \
    JOY_CAT3(nstl_attribute_alignof, _, x)
#define nstl_new(x) \
    JOY_CAT3(nstl_attribute_new, _, x)
#define nstl_delete(x) \
    JOY_CAT3(nstl_attribute_delete, _, x)
#define nstl_init(x) \
    JOY_CAT3(nstl_attribute_init, _, x)
#define nstl_init_cp(x) \
    JOY_CAT3(nstl_attribute_init_cp, _, x)
#define nstl_deinit(x) \
    JOY_CAT3(nstl_attribute_deinit, _, x)
#define nstl_init_n(x) \
    JOY_CAT3(nstl_attribute_init_n, _, x)
#define nstl_init_range(x) \
    JOY_CAT3(nstl_attribute_init_range, _, x)
#define nstl_begin(x) \
    JOY_CAT3(nstl_attribute_begin, _, x)
#define nstl_end(x) \
    JOY_CAT3(nstl_attribute_end, _, x)
#define nstl_rbegin(x) \
    JOY_CAT3(nstl_attribute_rbegin, _, x)
#define nstl_rend(x) \
    JOY_CAT3(nstl_attribute_rend, _, x)
#define nstl_push_back(x) \
    JOY_CAT3(nstl_attribute_push_back, _, x)
#define nstl_push_front(x) \
    JOY_CAT3(nstl_attribute_push_front, _, x)
#define nstl_other(x) \
    JOY_CAT3(nstl_attribute_other, _, x)
#define nstl_struct(x) \
    JOY_CAT3(nstl_attribute_struct, _, x)
/* [[[end]]] */

#endif /* !NSTL_INTERNAL_ATTRIBUTES_H */