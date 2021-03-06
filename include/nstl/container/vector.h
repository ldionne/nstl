/**
 * Implementation of a vector template.
 */

#ifndef NSTL_CONTAINER_VECTOR_H
#define NSTL_CONTAINER_VECTOR_H

#include <nstl/internal.h>

#include <stdlib.h>


#define NSTL_VECTOR(T) NSTL_I_VECTOR(nstl_vector(T), T)

#define NSTL_I_VECTOR(vector, T)                                               \
NSTL_TYPE(vector,                                                              \
                                                                               \
(defstruct                                                                     \
/**                                                                            \
 * Type of a vector container.                                                 \
 */                                                                            \
struct vector {                                                                \
    T *start;                                                                  \
    T *finish;                                                                 \
    T *end_of_storage;                                                         \
};                                                                             \
typedef struct vector vector;                                                  \
)                                                                              \
                                                                               \
/****************************************************************************  \
                        Initialization / deinitialization                      \
 ****************************************************************************/ \
(defun ctor                                                                    \
static NSTL_INLINE void nstl_ctor(vector)(vector *self) {                      \
    self->start = self->finish = self->end_of_storage = NULL;                  \
}                                                                              \
)                                                                              \
                                                                               \
(defun dtor                                                                    \
static NSTL_INLINE void nstl_dtor(vector)(vector *self) {                      \
    free(self->start);                                                         \
}                                                                              \
)                                                                              \
                                                                               \
/****************************************************************************  \
                                    Iterators                                  \
 ****************************************************************************/ \
(defun begin                                                                   \
static NSTL_INLINE T *nstl_begin(vector)(vector *self) {                       \
    return self->start;                                                        \
}                                                                              \
)                                                                              \
                                                                               \
(defun end                                                                     \
static NSTL_INLINE T *nstl_end(vector)(vector *self) {                         \
    return self->finish;                                                       \
}                                                                              \
)                                                                              \
                                                                               \
/****************************************************************************  \
                                Element access                                 \
 ****************************************************************************/ \
(defun at                                                                      \
static NSTL_INLINE T nstl_at(vector)(vector *self, nstl_size_t n) {            \
    nstl_assert_true(nstl_begin(vector)(self) + n < nstl_end(vector)(self));   \
    return *(nstl_begin(vector)(self) + n);                                    \
}                                                                              \
)                                                                              \
                                                                               \
(defun front                                                                   \
static NSTL_INLINE T nstl_front(vector)(vector *self) {                        \
    return *(nstl_begin(vector)(self));                                        \
}                                                                              \
)                                                                              \
                                                                               \
(defun back                                                                    \
static NSTL_INLINE T nstl_back(vector)(vector *self) {                         \
    return *(nstl_end(vector)(self) - 1);                                      \
}                                                                              \
)                                                                              \
                                                                               \
/****************************************************************************  \
                                    Capacity                                   \
 ****************************************************************************/ \
(defun empty                                                                   \
static NSTL_INLINE nstl_bool nstl_empty(vector)(vector *self) {                \
    return self->start == self->finish;                                        \
}                                                                              \
)                                                                              \
                                                                               \
(defun size                                                                    \
static NSTL_INLINE nstl_size_t nstl_size(vector)(vector *self) {               \
    return self->finish - self->start;                                         \
}                                                                              \
)                                                                              \
                                                                               \
(defun max_size                                                                \
static NSTL_INLINE nstl_size_t nstl_max_size(vector)(vector *self) {           \
    NSTL_SILENCE_UNUSED_VARIABLE_WARNING(self);                                \
    return (nstl_size_t)-1 / sizeof(T);                                        \
}                                                                              \
)                                                                              \
                                                                               \
(defun capacity                                                                \
static NSTL_INLINE nstl_size_t nstl_capacity(vector)(vector *self) {           \
    return self->end_of_storage - self->start;                                 \
}                                                                              \
)                                                                              \
                                                                               \
(defun reserve                                                                 \
/**                                                                            \
 * Request that the capacity of a vector be at least enough to hold @p n       \
 * elements.                                                                   \
 */                                                                            \
static NSTL_INLINE void nstl_reserve(vector)(vector *self, nstl_size_t n) {    \
    if (nstl_capacity(vector)(self) < n) {                                     \
        nstl_size_t const old_size = nstl_size(vector)(self);                  \
        nstl_assert_true(nstl_max_size(vector)(self) > n);                     \
                                                                               \
        self->start = reallocf(self->start, n * sizeof(T));                    \
        nstl_assert_true(self->start != NULL && "not enough memory.");         \
        self->end_of_storage = self->start + n;                                \
        self->finish = self->start + old_size;                                 \
    }                                                                          \
}                                                                              \
)                                                                              \
                                                                               \
/****************************************************************************  \
                                    Modifiers                                  \
 ****************************************************************************/ \
(defun push_back                                                               \
static NSTL_INLINE void nstl_push_back(vector)(vector *self, T x) {            \
    if (self->finish == self->end_of_storage) {                                \
        nstl_size_t size = nstl_size(vector)(self);                            \
        nstl_reserve(vector)(self, size > 0 ? size * 2 : 1);                   \
    }                                                                          \
     *self->finish = x;                                                        \
     ++self->finish;                                                           \
}                                                                              \
)                                                                              \
                                                                               \
(defun pop_back                                                                \
static NSTL_INLINE void nstl_pop_back(vector)(vector *self) {                  \
    --self->finish;                                                            \
}                                                                              \
)                                                                              \
                                                                               \
(defun clear                                                                   \
static NSTL_INLINE void nstl_clear(vector)(vector *self) {                     \
    self->finish = self->start;                                                \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
nstl.generate(cog,
    'vector(T)',

    mangle=True,
)

]]] */
#include <joy/cat.h>
#define nstl_vector(T) JOY_CAT3(nstl_mangled_vector, _, T)
/* [[[end]]] */

#endif /* !NSTL_CONTAINER_VECTOR_H */
