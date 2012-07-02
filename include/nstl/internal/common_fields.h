/*!
 * Definition of several common fields.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_COMMON_FIELDS_H
#define NSTL_INTERNAL_COMMON_FIELDS_H

/* [[[cog

import nstl
cog.outl(nstl.generate_mangled(
    # Initialization / deinitialization
    'init(T)',
    'init_from(T1, T2)',
    'deinit(T)',

    # Concrete C type representation
    'struct',

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
))

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_init (i n i t)
#define nstl_init(T) JOY_CAT3(nstl_mangled_init, _, T)
#define NSTL_TOKEN_init_from (i n i t _ f r o m)
#define nstl_init_from(T1,  T2) JOY_CAT5(nstl_mangled_init_from, _, T1, _,  T2)
#define NSTL_TOKEN_deinit (d e i n i t)
#define nstl_deinit(T) JOY_CAT3(nstl_mangled_deinit, _, T)
#define NSTL_TOKEN_struct (s t r u c t)
#define nstl_struct nstl_mangled_struct
#define NSTL_TOKEN_begin (b e g i n)
#define nstl_begin(T) JOY_CAT3(nstl_mangled_begin, _, T)
#define NSTL_TOKEN_end (e n d)
#define nstl_end(T) JOY_CAT3(nstl_mangled_end, _, T)
#define NSTL_TOKEN_rbegin (r b e g i n)
#define nstl_rbegin(T) JOY_CAT3(nstl_mangled_rbegin, _, T)
#define NSTL_TOKEN_rend (r e n d)
#define nstl_rend(T) JOY_CAT3(nstl_mangled_rend, _, T)
#define NSTL_TOKEN_at (a t)
#define nstl_at(T) JOY_CAT3(nstl_mangled_at, _, T)
#define NSTL_TOKEN_front (f r o n t)
#define nstl_front(T) JOY_CAT3(nstl_mangled_front, _, T)
#define NSTL_TOKEN_back (b a c k)
#define nstl_back(T) JOY_CAT3(nstl_mangled_back, _, T)
#define NSTL_TOKEN_empty (e m p t y)
#define nstl_empty(T) JOY_CAT3(nstl_mangled_empty, _, T)
#define NSTL_TOKEN_size (s i z e)
#define nstl_size(T) JOY_CAT3(nstl_mangled_size, _, T)
#define NSTL_TOKEN_max_size (m a x _ s i z e)
#define nstl_max_size(T) JOY_CAT3(nstl_mangled_max_size, _, T)
#define NSTL_TOKEN_capacity (c a p a c i t y)
#define nstl_capacity(T) JOY_CAT3(nstl_mangled_capacity, _, T)
#define NSTL_TOKEN_reserve (r e s e r v e)
#define nstl_reserve(T) JOY_CAT3(nstl_mangled_reserve, _, T)
#define NSTL_TOKEN_push_back (p u s h _ b a c k)
#define nstl_push_back(T) JOY_CAT3(nstl_mangled_push_back, _, T)
#define NSTL_TOKEN_pop_back (p o p _ b a c k)
#define nstl_pop_back(T) JOY_CAT3(nstl_mangled_pop_back, _, T)
#define NSTL_TOKEN_clear (c l e a r)
#define nstl_clear(T) JOY_CAT3(nstl_mangled_clear, _, T)
/* [[[end]]] */

#endif /* !NSTL_INTERNAL_COMMON_FIELDS_H */