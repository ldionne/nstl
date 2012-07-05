/*!
 * Macros to create and manipulate metatypes.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_TYPE_H
#define NSTL_TYPE_H

#include <nstl/internal/token.h>
#include <nstl/internal/config.h>
#include <nstl/internal/operator.h>
#include <nstl/internal/common_fields.h>

#include <joy/seq/append.h>
#include <joy/seq/contains.h>
#include <joy/seq/find_first.h>
#include <joy/seq/pyunzip.h>
#include <joy/seq/remove_if.h>
#include <joy/string/eq.h>
#include <joy/pair.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/seq/to_string.h>
#include <chaos/preprocessor/seq/fold_left.h>
#include <chaos/preprocessor/cat.h>


/******************************************************************************
                                 NSTL_TYPE
 ******************************************************************************/

/*!
 * Create a new nstl type.
 *
 * @param instructions A sequence of instructions:
 *                     (instruction_1 args...)
 *                     (instruction_2 args...)
 *                              ...
 *                     (instruction_n args...)
 */
#define NSTL_TYPE(instructions) \
    NSTL_TYPE_S(CHAOS_PP_STATE(), instructions)

#define NSTL_TYPE_S(s, instructions)                                           \
    CHAOS_PP_EXPR_S(s)(CHAOS_PP_SEQ_FOLD_LEFT_S(s,                             \
        NSTL_I_EXECUTE_STATEMENT,                                              \
        instructions,                                                          \
        NSTL_I_INITIAL_TYPE_STATE()                                            \
    ))                                                                         \
/**/

/* This is necessary because we can not have an empty argument as the initial
 * state in C89.
 */
#if NSTL_CONFIG_EMPTY_MACRO_ARGS
#   define NSTL_I_INITIAL_TYPE_STATE() /* nothing */
#else
#   define NSTL_I_INITIAL_TYPE_STATE() \
        ((NSTL_I_C89_COMPAT_0xDUMMY_MEMBER, NSTL_I_C89_COMPAT_0xDUMMY_MEMBER))
#   define NSTL_TOKEN_NSTL_I_C89_COMPAT_0xDUMMY_MEMBER \
        (N S T L _ I _ C 8 9 _ C O M P A T _ 0 X D U M M Y _ M E M B E R)
#endif /* NSTL_CONFIG_EMPTY_MACRO_ARGS */

/*!
 * Execute a statement of the form ``instruction args...''.
 */
#define NSTL_I_EXECUTE_STATEMENT(s, stmnt, self)                               \
    NSTL_II_EXECUTE_STATEMENT(s,                                               \
        self, NSTL_TOKEN_STRING_HEAD(stmnt), NSTL_TOKEN_STRING_TAIL(stmnt)     \
    )                                                                          \
/**/

#define NSTL_II_EXECUTE_STATEMENT(s, self, instruction, args) \
    NSTL_INSTRUCTION(instruction)(s, self, args)

/*!
 * Return whether two (field_name, value) pairs represent the same field.
 * Only the field name is checked.
 */
#define NSTL_I_TYPE_COMPARE(s, x, y)                                           \
    JOY_STRING_EQ_S(s,                                                         \
        NSTL_TOKEN_TO_STRING(JOY_PAIR_FIRST(x)),                               \
        NSTL_TOKEN_TO_STRING(JOY_PAIR_FIRST(y))                                \
    )                                                                          \
/**/

/*!
 * Given a token, return the nstl style instruction associated to it.
 *
 * @note In order for this macro to work properly, the NSTL_INSTRUCTION_instr
 *       macro must be defined properly.
 */
#define NSTL_INSTRUCTION(instr) CHAOS_PP_CAT(NSTL_INSTRUCTION_, instr)

/******************************************************************************
                                  NSTL_GETF
 ******************************************************************************/

/*!
 * Return the value of a field of an object.
 *
 * @param field A valid nstl token.
 */
#define NSTL_GETF(self, field) \
    NSTL_GETF_S(CHAOS_PP_STATE(), self, field)

#define NSTL_GETF_S(s, self, field)                                            \
    JOY_PAIR_SECOND(JOY_SEQ_FIND_FIRST_S(s,                                    \
        NSTL_I_TYPE_COMPARE, self, JOY_PAIR(field, ~)                          \
    ))                                                                         \
/**/

/*!
 * Instruction to get a single field from a nstl type and import it in
 * another one.
 *
 * Usage: @code (getf field_to_import OTHER_NSTL_TYPE) @endcode
 *
 * @note This is functionally equivalent to writing:
 *       @code (setf field NSTL_GETF(other, field)) @endcode
 */
#define NSTL_INSTRUCTION_getf(s, self, field_and_other)                        \
    NSTL_I_INSTRUCTION_getf(s, self,                                           \
        NSTL_TOKEN_STRING_HEAD(field_and_other),                               \
        NSTL_TOKEN_STRING_TAIL(field_and_other)                                \
    )                                                                          \
/**/

#define NSTL_I_INSTRUCTION_getf(s, self, field, other) \
    NSTL_SETF_S(s, self, field, NSTL_GETF_S(s, other, field))
#define NSTL_TOKEN_getf (g e t f)

/******************************************************************************
                                  NSTL_SETF
 ******************************************************************************/

/*!
 * Set or override a field of an object.
 *
 * @param field A valid nstl token.
 * @param value Anything containing no commas if < C99, and anything
 *              if >= C99. This will be the value of the field that can be
 *              retrieved by using @em NSTL_GETF().
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
 * Instruction counterpart of @em NSTL_SETF().
 *
 * Usage: @code (setf field_name field_value) @endcode
 *
 * Where @em field_name is any valid nstl token and @em field_value is
 * anything (without commas if < C99).
 */
#define NSTL_INSTRUCTION_setf(s, self, field_and_value)                        \
    NSTL_SETF_S(s, self,                                                       \
        NSTL_TOKEN_STRING_HEAD(field_and_value),                               \
        NSTL_TOKEN_STRING_TAIL(field_and_value)                                \
    )                                                                          \
/**/
#define NSTL_TOKEN_setf (s e t f)

/******************************************************************************
                                 NSTL_UNSETF
 ******************************************************************************/

/*!
 * Unset a field of an object.
 *
 * @param field A valid nstl token representing the field to unset.
 *
 * @note If the field is not set, nothing is done.
 */
#define NSTL_UNSETF(self, field) \
    NSTL_UNSETF_S(CHAOS_PP_STATE(), self, field)

#define NSTL_UNSETF_S(s, self, field)                                          \
    JOY_SEQ_REMOVE_IF_S(s,                                                     \
        NSTL_I_TYPE_COMPARE, self, JOY_PAIR(field, ~)                          \
    )                                                                          \
/**/

/*!
 * Instruction counterpart of @em NSTL_UNSETF().
 */
#define NSTL_INSTRUCTION_unsetf(s, self, field) NSTL_UNSETF_S(s, self, field)
#define NSTL_TOKEN_unsetf (u n s e t f)

/******************************************************************************
                                 NSTL_INHERIT
 ******************************************************************************/

/*!
 * Inherit from all the inheritable fields of another type.
 *
 * @param super A type to inherit fields from.
 */
#define NSTL_INHERIT(self, super) \
    NSTL_SETFS_S(CHAOS_PP_STATE(), self, super)

#if NSTL_CONFIG_EMPTY_MACRO_ARGS
#   define NSTL_INHERIT_S(s, self, super) NSTL_I_INHERIT(s, self, super)
#else
#   define NSTL_INHERIT_S(s, self, super)                                      \
        NSTL_I_INHERIT(s,                                                      \
            self, NSTL_UNSETF_S(s, super, NSTL_I_C89_COMPAT_0xDUMMY_MEMBER)    \
        )                                                                      \
    /**/
#endif /* NSTL_CONFIG_EMPTY_MACRO_ARGS */

#define NSTL_I_INHERIT(s, self, super)                                         \
    NSTL_DROP_S(s, self,                                                       \
        CHAOS_PP_SEQ_TO_STRING(                                                \
            JOY_PAIR_FIRST(JOY_SEQ_PYUNZIP_S(s, super))                        \
        )                                                                      \
    ) super                                                                    \
/**/

/*!
 * Instruction counterpart of @em NSTL_INHERIT().
 *
 * @param super A nstl type to inherit fields from.
 */
#define NSTL_INSTRUCTION_inherit(s, self, super) NSTL_INHERIT_S(s, self, super)
#define NSTL_TOKEN_inherit (i n h e r i t)

/******************************************************************************
                                 NSTL_DROP
 ******************************************************************************/

/*!
 * Unset many fields at once.
 *
 * @param fields A token string consisting of the field names to unset.
 *
 * @note Nothing is done for the fields that are not already set.
 */
#define NSTL_DROP(self, fields) \
    NSTL_DROP_S(CHAOS_PP_STATE(), self, fields)

#define NSTL_DROP_S(s, self, fields)                                           \
    JOY_SEQ_REMOVE_IF_S(s,                                                     \
        NSTL_I_DROP_PRED, self, NSTL_TOKEN_STRING_TO_SEQ_S(s, fields)          \
    )                                                                          \
/**/

#define NSTL_I_DROP_PRED(s, field, to_del) \
    JOY_SEQ_CONTAINS_S(s, NSTL_II_DROP_PRED, to_del, JOY_PAIR_FIRST(field))

#define NSTL_II_DROP_PRED(s, x, y) \
    JOY_STRING_EQ_S(s, NSTL_TOKEN_TO_STRING(x), NSTL_TOKEN_TO_STRING(y))

/*!
 * Instruction counterpart of @em NSTL_DROP().
 */
#define NSTL_INSTRUCTION_drop(s, self, fields) NSTL_DROP_S(s, self, fields)
#define NSTL_TOKEN_drop (d r o p)

/******************************************************************************
                                  NSTL_ISSET
 ******************************************************************************/

/*!
 * Return whether a given field is set on an object.
 *
 * @param field A valid nstl token.
 */
#define NSTL_ISSET(self, field) \
    NSTL_ISSET_S(CHAOS_PP_STATE(), self, field)

#define NSTL_ISSET_S(s, self, field)                                           \
    JOY_SEQ_CONTAINS_S(s,                                                      \
        NSTL_I_TYPE_COMPARE, self, JOY_PAIR(field, ~)                          \
    )                                                                          \
/**/

/******************************************************************************
                                NSTL_IMPLEMENT
 ******************************************************************************/

/*!
 * Instatiate the implementation of an object.
 */
#define NSTL_IMPLEMENT(self) NSTL_IMPLEMENT_S(CHAOS_PP_STATE(), self)

#if NSTL_CONFIG_EMPTY_MACRO_ARGS
#   define NSTL_IMPLEMENT_S(s, self) NSTL_I_IMPLEMENT(s, self)
#else
#   define NSTL_IMPLEMENT_S(s, self)                                           \
        NSTL_I_IMPLEMENT(s,                                                    \
            NSTL_UNSETF_S(s, self, NSTL_I_C89_COMPAT_0xDUMMY_MEMBER)           \
        )                                                                      \
    /**/
#endif /* NSTL_CONFIG_EMPTY_MACRO_ARGS */

#define NSTL_I_IMPLEMENT(s, self)                                              \
    CHAOS_PP_SEQ_TO_STRING(                                                    \
        JOY_PAIR_SECOND(JOY_SEQ_PYUNZIP_S(s, self))                            \
    )                                                                          \
/**/

#endif /* !NSTL_TYPE_H */
