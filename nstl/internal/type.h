/*!
 * Macros to create and manipulate template types.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_TYPE_H
#define NSTL_INTERNAL_TYPE_H

#include <chaos/preprocessor.h>
#include <joy.h>


/*!
 * Given a token, return a representation valid for use as an attribute name.
 *
 * @note In order for this macro to work properly, the NSTL_ATTRIBUTE_attr
 *       macro must be defined to expand to the preprocessor string version
 *       of the attribute name.
 */
#define NSTL_ATTRIBUTE(attr) CHAOS_PP_CAT(NSTL_ATTRIBUTE_, attr)

/*!
 * Given a token, return the nstl-style instruction associated to it.
 *
 * @note In order for this macro to work properly, the NSTL_INSTRUCTION_instr
 *       macro must be defined properly.
 */
#define NSTL_INSTRUCTION(instr) CHAOS_PP_CAT(NSTL_INSTRUCTION_, instr)

/*!
 * Create a new nstl type.
 */
#define NSTL_TYPE(attributes) \
    NSTL_TYPE_S(CHAOS_PP_STATE(), attributes)

#define NSTL_TYPE_S(s, attributes)                                             \
    JOY_EXECUTE_FOLD_S(s,                                                      \
        JOY_PB_OBJECT_S(s, /*no attrs*/),                                      \
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
    JOY_INSTRUCTION(                                                           \
        NSTL_INSTRUCTION(CHAOS_PP_STRING_HEAD(instruction)),                   \
        CHAOS_PP_STRING_TAIL(instruction)                                      \
    )                                                                          \
/**/

/*!
 * Instantiate the implementation of each attribute of a nstl type.
 */
#define NSTL_IMPLEMENT(self) \
    NSTL_IMPLEMENT_S(CHAOS_PP_STATE(), self)

#define NSTL_IMPLEMENT_S(s, self)                                              \
    CHAOS_PP_SEQ_TO_STRING(                                                    \
        JOY_PAIR_SECOND(                                                       \
            JOY_SEQUNZIP_S(s,                                                  \
                JOY_MAP_TO_SEQ_S(s, self)                                      \
            )                                                                  \
        )                                                                      \
    )                                                                          \
/**/

#endif /* !NSTL_INTERNAL_TYPE_H */
