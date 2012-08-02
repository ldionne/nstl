/**
 * Macros to create and manipulate metatypes.
 */

#ifndef NSTL_INTERNAL_TYPE_H
#define NSTL_INTERNAL_TYPE_H

#include <nstl/internal/config.h>
#include <nstl/internal/field.h>
#include <nstl/internal/token.h>

#include <joy/seq/append.h>
#include <joy/seq/contains.h>
#include <joy/seq/find_first.h>
#include <joy/seq/remove_if.h>
#include <joy/string/eq.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/recursion/basic.h>
#include <chaos/preprocessor/seq/filter.h>
#include <chaos/preprocessor/seq/fold_left.h>
#include <chaos/preprocessor/seq/elem.h>
#include <chaos/preprocessor/seq/replace.h>
#include <chaos/preprocessor/seq/for_each.h>
#include <chaos/preprocessor/logical/nor.h>
#include <chaos/preprocessor/logical/and.h>
#include <chaos/preprocessor/control/if.h>
#include <chaos/preprocessor/control/when.h>
#include <chaos/preprocessor/control/unless.h>
#include <chaos/preprocessor/cat.h>


/****************************************************************************
                                 NSTL_TYPE
 ****************************************************************************/

/**
 * Create a new nstl type.
 *
 * @param unique_id A unique C identifier representing the type.
 *                  For example, a nstl type defining a template function
 *                  could have a unique id composed from the base name of
 *                  the function and the unique id of the type used to
 *                  parametrize the template.
 *
 * @param instructions A sequence of instructions:
 *                     (instruction_1 args...)
 *                     (instruction_2 args...)
 *                              ...
 *                     (instruction_n args...)
 */
#define NSTL_TYPE(unique_id, instructions) \
    NSTL_TYPE_S(CHAOS_PP_STATE(), unique_id, instructions)

#define NSTL_TYPE_S(s, unique_id, instructions)                                \
    CHAOS_PP_EXPR_S(s)(CHAOS_PP_SEQ_FOLD_LEFT_S(s,                             \
        NSTL_I_EXECUTE_STATEMENT,                                              \
        instructions,                                                          \
        (unique_id) (NSTL_I_INITIAL_FIELDS_STATE())                            \
    ))                                                                         \
/**/

/* This is necessary because we can not have an empty argument as the initial
 * state in C89.
 */
#if NSTL_CONFIG_EMPTY_MACRO_ARGS
#   define NSTL_I_INITIAL_FIELDS_STATE() /* nothing */
#else
#   define NSTL_I_INITIAL_FIELDS_STATE() (NSTL_FIELD(~, anonymous, ~))
#endif /* NSTL_CONFIG_EMPTY_MACRO_ARGS */

/**
 * Execute a statement of the form ``instruction args...''.
 */
#define NSTL_I_EXECUTE_STATEMENT(s, stmnt, self)                               \
    NSTL_II_EXECUTE_STATEMENT(s, self,                                         \
        NSTL_TOKEN_STRING_HEAD(stmnt),                                         \
        /* we use the UNSAFE version here because we have no clue what can the \
         * arguments be, so we can't make assumptions about them being a valid \
         * token string.                                                       \
         */                                                                    \
        NSTL_TOKEN_STRING_TAIL_UNSAFE(stmnt)                                   \
    )                                                                          \
/**/

#define NSTL_II_EXECUTE_STATEMENT(s, self, instruction, args) \
    NSTL_INSTRUCTION(instruction)(s, self, args)

/**
 * Return whether two fields have the same name.
 */
#define NSTL_I_TYPE_COMPARE(s, x, y)                                           \
    CHAOS_PP_AND                                                               \
        (CHAOS_PP_NOR                                                          \
            (NSTL_FIELD_IS_ANONYMOUS(x))                                       \
            (NSTL_FIELD_IS_ANONYMOUS(y)))                                      \
        (JOY_STRING_EQ_S(s,                                                    \
            NSTL_TOKEN_TO_STRING(NSTL_FIELD_NAME(x)),                          \
            NSTL_TOKEN_TO_STRING(NSTL_FIELD_NAME(y))))                         \
/**/

/**
 * Given a token, return the nstl style instruction associated to it.
 *
 * @note In order for this macro to work properly, the NSTL_INSTRUCTION_instr
 *       macro must be defined properly.
 */
#define NSTL_INSTRUCTION(instr) CHAOS_PP_CAT(NSTL_INSTRUCTION_, instr)

/**
 * Return the unique identifier of a nstl type.
 */
#define NSTL_IDENTIFIER(self) CHAOS_PP_SEQ_ELEM(0, self)

/**
 * Return the fields of a nstl type.
 */
#define NSTL_I_TYPE_FIELDS(self) CHAOS_PP_SEQ_ELEM(1, self)

/**
 * Replace the fields of a nstl type.
 */
#define NSTL_I_TYPE_SET_FIELDS(self, fields) \
    CHAOS_PP_SEQ_REPLACE(1, self, fields)

/****************************************************************************
                                  NSTL_GETF
 ****************************************************************************/

/**
 * Return the value of a field of an object.
 *
 * @param field A valid nstl token.
 */
#define NSTL_GETF(self, field) \
    NSTL_GETF_S(CHAOS_PP_STATE(), self, field)

#define NSTL_GETF_S(s, self, field)                                            \
    CHAOS_PP_WHEN(NSTL_ISSET_S(s, self, field))(                               \
        NSTL_FIELD_VALUE(NSTL_I_GETF(s, self, field))                          \
    )                                                                          \
/**/

/**
 * Return a field of an object. If the field is not set, it is undefined
 * behavior.
 *
 * @note This is an internal macro returning the whole field of the object.
 *       @em NSTL_GETF must be used instead.
 */
#define NSTL_I_GETF(s, self, field)                                            \
    JOY_SEQ_FIND_FIRST_S(s,                                                    \
        NSTL_I_TYPE_COMPARE, NSTL_I_TYPE_FIELDS(self),                         \
                                NSTL_FIELD_S(s, field, __nstl_dummy_field, ~)  \
    )                                                                          \
/**/

/****************************************************************************
                                  NSTL_SETF
 ****************************************************************************/

/**
 * Set or override a field of an object.
 *
 * @param field A valid nstl token.
 * @param properties A token string of the properties of the field.
 * @param value Anything containing no commas if < C99, and anything
 *              if >= C99. This will be the value of the field that can be
 *              retrieved by using @em NSTL_GETF().
 */
#define NSTL_SETF(self, field, properties, value) \
    NSTL_SETF_S(CHAOS_PP_STATE(), self, field, properties, value)

#define NSTL_SETF_S(s, self, field, properties, value)                         \
    NSTL_I_TYPE_SET_FIELDS(self,                                               \
        JOY_SEQ_APPEND(                                                        \
            NSTL_FIELD_S(s, field, properties, value),                         \
            NSTL_I_TYPE_FIELDS(NSTL_UNSETF_S(s, self, field))                  \
        )                                                                      \
    )                                                                          \
/**/

/**
 * Instruction counterpart of @em NSTL_SETF().
 *
 * Usage: @code (setf field_name (field_properties...) field_value) @endcode
 *
 * Where @em field_name is any valid nstl token, @em field_properties is a
 * token string of properties, and @em field_value is anything
 * (without commas if < C99).
 */
#define NSTL_INSTRUCTION_setf(s, self, field_properties_value)                 \
    NSTL_I_INSTRUCTION_setf(s, self,                                           \
        NSTL_TOKEN_STRING_HEAD(field_properties_value),                        \
        /* We use the UNSAFE version here because the properties are inside    \
         * parenthesis and it is not a valid token string.                     \
         */                                                                    \
        NSTL_TOKEN_STRING_TAIL_UNSAFE(field_properties_value)                  \
    )                                                                          \
/**/

#define NSTL_I_INSTRUCTION_setf_EXPAND(x) x
#define NSTL_II_INSTRUCTION_setf_EXPAND(x) x

#define NSTL_I_INSTRUCTION_setf(s, self, field, properties_value)              \
    NSTL_I_INSTRUCTION_setf_EXPAND(CHAOS_PP_DEFER(NSTL_SETF_S)(s, self, field, \
        NSTL_II_INSTRUCTION_setf_EXPAND(                                       \
            NSTL_II_INSTRUCTION_setf_GET_PROPS properties_value                \
        )                                                                      \
    ))                                                                         \
/**/

#define NSTL_II_INSTRUCTION_setf_GET_PROPS(properties) properties,

/****************************************************************************
                                  NSTL_DEFUN
 ****************************************************************************/

/**
 * Define a function as a field of an object.
 *
 * Functions are instantiable, inheritable, and named fields.
 *
 * @param name A valid nstl token representing the name of the function.
 * @param definition The definition of the function that should be
 *                   instantiated when @em NSTL_INSTANTIATE() is called.
 *
 * @warning In pre C99, no commas (except when inside parenthesis) can be used
 *          inside the definition of the function, because this would require
 *          variadic macros.
 */
#define NSTL_DEFUN(self, name, definition) \
    NSTL_DEFUN_S(CHAOS_PP_STATE(), self, name, definition)

#define NSTL_DEFUN_S(s, self, name, definition) \
    NSTL_SETF_S(s, self, name, inheritable instantiable, definition)

/**
 * Instruction counterpart of @em NSTL_DEFUN().
 */
#define NSTL_INSTRUCTION_defun(s, self, name_def)                              \
    NSTL_DEFUN_S(s, self,                                                      \
        NSTL_TOKEN_STRING_HEAD(name_def),                                      \
        /* We use the UNSAFE version here because we can't make assumptions    \
         * the definition of the function being a valid token string.          \
         */                                                                    \
        NSTL_TOKEN_STRING_TAIL_UNSAFE(name_def)                                \
    )                                                                          \
/**/

/****************************************************************************
                                NSTL_DEFSTRUCT
 ****************************************************************************/

/**
 * Define a structure as a field of an object.
 *
 * Structures are instantiable, inheritable, and anonymous fields.
 *
 * @param struct The definition of the structure that should be
 *               instantiated when @em NSTL_INSTANTIATE() is called.
 *
 * @warning In pre C99, no commas (except when inside parenthesis) can be used
 *          inside the structure definition, because this would require
 *          variadic macros.
 */
#define NSTL_DEFSTRUCT(self, struct) \
    NSTL_DEFSTRUCT_S(CHAOS_PP_STATE(), self, struct)

#define NSTL_DEFSTRUCT_S(s, self, struct) \
    NSTL_SETF_S(s, self, ~, anonymous inheritable instantiable, struct)

/**
 * Instruction counterpart of @em NSTL_DEFSTRUCT().
 */
#define NSTL_INSTRUCTION_defstruct(s, self, struct) \
    NSTL_DEFSTRUCT_S(s, self, struct)

/****************************************************************************
                                 NSTL_UNSETF
 ****************************************************************************/

/**
 * Unset a field of an object.
 *
 * @param field A valid nstl token representing the field to unset.
 *
 * @note If the field is not set, nothing is done.
 */
#define NSTL_UNSETF(self, field) \
    NSTL_UNSETF_S(CHAOS_PP_STATE(), self, field)

#define NSTL_UNSETF_S(s, self, field)                                          \
    NSTL_I_TYPE_SET_FIELDS(self,                                               \
        JOY_SEQ_REMOVE_IF_S(s,                                                 \
            NSTL_I_TYPE_COMPARE, NSTL_I_TYPE_FIELDS(self),                     \
                                NSTL_FIELD_S(s, field, __nstl_dummy_field, ~)  \
        )                                                                      \
    )                                                                          \
/**/

/**
 * Instruction counterpart of @em NSTL_UNSETF().
 */
#define NSTL_INSTRUCTION_unsetf(s, self, field) NSTL_UNSETF_S(s, self, field)

/****************************************************************************
                                 NSTL_INHERIT
 ****************************************************************************/

/**
 * Inherit all the inheritable fields of another type.
 *
 * @param super A type to inherit fields from.
 */
#define NSTL_INHERIT(self, super) \
    NSTL_INHERIT_S(CHAOS_PP_STATE(), self, super)

#define NSTL_INHERIT_S(s, self, super)                                         \
    NSTL_I_INHERIT_BATCH_SETF(s,                                               \
        self, NSTL_I_INHERIT_KEEP_INHERITABLE(s, super)                        \
    )                                                                          \
/**/

/**
 * Traverse a @p type and keep only fields that are inheritable.
 */
#define NSTL_I_INHERIT_KEEP_INHERITABLE(s, type)                               \
    NSTL_I_TYPE_SET_FIELDS(type,                                               \
        CHAOS_PP_EXPR_S(s)(CHAOS_PP_SEQ_FILTER_S(s,                            \
            NSTL_II_INHERIT_KEEP_INHERITABLE_PRED, NSTL_I_TYPE_FIELDS(type), ~ \
        ))                                                                     \
    )                                                                          \
/**/
#define NSTL_II_INHERIT_KEEP_INHERITABLE_PRED(s, field, useless) \
    NSTL_FIELD_IS_INHERITABLE(field)

/**
 * Set all the fields of a type @p src to another type @p dst.
 */
#define NSTL_I_INHERIT_BATCH_SETF(s, dst, src)                                 \
    NSTL_II_INHERIT_BATCH_SETF(s,                                              \
        dst,                                                                   \
        NSTL_I_INHERIT_GET_NAMED_FIELD_NAMES(s, NSTL_I_TYPE_FIELDS(src)),      \
        NSTL_I_TYPE_FIELDS(src)                                                \
    )                                                                          \
/**/

/**
 * Drop several fields from a type and then extend the type with some other
 * given fields.
 */
#define NSTL_II_INHERIT_BATCH_SETF(s, type, names_to_drop, fields_to_extend)   \
    NSTL_I_TYPE_SET_FIELDS(type,                                               \
        NSTL_I_TYPE_FIELDS(                                                    \
            CHAOS_PP_IF(CHAOS_PP_IS_EMPTY(names_to_drop))(                     \
                type, NSTL_DROP_S(s, type, names_to_drop)                      \
            )                                                                  \
        ) fields_to_extend                                                     \
    )                                                                          \
/**/

/**
 * Gather a token string containing all the named field names in a sequence
 * of fields.
 */
#define NSTL_I_INHERIT_GET_NAMED_FIELD_NAMES(s, fields)                        \
    CHAOS_PP_EXPR_S(s)(CHAOS_PP_SEQ_FOR_EACH_S(s,                              \
        NSTL_I_INHERIT_PUT_FIELD_NAME_IF, fields, ~                            \
    ))                                                                         \
/**/

#define NSTL_I_INHERIT_PUT_FIELD_NAME_IF(s, field, useless)                    \
    CHAOS_PP_UNLESS(NSTL_FIELD_IS_ANONYMOUS(field))(                           \
        NSTL_FIELD_NAME(field)                                                 \
    )                                                                          \
/**/

/**
 * Instruction counterpart of @em NSTL_INHERIT().
 *
 * @param super A nstl type to inherit fields from.
 */
#define NSTL_INSTRUCTION_inherit(s, self, super) \
    NSTL_INHERIT_S(s, self, super)

/****************************************************************************
                                 NSTL_DROP
 ****************************************************************************/

/**
 * Unset many fields at once.
 *
 * @param fields A token string consisting of the field names to unset.
 *
 * @note Nothing is done for the fields that are not already set.
 */
#define NSTL_DROP(self, fields) \
    NSTL_DROP_S(CHAOS_PP_STATE(), self, fields)

#define NSTL_DROP_S(s, self, fields)                                           \
    NSTL_I_TYPE_SET_FIELDS(self,                                               \
        JOY_SEQ_REMOVE_IF_S(s,                                                 \
            NSTL_I_DROP_PRED,                                                  \
            NSTL_I_TYPE_FIELDS(self),                                          \
            NSTL_TOKEN_STRING_TO_SEQ_S(s, fields)                              \
        )                                                                      \
    )                                                                          \
/**/

#define NSTL_I_DROP_PRED(s, field, to_unset)                                   \
    CHAOS_PP_IF(NSTL_FIELD_IS_ANONYMOUS(field))(0,                             \
        JOY_SEQ_CONTAINS_S(s,                                                  \
            NSTL_II_DROP_PRED, to_unset, NSTL_FIELD_NAME(field)                \
        )                                                                      \
    )                                                                          \
/**/

#define NSTL_II_DROP_PRED(s, x, y) \
    JOY_STRING_EQ_S(s, NSTL_TOKEN_TO_STRING(x), NSTL_TOKEN_TO_STRING(y))

/**
 * Instruction counterpart of @em NSTL_DROP().
 */
#define NSTL_INSTRUCTION_drop(s, self, fields) NSTL_DROP_S(s, self, fields)

/****************************************************************************
                                  NSTL_ISSET
 ****************************************************************************/

/**
 * Return whether a given field is set on an object.
 *
 * @param field A valid nstl token.
 */
#define NSTL_ISSET(self, field) \
    NSTL_ISSET_S(CHAOS_PP_STATE(), self, field)

#define NSTL_ISSET_S(s, self, field)                                           \
    JOY_SEQ_CONTAINS_S(s,                                                      \
        NSTL_I_TYPE_COMPARE, NSTL_I_TYPE_FIELDS(self),                         \
                                NSTL_FIELD_S(s, field, __nstl_dummy_field, ~)  \
    )                                                                          \
/**/

/****************************************************************************
                                NSTL_INSTANTIATE
 ****************************************************************************/

/**
 * Instantiate all the instantiable fields of an object.
 *
 * @note Since the NSTL_I_C89_COMPAT_0xDUMMY_MEMBER field is not instantiable,
 *       we do not need to filter it out specially before instantiating
 *       because it will be filtered out like any other uninstantiable field.
 */
#define NSTL_INSTANTIATE(self) NSTL_INSTANTIATE_S(CHAOS_PP_STATE(), self)

#define NSTL_INSTANTIATE_S(s, self)                                            \
    CHAOS_PP_EXPR_S(s)(CHAOS_PP_SEQ_FOR_EACH_S(s,                              \
        NSTL_II_INSTANTIATE_FIELD_VALUE, NSTL_I_TYPE_FIELDS(self), ~           \
    ))                                                                         \
/**/

#define NSTL_II_INSTANTIATE_FIELD_VALUE(s, field, useless)                     \
    CHAOS_PP_WHEN(NSTL_FIELD_IS_INSTANTIABLE(field))(                          \
        NSTL_FIELD_VALUE(field)                                                \
    )                                                                          \
/**/

/* [[[cog

import nstl
nstl.generate(cog,
    'drop',
    'inherit',
    'unsetf',
    'defun',
    'defstruct',
    'setf',

    token=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_drop (d r o p)
#define NSTL_TOKEN_inherit (i n h e r i t)
#define NSTL_TOKEN_unsetf (u n s e t f)
#define NSTL_TOKEN_defun (d e f u n)
#define NSTL_TOKEN_defstruct (d e f s t r u c t)
#define NSTL_TOKEN_setf (s e t f)
/* [[[end]]] */

#endif /* !NSTL_INTERNAL_TYPE_H */
