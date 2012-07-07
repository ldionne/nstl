/*!
 * Macros to manipulate fields.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_FIELD_H
#define NSTL_INTERNAL_FIELD_H

#include <nstl/internal/token.h>

#include <chaos/preprocessor/cat.h>
#include <chaos/preprocessor/seq/fold_right.h>
#include <chaos/preprocessor/seq/elem.h>
#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/arithmetic/add.h>


/*!
 * Create a nstl field.
 *
 * @param name A valid nstl token.
 * @param properties A token string of properties.
 * @param value The value of the field.
 */
#define NSTL_FIELD(name, properties, value) \
    NSTL_FIELD_S(CHAOS_PP_STATE(), name, properties, value)

#define NSTL_FIELD_S(s, name, properties, value) \
    (name) (NSTL_I_FIELD_SUM_PROPERTIES(s, properties)) (value)

#define NSTL_I_FIELD_SUM_PROPERTIES(s, properties)                             \
    CHAOS_PP_EXPR_S(s)(CHAOS_PP_SEQ_FOLD_RIGHT_S(s,                            \
        NSTL_II_FIELD_SUM_PROPERTIES,                                          \
        NSTL_TOKEN_STRING_TO_SEQ_S(s, properties),                             \
        /* initial value of the sum = */ 0                                     \
    ))                                                                         \
/**/

/* CHAOS_PP_CATing ``NSTL_I_FIELD_PROP_'' and property will expand to
 * the value of the property; see script below.
 */
#define NSTL_II_FIELD_SUM_PROPERTIES(s, property, total) \
    CHAOS_PP_ADD(total, CHAOS_PP_CAT(NSTL_I_FIELD_PROP_, property))

/*!
 * Return the name of a field.
 */
#define NSTL_FIELD_NAME(field) CHAOS_PP_SEQ_ELEM(0, field)

/*!
 * Return the properties of a field.
 *
 * Properties define what is possible to do with a field. Internally,
 * properties are stored using their number equivalent. It works pretty
 * much like file system permissions in Unix (@see `chmod`).
 *
 * The sum of the properties is computed and the resulting unique number
 * defines what is allowed and what is restricted for that field.
 *
 * @return The sum of the properties of a field.
 */
#define NSTL_FIELD_PROPERTIES(field) CHAOS_PP_SEQ_ELEM(1, field)

/*!
 * Return the value of a field.
 */
#define NSTL_FIELD_VALUE(field) CHAOS_PP_SEQ_ELEM(2, field)

/*!
 * Return whether a field is writable.
 */
#define NSTL_FIELD_IS_WRITABLE(field) \
    CHAOS_PP_CAT(NSTL_I_FIELD_PROP_writable_, NSTL_FIELD_PROPERTIES(field))

/*!
 * Return whether a field can be instantiated.
 */
#define NSTL_FIELD_IS_INSTANTIABLE(field) \
    CHAOS_PP_CAT(NSTL_I_FIELD_PROP_instantiable_, NSTL_FIELD_PROPERTIES(field))

/*!
 * Return whether a field can be inherited.
 */
#define NSTL_FIELD_IS_INHERITABLE(field) \
    CHAOS_PP_CAT(NSTL_I_FIELD_PROP_inheritable_, NSTL_FIELD_PROPERTIES(field))

/*!
 * Return whether a field is an anonymous field, i.e. whether it can't be
 * referenced using a name.
 */
#define NSTL_FIELD_IS_ANONYMOUS(field) \
    CHAOS_PP_CAT(NSTL_I_FIELD_PROP_anonymous_, NSTL_FIELD_PROPERTIES(field))


/* [[[cog

"""
Generate ``#define NSTL_I_FIELD_PROP_xx_n 0|1'' automatically, so the property
macros only have to CHAOS_PP_CAT() with the properties.
"""

import nstl
import itertools

PROPERTIES_VALUES = [(prop, 2**power) for power, prop in enumerate([
    'inheritable', 'instantiable', 'writable', 'anonymous',
    '__nstl_dummy_field',
    ])]

properties, values = zip(*PROPERTIES_VALUES)
all_possible_mods = itertools.chain.from_iterable(
    itertools.combinations(values, number_of_props_set)
                for number_of_props_set in range(len(PROPERTIES_VALUES) + 1))

all_possible_sums = list(map(sum, all_possible_mods))

template = "#define NSTL_I_FIELD_PROP_{}_{} {}"
value_template = "#define NSTL_I_FIELD_PROP_{} {}"

for prop, value in PROPERTIES_VALUES:
    cog.outl(value_template.format(prop, value))
    for n in sorted(all_possible_sums):
        cog.outl(template.format(prop, n, int(bool(value & n))))

cog.outl(nstl.generate(*properties, token=True))

]]] */
#define NSTL_I_FIELD_PROP_inheritable 1
#define NSTL_I_FIELD_PROP_inheritable_0 0
#define NSTL_I_FIELD_PROP_inheritable_1 1
#define NSTL_I_FIELD_PROP_inheritable_2 0
#define NSTL_I_FIELD_PROP_inheritable_3 1
#define NSTL_I_FIELD_PROP_inheritable_4 0
#define NSTL_I_FIELD_PROP_inheritable_5 1
#define NSTL_I_FIELD_PROP_inheritable_6 0
#define NSTL_I_FIELD_PROP_inheritable_7 1
#define NSTL_I_FIELD_PROP_inheritable_8 0
#define NSTL_I_FIELD_PROP_inheritable_9 1
#define NSTL_I_FIELD_PROP_inheritable_10 0
#define NSTL_I_FIELD_PROP_inheritable_11 1
#define NSTL_I_FIELD_PROP_inheritable_12 0
#define NSTL_I_FIELD_PROP_inheritable_13 1
#define NSTL_I_FIELD_PROP_inheritable_14 0
#define NSTL_I_FIELD_PROP_inheritable_15 1
#define NSTL_I_FIELD_PROP_inheritable_16 0
#define NSTL_I_FIELD_PROP_inheritable_17 1
#define NSTL_I_FIELD_PROP_inheritable_18 0
#define NSTL_I_FIELD_PROP_inheritable_19 1
#define NSTL_I_FIELD_PROP_inheritable_20 0
#define NSTL_I_FIELD_PROP_inheritable_21 1
#define NSTL_I_FIELD_PROP_inheritable_22 0
#define NSTL_I_FIELD_PROP_inheritable_23 1
#define NSTL_I_FIELD_PROP_inheritable_24 0
#define NSTL_I_FIELD_PROP_inheritable_25 1
#define NSTL_I_FIELD_PROP_inheritable_26 0
#define NSTL_I_FIELD_PROP_inheritable_27 1
#define NSTL_I_FIELD_PROP_inheritable_28 0
#define NSTL_I_FIELD_PROP_inheritable_29 1
#define NSTL_I_FIELD_PROP_inheritable_30 0
#define NSTL_I_FIELD_PROP_inheritable_31 1
#define NSTL_I_FIELD_PROP_instantiable 2
#define NSTL_I_FIELD_PROP_instantiable_0 0
#define NSTL_I_FIELD_PROP_instantiable_1 0
#define NSTL_I_FIELD_PROP_instantiable_2 1
#define NSTL_I_FIELD_PROP_instantiable_3 1
#define NSTL_I_FIELD_PROP_instantiable_4 0
#define NSTL_I_FIELD_PROP_instantiable_5 0
#define NSTL_I_FIELD_PROP_instantiable_6 1
#define NSTL_I_FIELD_PROP_instantiable_7 1
#define NSTL_I_FIELD_PROP_instantiable_8 0
#define NSTL_I_FIELD_PROP_instantiable_9 0
#define NSTL_I_FIELD_PROP_instantiable_10 1
#define NSTL_I_FIELD_PROP_instantiable_11 1
#define NSTL_I_FIELD_PROP_instantiable_12 0
#define NSTL_I_FIELD_PROP_instantiable_13 0
#define NSTL_I_FIELD_PROP_instantiable_14 1
#define NSTL_I_FIELD_PROP_instantiable_15 1
#define NSTL_I_FIELD_PROP_instantiable_16 0
#define NSTL_I_FIELD_PROP_instantiable_17 0
#define NSTL_I_FIELD_PROP_instantiable_18 1
#define NSTL_I_FIELD_PROP_instantiable_19 1
#define NSTL_I_FIELD_PROP_instantiable_20 0
#define NSTL_I_FIELD_PROP_instantiable_21 0
#define NSTL_I_FIELD_PROP_instantiable_22 1
#define NSTL_I_FIELD_PROP_instantiable_23 1
#define NSTL_I_FIELD_PROP_instantiable_24 0
#define NSTL_I_FIELD_PROP_instantiable_25 0
#define NSTL_I_FIELD_PROP_instantiable_26 1
#define NSTL_I_FIELD_PROP_instantiable_27 1
#define NSTL_I_FIELD_PROP_instantiable_28 0
#define NSTL_I_FIELD_PROP_instantiable_29 0
#define NSTL_I_FIELD_PROP_instantiable_30 1
#define NSTL_I_FIELD_PROP_instantiable_31 1
#define NSTL_I_FIELD_PROP_writable 4
#define NSTL_I_FIELD_PROP_writable_0 0
#define NSTL_I_FIELD_PROP_writable_1 0
#define NSTL_I_FIELD_PROP_writable_2 0
#define NSTL_I_FIELD_PROP_writable_3 0
#define NSTL_I_FIELD_PROP_writable_4 1
#define NSTL_I_FIELD_PROP_writable_5 1
#define NSTL_I_FIELD_PROP_writable_6 1
#define NSTL_I_FIELD_PROP_writable_7 1
#define NSTL_I_FIELD_PROP_writable_8 0
#define NSTL_I_FIELD_PROP_writable_9 0
#define NSTL_I_FIELD_PROP_writable_10 0
#define NSTL_I_FIELD_PROP_writable_11 0
#define NSTL_I_FIELD_PROP_writable_12 1
#define NSTL_I_FIELD_PROP_writable_13 1
#define NSTL_I_FIELD_PROP_writable_14 1
#define NSTL_I_FIELD_PROP_writable_15 1
#define NSTL_I_FIELD_PROP_writable_16 0
#define NSTL_I_FIELD_PROP_writable_17 0
#define NSTL_I_FIELD_PROP_writable_18 0
#define NSTL_I_FIELD_PROP_writable_19 0
#define NSTL_I_FIELD_PROP_writable_20 1
#define NSTL_I_FIELD_PROP_writable_21 1
#define NSTL_I_FIELD_PROP_writable_22 1
#define NSTL_I_FIELD_PROP_writable_23 1
#define NSTL_I_FIELD_PROP_writable_24 0
#define NSTL_I_FIELD_PROP_writable_25 0
#define NSTL_I_FIELD_PROP_writable_26 0
#define NSTL_I_FIELD_PROP_writable_27 0
#define NSTL_I_FIELD_PROP_writable_28 1
#define NSTL_I_FIELD_PROP_writable_29 1
#define NSTL_I_FIELD_PROP_writable_30 1
#define NSTL_I_FIELD_PROP_writable_31 1
#define NSTL_I_FIELD_PROP_anonymous 8
#define NSTL_I_FIELD_PROP_anonymous_0 0
#define NSTL_I_FIELD_PROP_anonymous_1 0
#define NSTL_I_FIELD_PROP_anonymous_2 0
#define NSTL_I_FIELD_PROP_anonymous_3 0
#define NSTL_I_FIELD_PROP_anonymous_4 0
#define NSTL_I_FIELD_PROP_anonymous_5 0
#define NSTL_I_FIELD_PROP_anonymous_6 0
#define NSTL_I_FIELD_PROP_anonymous_7 0
#define NSTL_I_FIELD_PROP_anonymous_8 1
#define NSTL_I_FIELD_PROP_anonymous_9 1
#define NSTL_I_FIELD_PROP_anonymous_10 1
#define NSTL_I_FIELD_PROP_anonymous_11 1
#define NSTL_I_FIELD_PROP_anonymous_12 1
#define NSTL_I_FIELD_PROP_anonymous_13 1
#define NSTL_I_FIELD_PROP_anonymous_14 1
#define NSTL_I_FIELD_PROP_anonymous_15 1
#define NSTL_I_FIELD_PROP_anonymous_16 0
#define NSTL_I_FIELD_PROP_anonymous_17 0
#define NSTL_I_FIELD_PROP_anonymous_18 0
#define NSTL_I_FIELD_PROP_anonymous_19 0
#define NSTL_I_FIELD_PROP_anonymous_20 0
#define NSTL_I_FIELD_PROP_anonymous_21 0
#define NSTL_I_FIELD_PROP_anonymous_22 0
#define NSTL_I_FIELD_PROP_anonymous_23 0
#define NSTL_I_FIELD_PROP_anonymous_24 1
#define NSTL_I_FIELD_PROP_anonymous_25 1
#define NSTL_I_FIELD_PROP_anonymous_26 1
#define NSTL_I_FIELD_PROP_anonymous_27 1
#define NSTL_I_FIELD_PROP_anonymous_28 1
#define NSTL_I_FIELD_PROP_anonymous_29 1
#define NSTL_I_FIELD_PROP_anonymous_30 1
#define NSTL_I_FIELD_PROP_anonymous_31 1
#define NSTL_I_FIELD_PROP___nstl_dummy_field 16
#define NSTL_I_FIELD_PROP___nstl_dummy_field_0 0
#define NSTL_I_FIELD_PROP___nstl_dummy_field_1 0
#define NSTL_I_FIELD_PROP___nstl_dummy_field_2 0
#define NSTL_I_FIELD_PROP___nstl_dummy_field_3 0
#define NSTL_I_FIELD_PROP___nstl_dummy_field_4 0
#define NSTL_I_FIELD_PROP___nstl_dummy_field_5 0
#define NSTL_I_FIELD_PROP___nstl_dummy_field_6 0
#define NSTL_I_FIELD_PROP___nstl_dummy_field_7 0
#define NSTL_I_FIELD_PROP___nstl_dummy_field_8 0
#define NSTL_I_FIELD_PROP___nstl_dummy_field_9 0
#define NSTL_I_FIELD_PROP___nstl_dummy_field_10 0
#define NSTL_I_FIELD_PROP___nstl_dummy_field_11 0
#define NSTL_I_FIELD_PROP___nstl_dummy_field_12 0
#define NSTL_I_FIELD_PROP___nstl_dummy_field_13 0
#define NSTL_I_FIELD_PROP___nstl_dummy_field_14 0
#define NSTL_I_FIELD_PROP___nstl_dummy_field_15 0
#define NSTL_I_FIELD_PROP___nstl_dummy_field_16 1
#define NSTL_I_FIELD_PROP___nstl_dummy_field_17 1
#define NSTL_I_FIELD_PROP___nstl_dummy_field_18 1
#define NSTL_I_FIELD_PROP___nstl_dummy_field_19 1
#define NSTL_I_FIELD_PROP___nstl_dummy_field_20 1
#define NSTL_I_FIELD_PROP___nstl_dummy_field_21 1
#define NSTL_I_FIELD_PROP___nstl_dummy_field_22 1
#define NSTL_I_FIELD_PROP___nstl_dummy_field_23 1
#define NSTL_I_FIELD_PROP___nstl_dummy_field_24 1
#define NSTL_I_FIELD_PROP___nstl_dummy_field_25 1
#define NSTL_I_FIELD_PROP___nstl_dummy_field_26 1
#define NSTL_I_FIELD_PROP___nstl_dummy_field_27 1
#define NSTL_I_FIELD_PROP___nstl_dummy_field_28 1
#define NSTL_I_FIELD_PROP___nstl_dummy_field_29 1
#define NSTL_I_FIELD_PROP___nstl_dummy_field_30 1
#define NSTL_I_FIELD_PROP___nstl_dummy_field_31 1
#include <joy/cat.h>
#define NSTL_TOKEN_inheritable (i n h e r i t a b l e)
#define NSTL_TOKEN_instantiable (i n s t a n t i a b l e)
#define NSTL_TOKEN_writable (w r i t a b l e)
#define NSTL_TOKEN_anonymous (a n o n y m o u s)
#define NSTL_TOKEN___nstl_dummy_field (_ _ n s t l _ d u m m y _ f i e l d)
/* [[[end]]] */

#endif /* !NSTL_INTERNAL_FIELD_H */
