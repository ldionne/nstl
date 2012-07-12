/**
 * Internal configuration file to enable/disable features depending on the
 * platform.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_CONFIG_H
#define NSTL_INTERNAL_CONFIG_H

/**
 * This flag is enabled when it is allowed to pass empty arguments to macros.
 */
#define NSTL_CONFIG_EMPTY_MACRO_ARGS 0

/**
 * This flag is enabled when variadic macros are supported.
 */
#define NSTL_CONFIG_VARIADIC_MACROS 0

/**
 * This macro is used to specify that a function should be inlined by the
 * compiler. This is for compatibility with dialects older than C99.
 */
#define NSTL_INLINE

/**
 * This flag is enabled when the long long and unsigned long long types are
 * available.
 */
#define NSTL_CONFIG_LONG_LONG_AVAILABLE 0

/**
 * This flag is enabled when the @em stdbool.h header is available, i.e.
 * when @em bool, @em true, and @em false can be used.
 */
#define NSTL_CONFIG_BOOL_IS_AVAILABLE 0

#endif /* !NSTL_INTERNAL_CONFIG_H */
