/*!
 * Implementation of a generic preprocessor object.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_TYPE_H
#define NSTL_INTERNAL_TYPE_H

#include <chaos/preprocessor/seq/to_string.h>
#include <joy/seq/find_first.h>
#include <joy/seq/append.h>
#include <joy/seq/pyunzip.h>
#include <joy/seq/remove_if.h>
#include <joy/seq/contains.h>
#include <joy/string/eq.h>
#include <joy/pair.h>


/*!
 * Return whether two (attribute_name, implementation) pairs represent the same
 * attribute. The implementation can differ.
 */
#define NSTL_I_TYPE_COMPARE(s, x, y)                                           \
    JOY_STRING_EQ_S(s,                                                         \
        NSTL_TOKEN_TO_STRING(JOY_PAIR_FIRST(x)),                               \
        NSTL_TOKEN_TO_STRING(JOY_PAIR_FIRST(y))                                \
    )                                                                          \
/**/

/*!
 * Return the value of an attribute of an object.
 */
#define NSTL_GETATTR(self, attr) \
    NSTL_GETATTR_S(CHAOS_PP_STATE(), self, attr)

#define NSTL_GETATTR_S(s, self, attr)                                          \
    JOY_PAIR_SECOND(JOY_SEQ_FIND_FIRST_S(s,                                    \
        NSTL_I_TYPE_COMPARE, self, JOY_PAIR(attr, ~)                           \
    ))                                                                         \
/**/

/*!
 * Set or override an attribute of an object.
 */
#define NSTL_SETATTR(self, attr, value) \
    NSTL_SETATTR_S(CHAOS_PP_STATE(), attr, value)

#define NSTL_SETATTR_S(s, self, attr, value)                                   \
    JOY_SEQ_APPEND(                                                            \
        JOY_PAIR(attr, value),                                                 \
        NSTL_DELATTR_S(s, self, attr)                                          \
    )                                                                          \
/**/

/*!
 * Set or override many attributes at once.
 *
 * @param attrs A sequence of name:value pairs.
 */
#define NSTL_SETATTRS(self, attrs) \
    NSTL_SETATTRS_S(CHAOS_PP_STATE(), self, attrs)

#define NSTL_SETATTRS_S(s, self, attrs)                                        \
    NSTL_DELATTRS_S(s,                                                         \
        self, JOY_PAIR_FIRST(JOY_SEQ_PYUNZIP_S(s, attrs))                      \
    ) attrs                                                                    \
/**/

/*!
 * Delete an attribute of an object.
 *
 * @note If the attribute is not found, nothing is done.
 */
#define NSTL_DELATTR(self, attr) \
    NSTL_DELATTR_S(CHAOS_PP_STATE(), self, attr)

#define NSTL_DELATTR_S(s, self, attr)                                          \
    JOY_SEQ_REMOVE_IF_S(s,                                                     \
        NSTL_I_TYPE_COMPARE, self, JOY_PAIR(attr, ~)                           \
    )                                                                          \
/**/

/*!
 * Delete many attributes at once.
 *
 * @param attrs A sequence of attributes to delete.
 */
#define NSTL_DELATTRS(self, attrs) \
    NSTL_DELATTRS_S(CHAOS_PP_STATE(), self, attrs)

#define NSTL_DELATTRS_S(s, self, attrs) \
    JOY_SEQ_REMOVE_IF_S(s, NSTL_I_DELATTRS_PRED, self, attrs)

#define NSTL_I_DELATTRS_PRED(s, attr, to_del) \
    JOY_SEQ_CONTAINS_S(s, NSTL_II_DELATTRS_PRED, to_del, JOY_PAIR_FIRST(attr))

#define NSTL_II_DELATTRS_PRED(s, x, y) \
    JOY_STRING_EQ_S(s, NSTL_TOKEN_TO_STRING(x), NSTL_TOKEN_TO_STRING(y))

/*!
 * Return whether an object has a given attribute.
 */
#define NSTL_HASATTR(self, attr) \
    NSTL_HASATTR_S(CHAOS_PP_STATE(), self, attr)

#define NSTL_HASATTR_S(s, self, attr)                                          \
    JOY_SEQ_CONTAINS_S(s,                                                      \
        NSTL_I_TYPE_COMPARE, self, JOY_PAIR(attr, ~)                           \
    )                                                                          \
/**/

/*!
 * Instantiate the implementation of each attribute of a nstl type.
 */
#define NSTL_IMPLEMENT(self) \
    NSTL_IMPLEMENT_S(CHAOS_PP_STATE(), self)

#define NSTL_IMPLEMENT_S(s, self)                                              \
    CHAOS_PP_SEQ_TO_STRING(                                                    \
        JOY_PAIR_SECOND(JOY_SEQ_PYUNZIP_S(s, self))                            \
    )                                                                          \
/**/

#endif /* !NSTL_INTERNAL_TYPE_H */
