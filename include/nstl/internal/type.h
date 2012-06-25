/*!
 * Macros to create and manipulate template types.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_TYPE_H
#define NSTL_INTERNAL_TYPE_H

#include <nstl/internal/attributes.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/seq/transform.h>
#include <chaos/preprocessor/seq/to_string.h>
#include <chaos/preprocessor/string/core.h>
#include <joy/cat.h>
#include <joy/execute.h>
#include <joy/pair.h>
#include <joy/seq/pyunzip.h>
#include <joy/map/to_seq.h>


/*!
 * Given a token, return a representation containing its preprocessor string
 * representation as well as parenthesis necessary to make it a valid
 * preprocessor string character.
 *
 * @note In order for this macro to work properly, the NSTL_TOKEN_token
 *       macro must be defined to expand to the preprocessor string version
 *       of the token inside parenthesis.
 */
#define NSTL_TOKEN(token) JOY_CAT_NOEXP(NSTL_TOKEN_, token)

#define NSTL_TOKEN_TO_STRING(token) CHAOS_PP_UNBOX(NSTL_TOKEN(token))

/*!
 * Given a token, return the nstl-style instruction associated to it.
 *
 * @note In order for this macro to work properly, the NSTL_INSTRUCTION_instr
 *       macro must be defined properly.
 */
#define NSTL_INSTRUCTION(instr) JOY_CAT(NSTL_INSTRUCTION_, instr)

/*!
 * Create a new nstl type.
 */
#define NSTL_TYPE(attributes) \
    NSTL_TYPE_S(CHAOS_PP_STATE(), attributes)

#define NSTL_TYPE_S(s, attributes)                                             \
    JOY_EXECUTE_FOLD_S(s,                                                      \
        JOY_OBJECT_S(s, /* no attributes */),                                  \
        NSTL_I_INSTRUCTIONS_TO_JOY(s, attributes)                              \
    )                                                                          \
/**/

/*!
 * Convert user-friendly instructions to joy-style instructions.
 */
#define NSTL_I_INSTRUCTIONS_TO_JOY(s, instructions)                            \
    CHAOS_PP_EXPR_S(s)(CHAOS_PP_SEQ_TRANSFORM_S(s,                             \
        NSTL_II_INSTRUCTIONS_TO_JOY, instructions, ~                           \
    ))                                                                         \
/**/

#define NSTL_II_INSTRUCTIONS_TO_JOY(s, instruction, useless)                   \
    NSTL_II_INSTRUCTIONS_TO_JOY_EXPAND(                                        \
        CHAOS_PP_DEFER(NSTL_IIII_MAKE_JOY_INSTRUCTION)(                        \
            NSTL_III_INSTRUCTIONS_TO_JOY(s, instruction)                       \
        )                                                                      \
    )                                                                          \
/**/
#define NSTL_II_INSTRUCTIONS_TO_JOY_EXPAND(x) x

#define NSTL_III_INSTRUCTIONS_TO_JOY(s, instruction)                           \
 /* expands to: JOY_STRING_CAT_S(s, token), rest_of_instruction... */          \
    JOY_STRING_CAT_S CHAOS_PP_LPAREN() s,                                      \
                                                                               \
         /* expands to: t o k e n) , rest_of_instruction... */                 \
            NSTL_III_INSTRUCTIONS_TO_JOY_EXPAND(NSTL_I_SPLIT_TOKEN             \
                                                                               \
                 /* expands to: (t o k e n) rest_of_instruction... */          \
                    NSTL_TOKEN(instruction)                                    \
            )                                                                  \
/**/
#define NSTL_III_INSTRUCTIONS_TO_JOY_EXPAND(x) x
#define NSTL_I_SPLIT_TOKEN(pp_string) pp_string),

#define NSTL_IIII_MAKE_JOY_INSTRUCTION(instruction, args) \
    JOY_INSTRUCTION(NSTL_INSTRUCTION(instruction), args)

/*!
 * Instantiate the implementation of each attribute of a nstl type.
 */
#define NSTL_IMPLEMENT(self) \
    NSTL_IMPLEMENT_S(CHAOS_PP_STATE(), self)

#define NSTL_IMPLEMENT_S(s, self) \
    CHAOS_PP_SEQ_TO_STRING(JOY_MAP_VALUES_S(s, self))

#endif /* !NSTL_INTERNAL_TYPE_H */
