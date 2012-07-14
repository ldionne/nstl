/**
 * Workarounds (read hacks) to fix several issues.
 * Let's hope this stays small.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_WORKAROUND_H
#define NSTL_INTERNAL_WORKAROUND_H

/**
 * Macro used to silence warnings emitted by compilers when a function
 * parameter or a variable is not used in a function.
 */
#define NSTL_SILENCE_UNUSED_VARIABLE_WARNING(var) \
    do { (void)var; } while (0)

#endif /* !NSTL_INTERNAL_WORKAROUND_H */
