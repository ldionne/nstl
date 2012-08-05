/**
 * Implementation of C pointer types.
 */

#ifndef NSTL_INTERNAL_POINTER_H
#define NSTL_INTERNAL_POINTER_H

#include <nstl/internal/integral.h>
#include <nstl/internal/operator.h>
#include <nstl/internal/type.h>


#define NSTL_POINTER(ValueType, Pointer)                                       \
NSTL_TYPE(Pointer,                                                             \
                                                                               \
(defun deref_proxy                                                             \
NSTL_INSTANTIATE(                                                              \
    NSTL_I_POINTER_DEREF_PROXY(Pointer, ValueType)                             \
)                                                                              \
)                                                                              \
                                                                               \
(inherit NSTL_INITIALIZATION_OPERATORS(Pointer))                               \
(inherit NSTL_ARITHMETIC_OPERATORS(Pointer))                                   \
(inherit NSTL_COMPARISON_OPERATORS(Pointer))                                   \
(inherit NSTL_LOGICAL_OPERATORS(Pointer))                                      \
                                                                               \
(defun add                                                                     \
static NSTL_INLINE Pointer nstl_add(Pointer, nstl_ptrdiff_t)                   \
                                            (Pointer self, nstl_ptrdiff_t n) { \
    return self + n;                                                           \
}                                                                              \
)                                                                              \
(defun iadd                                                                    \
static NSTL_INLINE Pointer nstl_iadd(Pointer, nstl_ptrdiff_t)                  \
                                        (Pointer *self, nstl_ptrdiff_t n) {    \
    return (*self) += n;                                                       \
}                                                                              \
)                                                                              \
(defun sub                                                                     \
static NSTL_INLINE nstl_ptrdiff_t nstl_sub(Pointer, Pointer)                   \
                                                    (Pointer x, Pointer y) {   \
    return x - y;                                                              \
}                                                                              \
                                                                               \
static NSTL_INLINE Pointer nstl_sub(Pointer, nstl_ptrdiff_t)                   \
                                            (Pointer self, nstl_ptrdiff_t n) { \
    return self - n;                                                           \
}                                                                              \
)                                                                              \
(defun isub                                                                    \
static NSTL_INLINE Pointer nstl_isub(Pointer, nstl_ptrdiff_t)                  \
                                        (Pointer *self, nstl_ptrdiff_t n) {    \
    return (*self) -= n;                                                       \
}                                                                              \
)                                                                              \
                                                                               \
(defun deref                                                                   \
static NSTL_INLINE ValueType nstl_deref(Pointer)(Pointer self) {               \
    return *self;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(drop mul imul  div idiv  mod imod  prom inv)                                  \
                                                                               \
)                                                                              \
/**/


#define NSTL_I_POINTER_DEREF_PROXY(Pointer, ValueType)                         \
NSTL_TYPE(nstl_deref_proxy(Pointer),                                           \
                                                                               \
(defstruct                                                                     \
struct nstl_deref_proxy(Pointer) {                                             \
    Pointer p;                                                                 \
};                                                                             \
typedef struct nstl_deref_proxy(Pointer) nstl_deref_proxy(Pointer);            \
)                                                                              \
                                                                               \
(defun ctor                                                                    \
static NSTL_INLINE void nstl_ctor(nstl_deref_proxy(Pointer))                   \
                            (nstl_deref_proxy(Pointer) *proxy, Pointer p) {    \
    proxy->p = p;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(defun dtor                                                                    \
static NSTL_INLINE void nstl_dtor(nstl_deref_proxy(Pointer))                   \
                                        (nstl_deref_proxy(Pointer) *proxy) {   \
    NSTL_SILENCE_UNUSED_VARIABLE_WARNING(proxy);                               \
}                                                                              \
)                                                                              \
                                                                               \
(defun put                                                                     \
static NSTL_INLINE void nstl_put(nstl_deref_proxy(Pointer))                    \
                            (nstl_deref_proxy(Pointer) proxy, ValueType x) {   \
    nstl_asg(ValueType, ValueType)(proxy.p, x);                                \
}                                                                              \
)                                                                              \
                                                                               \
(defun get                                                                     \
static NSTL_INLINE ValueType nstl_get(nstl_deref_proxy(Pointer))               \
                                        (nstl_deref_proxy(Pointer) proxy) {    \
    return *proxy.p;                                                           \
}                                                                              \
)                                                                              \
                                                                               \
(defun get_lvalue                                                              \
static NSTL_INLINE ValueType *nstl_get_lvalue(nstl_deref_proxy(Pointer))       \
                                        (nstl_deref_proxy(Pointer) proxy) {    \
    return proxy.p;                                                            \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'deref(Pointer)',
    'deref_proxy(Iterator)',
    'put(Proxy)',
    'get(Proxy)',
    'get_lvalue(Proxy)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_deref (d e r e f)
#define nstl_deref(Pointer) JOY_CAT3(nstl_mangled_deref, _, Pointer)
#define NSTL_TOKEN_deref_proxy (d e r e f _ p r o x y)
#define nstl_deref_proxy(Iterator) JOY_CAT3(nstl_mangled_deref_proxy, _, Iterator)
#define NSTL_TOKEN_put (p u t)
#define nstl_put(Proxy) JOY_CAT3(nstl_mangled_put, _, Proxy)
#define NSTL_TOKEN_get (g e t)
#define nstl_get(Proxy) JOY_CAT3(nstl_mangled_get, _, Proxy)
#define NSTL_TOKEN_get_lvalue (g e t _ l v a l u e)
#define nstl_get_lvalue(Proxy) JOY_CAT3(nstl_mangled_get_lvalue, _, Proxy)
/* [[[end]]] */

#endif /* !NSTL_INTERNAL_POINTER_H */
