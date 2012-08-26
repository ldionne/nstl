# Traits
Traits are used very widely in the __nstl__ library. The traits used here
differ from the traits most people are used to.


## What are traits in the __nstl__?
Basically, traits are mappings from key to value. Algorithms in the __nstl__
expect to receive these maps, from which they retrieve necessary information
such as the types to act upon. The algorithm that you wish to instantiate will
dictate the content of the map that you must provide.


## How does it work?
Traits are collections of (key value) pairs. Using some macro trickery, it is
possible to parse sequences of these pairs and to retrieve the value
associated to a given key, which gives us the same functionality as a map
would.


## How are they created?
The whole process of creating traits has been thought over and over to be made
as easy as possible. Here is an example:

    #define MyTraits (key1 value1) (key2 value2)

This defines a simple collection of two traits. Note that in order for this
to work, _key1_ and _key2_ must be valid _nstl tokens_. _value1_ and _value2_,
however, can be arbitrary stuff with the only restriction that they must not
contain open commas if variadic macros are not supported.

## Iterator traits
Iterator traits are traits associated to iterators. They are used everywhere
to instantiate generic algorithms. They differ in some ways from their
equivalent in the C++ STL.

### Keys
The following is a list of keys contained in iterator traits. All the keys
shown here are already defined to be valid _nstl tokens_, so you must not do
anything special before using them.

* `self_type`

    The actual C type described by the trait.

* `value_traits`

    Traits of the type pointed to by an iterator.

* `ref_traits`

    Traits of a type that can be used as a C++ reference to the type described
    by `value_traits`.

* `ptr_traits`

    Traits of a type that can be used as a pointer to the type described by
    `value_traits`.

* `diff_traits`

    Traits of a type that can be used to represent the distance from one
    iterator to the other, or the number of elements in a range. The type
    described by this field must behave like a signed integral type.

* `traversal_category`

    Category of the traversal supported by an iterator.
