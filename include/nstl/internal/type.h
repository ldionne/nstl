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
 * Return the value of a field of an object.
 */
#define NSTL_GETF(self, field) \
    NSTL_GETF_S(CHAOS_PP_STATE(), self, field)

#define NSTL_GETF_S(s, self, field)                                            \
    JOY_PAIR_SECOND(JOY_SEQ_FIND_FIRST_S(s,                                    \
        NSTL_I_TYPE_COMPARE, self, JOY_PAIR(field, ~)                          \
    ))                                                                         \
/**/

/*!
 * Set or override a field of an object.
 */
#define NSTL_SETF(self, field, value) \
    NSTL_SETF_S(CHAOS_PP_STATE(), field, value)

#define NSTL_SETF_S(s, self, field, value)                                     \
    JOY_SEQ_APPEND(                                                            \
        JOY_PAIR(field, value),                                                \
        NSTL_UNSETF_S(s, self, field)                                          \
    )                                                                          \
/**/

/*!
 * Set or override many fields at once.
 *
 * @param fields A sequence of name:value pairs.
 */
#define NSTL_SETFS(self, fields) \
    NSTL_SETFS_S(CHAOS_PP_STATE(), self, fields)

#define NSTL_SETFS_S(s, self, fields)                                          \
    NSTL_UNSETFS_S(s,                                                          \
        self, JOY_PAIR_FIRST(JOY_SEQ_PYUNZIP_S(s, fields))                     \
    ) fields                                                                   \
/**/

/*!
 * Delete a field of an object.
 *
 * @note If the field is not found, nothing is done.
 */
#define NSTL_UNSETF(self, field) \
    NSTL_UNSETF_S(CHAOS_PP_STATE(), self, field)

#define NSTL_UNSETF_S(s, self, field)                                          \
    JOY_SEQ_REMOVE_IF_S(s,                                                     \
        NSTL_I_TYPE_COMPARE, self, JOY_PAIR(field, ~)                          \
    )                                                                          \
/**/

/*!
 * Delete many fields at once.
 *
 * @param fields A sequence of field names to delete.
 */
#define NSTL_UNSETFS(self, fields) \
    NSTL_UNSETFS_S(CHAOS_PP_STATE(), self, fields)

#define NSTL_UNSETFS_S(s, self, fields) \
    JOY_SEQ_REMOVE_IF_S(s, NSTL_I_UNSETFS_PRED, self, fields)

#define NSTL_I_UNSETFS_PRED(s, field, to_del) \
    JOY_SEQ_CONTAINS_S(s, NSTL_II_UNSETFS_PRED, to_del, JOY_PAIR_FIRST(field))

#define NSTL_II_UNSETFS_PRED(s, x, y) \
    JOY_STRING_EQ_S(s, NSTL_TOKEN_TO_STRING(x), NSTL_TOKEN_TO_STRING(y))

/*!
 * Return whether an object has a given field.
 */
#define NSTL_ISSET(self, field) \
    NSTL_ISSET_S(CHAOS_PP_STATE(), self, field)

#define NSTL_ISSET_S(s, self, field)                                           \
    JOY_SEQ_CONTAINS_S(s,                                                      \
        NSTL_I_TYPE_COMPARE, self, JOY_PAIR(field, ~)                          \
    )                                                                          \
/**/

/*!
 * Dump the value of each field of an object.
 */
#define NSTL_DUMPF(self) \
    NSTL_DUMPF_S(CHAOS_PP_STATE(), self)

#define NSTL_DUMPF_S(s, self)                                                  \
    CHAOS_PP_SEQ_TO_STRING(                                                    \
        JOY_PAIR_SECOND(JOY_SEQ_PYUNZIP_S(s, self))                            \
    )                                                                          \
/**/

#endif /* !NSTL_INTERNAL_TYPE_H */
