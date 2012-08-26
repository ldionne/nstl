# Code style / conventions
The conventions listed here are used throughout the entire library, without
derogation:

* Variabe names

    All lowercase with words separated by one underscore.

* Function names

    All lowercase with words separated by one underscore. All functions are
    prefixed with the _nstl\__ particule to separate user and library
    namespaces.

* Macros

    All uppercase with words separated by one underscore. All macros are
    prefixed with the _NSTL\__ particule to separate user and library
    namespaces.

* Type names

    For library type names, all lowercase with words separated by one
    underscore. Library type names are also prefixed with _nstl\__ to separate
    user and library namespaces. Type names that are given by the user
    (such as template parameters) are written in UpperCamelCase.

* Internal function/macro names

    All functions / macros that are meant to be used only internally
    by the library must be prefixed with _nstl\_i\__ for functions and
    _NSTL\_I\__ for macros. This supersedes the rule written above.

* Braces

    Braces go at the end of the line of the statement / declaration. Braces
    are ommitted when they are not necessary and when their ommission does not
    make the code hard to understand (inside nested `if`/`else` statements for
    example).

    Bad:

        for (i = 0; i < 10; ++i)
        {

        }

        void function(void)
        {

        }


    Good:

        for (i = 0; i < 10; ++i) {

        }

        void function(void) {

        }

* Structure declarations / typedefs
    All structure declarations are provided with the corresponding
    `typedef`. The `typedef`-only shortcut is never used.

    Bad:

        typedef struct {
            int foo;
        } Foo;


    Good:

        struct Foo {
            int foo;
        };
        typedef struct Foo Foo;

* Lines stop at the 78th column.

* Indents are 4 spaces (no hard tabs).

* There are no trailing whitespaces.

* Don't use open commas. Open commas are commas not enclosed in parenthesis.
  This is very important because a macro containing open commas can break if
  there is no support for variadic macros.

* Comments
    - C-style comments only (`/* */`). This is required for ANSI-C compliance.
    - Comments go before the code they comment.
    - Doxygen comments begin with `/**`, not `/*!`.
    - Doxygen special tags are used with `@` instead of `\`.

* No compiler dependant features are used.
