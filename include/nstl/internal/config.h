/**
 * Internal configuration file to enable/disable features depending on the
 * platform.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_CONFIG_H
#define NSTL_INTERNAL_CONFIG_H

/**
 * This flag is on whenever we are being compiled using the C99 dialect.
 */
#if !__cplusplus && __STDC_VERSION__ >= 199901L
#   define NSTL_CONFIG_C99 1
#else
#   define NSTL_CONFIG_C99 0
#endif

/**
 * This flag is on whenever we are being compiled using C++11.
 */
#if defined(__cplusplus) && __cplusplus >= 201103L
#   define NSTL_CONFIG_CPP11 1
#else
#   define NSTL_CONFIG_CPP11 0
#endif

/**
 * This flag is enabled when it is allowed to pass empty arguments to macros.
 */
#if NSTL_CONFIG_C99 || NSTL_CONFIG_CPP11
#   define NSTL_CONFIG_EMPTY_MACRO_ARGS 1
#else
#   define NSTL_CONFIG_EMPTY_MACRO_ARGS 0
#endif

/**
 * This flag is enabled when variadic macros are supported.
 */
#if NSTL_CONFIG_C99 || NSTL_CONFIG_CPP11
#   define NSTL_CONFIG_VARIADIC_MACROS 1
#else
#   define NSTL_CONFIG_VARIADIC_MACROS 0
#endif

/**
 * This macro is used to specify that a function should be inlined by the
 * compiler. This is for compatibility with dialects older than C99.
 */
#if NSTL_CONFIG_C99 || __cplusplus
#   define NSTL_INLINE inline
#else
#   define NSTL_INLINE /* nothing */
#endif

/**
 * This flag is enabled when the long long and unsigned long long types are
 * available.
 */
#if NSTL_CONFIG_C99
#   define NSTL_CONFIG_LONG_LONG_AVAILABLE 1
#else
#   define NSTL_CONFIG_LONG_LONG_AVAILABLE 0
#endif

/**
 * This flag is enabled when the @em stdbool.h header is available, i.e.
 * when @em bool, @em true, and @em false can be used.
 */
#if NSTL_CONFIG_C99 || __cplusplus
#   define NSTL_CONFIG_BOOL_IS_AVAILABLE 1
#else
#   define NSTL_CONFIG_BOOL_IS_AVAILABLE 0
#endif

/**
 * If this flag is enabled, concept requirements will be checked whenever
 * concept checks appear. If it is disabled, concept requirements won't
 * be checked.
 *
 * Disabling this should decrease compilation time, but metatype errors will
 * be harder to spot.
 */
#define NSTL_CONFIG_CHECK_CONCEPT_REQUIREMENTS 1

#endif /* !NSTL_INTERNAL_CONFIG_H */
