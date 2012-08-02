# __nstl__ - the non standard template library
The __nstl__ is a collection of generic data structures and algorithms written
in ANSI-C.


## Name mapping with the C++ STL
Although most algorithms and data structures are named as their counterpart
in the C++ STL, some names differ. This happened when we felt that a name in
in the C++ STL could be made clearer or more expressive. The following list
shows the mapping of the names from the C++ STL to the __nstl__.

* _adjacent\_find_ --> _find\_adjacent_
* _equal_ --> _is\_equal_
* _find\_first\_of_ --> _find\_any\_of_
* _find\_end_ --> ?
* _search_ --> ?
* _search\_n_ --> ?
* _remove_ --> ?
* _remove\_copy_ --> ?
* _replace_ --> ?
* _replace\_copy_ --> ?
* _unique_ --> _remove\_adjacent_
* _unique\_copy_ --> _remove\_adjacent\_copy_


## Documentation
Since a large portion of the __nstl__ is a reimplementation of the C++ STL,
the choice to not rewrite the documentation was made. For anything sharing
its name with something in the C++ STL, the documentation available for
the C++ STL also applies unless stated otherwise. For anything else, the
documentation appears in the sources as Javadoc comments.


## Building

1. `git clone https://github.com/ldionne/nstl.git`

    Clones the repository.

2. `git submodule update --init`

    Fetches the dependencies stored as submodules.

3. `make gen-cmake`

    Generate the Makefiles on your platform using CMake.

4. `make`

    Builds the library and unit tests.

5. `make run-tests`

    Runs all the unit tests of the library.


## To do
The tasks listed here are things that could/should be considered/done to
improve the __nstl__. The list is certainly incomplete and the order in which
things are listed is irrelevant.

* Think of a way to instantiate C99 style inline functions (when available)
  instead of static inline functions only.

* Consider the possibility of using metatypes as template arguments.

* Use concept checks whenever possible.

* Put the _deref_ operator in the operators, and add a subscript operator.

* Refactor the concepts currently implemented and fix them so they correspond
  to the boost concepts where needed.

* Find a way to give O(1) access to the native operators in the metatypes.

* Precompute the macro expansion of primitive types (not to confound with
  their instantiation, which is already done).

* Consider implementing a reference type.

* Consider instantiating a pointer, pointer to const, reference, const
  reference, etc... for primitive types.

* Find a way to manage temporaries consistently, to avoid memory leaks. One
  challenge is to find a way to deal with unused return values which are
  copies. In C++, their destructor would be called automatically after the
  expression is evaluated, but it is not the case in C, so it must be done
  explicitly in some way.

* Use type traits. Amongst others, it will allow us to eliminate redundant
  `ValueType` arguments to some algorithms dealing with iterators only by
  giving access to `ValueType` via the iterator's traits. Also, we will be
  able to specialize algorithms depending on an iterator's traits.

* Refactor the names used for iterators in the algorithms to make them
  consistent with boost iterator categories.

* Find a way to share helper functions across many levels of algorithms,
  avoiding the useless duplication of function instantiations.

* Leverage variadic macros when available by providing overloaded functions
  and other goodies.

* Implement all the algorithms and data structures available in the C++11 STL.

* Design ranges and write wrappers to use ranges with all the algorithms that
  support it.

* Find a way to factor out common code for \_comp versions of algorithms to
  reduce code size (some algorithms like _equal\_range_ are quite lengthy).

* Consider renaming _min\_element_ and _max\_element_ to something clearer
  like _min\_in_ and _max\_in_ or something similar.

* Implement debug facilities such as validity checks and code instrumentation.


## Code style / conventions
The conventions listed here are used throughout the entire library, without
derogation:

* Variabe names

    All lowercase with words separated by one underscore.

* Function names

    All lowercase with words separated by one underscore. All functions are
    prefixed with the _nstl__ particule to separate user and library
    namespaces.

* Macros

    All uppercase with words separated by one underscore. All macros are
    prefixed with the _NSTL__ particule to separate user and library
    namespaces.

* Type names

    For library type names, all lowercase with words separated by one
    underscore. Library type names are also prefixed with _nstl__ to separate
    user and library namespaces. Type names that are given by the user
    (such as template parameters) are written in UpperCamelCase.

* Internal function/macro names

    All functions / macros that are meant to be used only internally
    by the library must be prefixed with _nstl_i__ for functions and
    _NSTL_I__ for macros. This supersedes the rule written above.

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

* Comments
    - C-style comments only (`/* */`). This is required for ANSI-C compliance.
    - Comments go before the code they comment.
    - Doxygen comments begin with `/**`, not `/*!`.
    - Doxygen special tags are used with `@` instead of `\`.

* No compiler dependant features are used.
