/*!
 * Macros to create and manipulate template types.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_TYPE_H
#define NSTL_INTERNAL_TYPE_H

#include <nstl/internal/attributes.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/recursion/basic.h>
#include <chaos/preprocessor/seq/transform.h>
#include <chaos/preprocessor/seq/to_string.h>
#include <chaos/preprocessor/facilities/unbox.h>
#include <chaos/preprocessor/facilities/expand.h>
#include <joy/cat.h>
#include <joy/execute.h>
#include <joy/pair.h>
#include <joy/seq/pyunzip.h>
#include <joy/map/to_seq.h>
#include <joy/string/cat.h>


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
        /* no initial state */,                                                \
        NSTL_I_PARSE_TO_JOY_INSTRUCTIONS(s, attributes)                        \
    )                                                                          \
/**/

/*!
 * Given a sequence of (token args...) strings, return a sequence of
 * (token, args...) joy-style instructions.
 */
#define NSTL_I_PARSE_TO_JOY_INSTRUCTIONS(s, seq)                               \
    CHAOS_PP_EXPR_S(s)(CHAOS_PP_SEQ_TRANSFORM_S(s,                             \
        NSTL_I_CREATE_INSTRUCTION_FROM_STR_ARGS_PAIR,                          \
        NSTL_I_PARSE_TO_PAIRS(s, seq),                                         \
        ~                                                                      \
    ))                                                                         \
/**/

/*!
 * Create a valid joy-style instruction from a pair containing a preprocessor
 * string and sequence of arguments.
 */
#define NSTL_I_CREATE_INSTRUCTION_FROM_STR_ARGS_PAIR(s, elem, useless)         \
    JOY_INSTRUCTION(                                                           \
        NSTL_INSTRUCTION(JOY_STRING_CAT_S(s, JOY_PAIR_FIRST(elem))),           \
        JOY_PAIR_SECOND(elem)                                                  \
    )                                                                          \
/**/

/*!
 * Given a sequence of (token args...) strings, return a sequence of
 * (t o k e n, args...) pairs.
 */
#define NSTL_I_PARSE_TO_PAIRS(s, seq)                                          \
    CHAOS_PP_EXPR_S(s)(CHAOS_PP_SEQ_TRANSFORM_S(s,                             \
        NSTL_I_MAKE_PAIR_FROM_TOKEN_AND_ARGS, seq, ~                           \
    ))                                                                         \
/**/

/*!
 * Return a (t o k e n, args...) pair given a (token args...) preprocessor
 * string.
 *
 * @note The NSTL_TOKEN_token macro must be defined properly for the token that
 *       is processed.
 */
#define NSTL_I_MAKE_PAIR_FROM_TOKEN_AND_ARGS(s, token_args, useless)           \
    CHAOS_PP_EXPAND(CHAOS_PP_DEFER(JOY_PAIR)(                                  \
     /* expands to: t o k e n , rest_of_instruction... */                      \
        CHAOS_PP_EXPAND(NSTL_II_MAKE_PAIR_FROM_TOKEN_AND_ARGS                  \
         /* expands to: (t o k e n) rest_of_instruction... */                  \
            NSTL_TOKEN(token_args)                                             \
        )                                                                      \
    ))                                                                         \
/**/
#define NSTL_II_MAKE_PAIR_FROM_TOKEN_AND_ARGS(token) token,

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
