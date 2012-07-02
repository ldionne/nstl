/*!
 * Macros to create and manipulate template types.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_TYPE_H
#define NSTL_TYPE_H

#include <nstl/internal/type.h>
#include <nstl/internal/token.h>
#include <nstl/internal/config.h>
#include <nstl/internal/operator.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/seq/fold_left.h>
#include <chaos/preprocessor/cat.h>


/*!
 * Given a token, return the nstl style instruction associated to it.
 *
 * @note In order for this macro to work properly, the NSTL_INSTRUCTION_instr
 *       macro must be defined properly.
 */
#define NSTL_INSTRUCTION(instr) CHAOS_PP_CAT(NSTL_INSTRUCTION_, instr)

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

/*!
 * This is necessary because we can not have an empty argument as the initial
 * state in c89.
 */
#if NSTL_CONFIG_EMPTY_MACRO_ARGS
#   define NSTL_I_INITIAL_TYPE_STATE()
#else
#   define NSTL_I_INITIAL_TYPE_STATE() \
        ((NSTL_I_C89_COMPAT_0xDUMMY_MEMBER, NSTL_I_C89_COMPAT_0xDUMMY_MEMBER))
#   define NSTL_TOKEN_NSTL_I_C89_COMPAT_0xDUMMY_MEMBER \
        (N S T L _ I _ C 8 9 _ C O M P A T _ 0 X D U M M Y _ M E M B E R)
#endif

/*!
 * Execute a statement of the form ``instruction args...''.
 */
#define NSTL_I_EXECUTE_STATEMENT(s, statement, self)                           \
    NSTL_II_EXECUTE_STATEMENT(s,                                               \
        self,                                                                  \
        NSTL_TOKEN_STRING_HEAD(statement),                                     \
        NSTL_TOKEN_STRING_TAIL(statement)                                      \
    )                                                                          \
/**/

#define NSTL_II_EXECUTE_STATEMENT(s, self, instruction, args)                  \
    NSTL_INSTRUCTION(instruction)(s,                                           \
        self, args                                                             \
    )                                                                          \
/**/

/*!
 * Instatiate the implementation of an object.
 */
#define NSTL_IMPLEMENT(self) NSTL_IMPLEMENT_S(CHAOS_PP_STATE(), self)

#if NSTL_CONFIG_EMPTY_MACRO_ARGS
#   define NSTL_IMPLEMENT_S(s, self) NSTL_DUMPF_S(s, self)
#else
#   define NSTL_IMPLEMENT_S(s, self) \
        NSTL_DUMPF_S(s, \
            NSTL_UNSETF_S(s, self, NSTL_I_C89_COMPAT_0xDUMMY_MEMBER) \
        ) \
    /**/
#endif

/*!
 * Instruction used to remove a field from a nstl type.
 *
 * @note The field must have been added to the type previously.
 *       If the type does not have the given field, nothing is done.
 */
#define NSTL_INSTRUCTION_unsetf(s, self, field) NSTL_UNSETF_S(s, self, field)
#define NSTL_TOKEN_unsetf (u n s e t f)

/*!
 * Instruction used to overwrite or set the value of a field.
 */
#define NSTL_INSTRUCTION_setf(s, self, field_and_value)                        \
    NSTL_SETF_S(s,                                                             \
        self,                                                                  \
        NSTL_TOKEN_STRING_HEAD(field_and_value),                               \
        NSTL_TOKEN_STRING_TAIL(field_and_value)                                \
    )                                                                          \
/**/
#define NSTL_TOKEN_setf (s e t f)

/*!
 * Instruction used to include all the fields of a given @p super nstl type
 * in another nstl type.
 */
#define NSTL_INSTRUCTION_inherit(s, self, super) NSTL_SETFS_S(s, self, super)
#define NSTL_TOKEN_inherit (i n h e r i t)

#endif /* !NSTL_TYPE_H */
