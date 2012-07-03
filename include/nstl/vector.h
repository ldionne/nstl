/*!
 * Implementation of a vector template.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_VECTOR_H
#define NSTL_VECTOR_H

#include <nstl/type.h>

#include <assert.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>


#define NSTL_VECTOR(T) NSTL_VECTOR_INHERIT(nstl_vector(T), T)

#define NSTL_VECTOR_INHERIT(vector, T)                                         \
NSTL_TYPE(                                                                     \
                                                                               \
(setf struct                                                                   \
/*!                                                                            \
 * Type of a vector container.                                                 \
 */                                                                            \
typedef struct {                                                               \
    T *start;                                                                  \
    T *finish;                                                                 \
    T *end_of_storage;                                                         \
} vector;                                                                      \
)                                                                              \
                                                                               \
/****************************************************************************** \
                        Initialization / deinitialization                      \
 ******************************************************************************/ \
(setf ctor                                                                     \
static inline void nstl_ctor(vector)(vector *self)                             \
{                                                                              \
    self->start = self->finish = self->end_of_storage = NULL;                  \
}                                                                              \
)                                                                              \
                                                                               \
(setf dtor                                                                     \
static inline void nstl_dtor(vector)(vector *self)                             \
{                                                                              \
    free(self->start);                                                         \
}                                                                              \
)                                                                              \
                                                                               \
/****************************************************************************** \
                                    Iterators                                  \
 ******************************************************************************/ \
(setf begin                                                                    \
static inline T *nstl_begin(vector)(vector *self)                              \
{                                                                              \
    return self->start;                                                        \
}                                                                              \
)                                                                              \
                                                                               \
(setf end                                                                      \
static inline T *nstl_end(vector)(vector *self)                                \
{                                                                              \
    return self->finish;                                                       \
}                                                                              \
)                                                                              \
                                                                               \
/****************************************************************************** \
                                Element access                                 \
 ******************************************************************************/ \
(setf at                                                                       \
static inline T nstl_at(vector)(vector *self, size_t n)                        \
{                                                                              \
    assert(nstl_begin(vector)(self) + n < nstl_end(vector)(self));             \
    return *(nstl_begin(vector)(self) + n);                                    \
}                                                                              \
)                                                                              \
                                                                               \
(setf front                                                                    \
static inline T nstl_front(vector)(vector *self)                               \
{                                                                              \
    return *(nstl_begin(vector)(self));                                        \
}                                                                              \
)                                                                              \
                                                                               \
(setf back                                                                     \
static inline T nstl_back(vector)(vector *self)                                \
{                                                                              \
    return *(nstl_end(vector)(self) - 1);                                      \
}                                                                              \
)                                                                              \
                                                                               \
/****************************************************************************** \
                                    Capacity                                   \
 ******************************************************************************/ \
(setf empty                                                                    \
static inline bool nstl_empty(vector)(vector *self)                            \
{                                                                              \
    return self->start == self->finish;                                        \
}                                                                              \
)                                                                              \
                                                                               \
(setf size                                                                     \
static inline size_t nstl_size(vector)(vector *self)                           \
{                                                                              \
    return self->finish - self->start;                                         \
}                                                                              \
)                                                                              \
                                                                               \
(setf max_size                                                                 \
static inline size_t nstl_max_size(vector)(vector *self)                       \
{                                                                              \
    return (size_t)-1 / sizeof(T);                                             \
}                                                                              \
)                                                                              \
                                                                               \
(setf capacity                                                                 \
static inline size_t nstl_capacity(vector)(vector *self)                       \
{                                                                              \
    return self->end_of_storage - self->start;                                 \
}                                                                              \
)                                                                              \
                                                                               \
(setf reserve                                                                  \
/*!                                                                            \
 * Request that the capacity of a vector be at least enough to hold @p n       \
 * elements.                                                                   \
 */                                                                            \
static inline void nstl_reserve(vector)(vector *self, size_t n)                \
{                                                                              \
    if (nstl_capacity(vector)(self) < n) {                                     \
        assert(nstl_max_size(vector)(self) > n);                               \
                                                                               \
        size_t const old_size = nstl_size(vector)(self);                       \
        self->start = reallocf(self->start, n * sizeof(T));                    \
        assert(self->start != NULL && "not enough memory.");                   \
        self->end_of_storage = self->start + n;                                \
        self->finish = self->start + old_size;                                 \
    }                                                                          \
}                                                                              \
)                                                                              \
                                                                               \
/****************************************************************************** \
                                    Modifiers                                  \
 ******************************************************************************/ \
(setf push_back                                                                \
static inline void nstl_push_back(vector)(vector *self, T x)                   \
{                                                                              \
    if (self->finish == self->end_of_storage) {                                \
        size_t size = nstl_size(vector)(self);                                 \
        nstl_reserve(vector)(self, size > 0 ? size * 2 : 1);                   \
    }                                                                          \
     *self->finish = x;                                                        \
     ++self->finish;                                                           \
}                                                                              \
)                                                                              \
                                                                               \
(setf pop_back                                                                 \
static inline void nstl_pop_back(vector)(vector *self)                         \
{                                                                              \
    --self->finish;                                                            \
}                                                                              \
)                                                                              \
                                                                               \
(setf clear                                                                    \
static inline void nstl_clear(vector)(vector *self)                            \
{                                                                              \
    self->finish = self->start;                                                \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
cog.outl(nstl.generate_mangled(
    'vector(T)',

    token=False,
))

]]] */
#include <joy/cat.h>
#define nstl_vector(T) JOY_CAT3(nstl_mangled_vector, _, T)
/* [[[end]]] */

#endif /* !NSTL_VECTOR_H */
