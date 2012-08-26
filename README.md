# __nstl__ - the non standard template library
The __nstl__ is a collection of generic data structures and algorithms written
in ANSI-C.



## Name mapping with the C++ STL
Although most algorithms and data structures are named as their counterpart
in the C++ STL, some names differ. This happened when we felt that a name in
in the C++ STL could be made clearer or more expressive. The following list
shows the mapping of the names from the C++ STL to the __nstl__.

* `adjacent_find` --> `find_adjacent`
* `equal` --> `is_equal`
* `find_first_of` --> `find_any_of`
* `find_end` --> ?
* `mismatch` --> `find_mismatch`
* `search` --> `find_subsequence`
* `search_n` --> ?
* `remove` --> ?
* `remove_copy` --> ?
* `replace` --> ?
* `replace_copy` --> ?
* `unique` --> `remove_adjacent`
* `unique_copy` --> `remove_adjacent_copy`



## Documentation
Since a large portion of the __nstl__ is a reimplementation of the C++ STL,
the choice to not rewrite the documentation was made. For anything sharing
its name with something in the C++ STL, the documentation available for
the C++ STL also applies unless stated otherwise. For anything else, the
documentation appears in the sources or in [the docs](doc/).



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

* Put the `deref` operator in the operators, and add a subscript operator.

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

* Find a way to share helper functions across many levels of algorithms,
  avoiding the useless duplication of function instantiations.

* Leverage variadic macros when available by providing overloaded functions
  and other goodies.

* Implement all the algorithms and data structures available in the C++11 STL.

* Design ranges and write wrappers to use ranges with all the algorithms that
  support it.

* Consider renaming `min_element` and `max_element` to something clearer
  like `min_in` and `max_in` or something similar.

* Implement debug facilities such as validity checks and code instrumentation.
