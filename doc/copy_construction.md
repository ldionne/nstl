# On copy construction
When passing arguments by value to a function, one's copy of the arguments are
not expected to change. C++ insures this by calling the copy constructor,
which performs a deep copy of the object, whenever arguments are passed by
value. The called function can then do anything with its copy of the arguments
without impacting the calling function's copy:

    #include <cassert>


    struct Foo {
        Foo(int x) : i(new int(x)) { }
        Foo(Foo const &other) : i(new int(*other.i)) { }
        ~Foo() { delete i; }
        int *i;
    };

    namespace {
        void modify_copy_of_argument(Foo foo) {
            // Anything could be done here, it will never affect
            // main's foo because we are modifying a copy.
            ++(*foo.i);
        }
    }

    int main(int argc, char const *argv[]) {
        Foo foo(0);

        modify_copy_of_argument(foo);
        assert(*foo.i == 0);

        return 0;
    }

However, C has no notion of constructor and arguments passed by value are only
shallowly copied. For this reason, modifications to arguments passed by value
in the callee could eventually affect the calling function's copy:

    #include <assert.h>
    #include <stdlib.h>


    struct Foo {
        int *i;
    };

    static void Foo_ctor(Foo *self, int x) {
        self->i = (int *)malloc(sizeof(*self->i));
        *self->i = x;
    }

    static void Foo_dtor(Foo *self) {
        free(self->i);
    }

    static void modify_copy_of_argument(Foo foo) {
        /* Here, we modify main's foo even though we receive
         * a copy of it. We would require a deep copy but
         * only a shallow copy was made, and we end up
         * corrupting the object.
         */
        ++(*foo.i);
    }

    int main(int argc, char const *argv[]) {
        Foo foo;
        Foo_ctor(&foo, 0);

        modify_copy_of_argument(foo);
        assert(*foo.i != 0);

        Foo_dtor(&foo);
        return 0;
    }

To circumvent this, some rules need to be defined.

1. A copy constructor must be defined when a type holds pointers. In order to
   be well behaved, the copy constructor should perform a deep copy of the
   object.

2. Any function modifying the memory pointed to by a pointer owned by an
   object received by value or obtained from an object passed by value should
   make a deep copy before performing the operation.

3. Any function passing an object received by value or obtained from an object
   passed by value to another function by reference should make a deep copy of
   the object first, since the function receiving the object by reference is
   not bound to any specific rules concerning the preservation of the object.

Here is how it looks like in C:

    #include <assert.h>
    #include <stdlib.h>


    struct Foo {
        int *i;
    };

    static void Foo_ctor(Foo *self, int x) {
        self->i = (int *)malloc(sizeof(*self->i));
        *self->i = x;
    }

    static void Foo_copy_ctor(Foo *self, Foo other) {
        /* Perform deep copy. */
        Foo_ctor(self, *other.i);
    }

    static void Foo_dtor(Foo *self) {
        free(self->i);
    }

    static void modify_argument_by_reference(Foo *foo) {
        /* Here, we are not bound to any specific requirement
         * since we obtain the argument by reference and it
         * is expected that the argument might be modified.
         */
        ++(*foo->i);
    }

    static void modify_copy_of_argument(Foo foo_) {
        /* Here, since we are going to modify the content of
         * a pointer owned by an object passed by value, we
         * first make an explicit deep copy and then perform
         * the modification. It insures us that main's foo
         * is not modified unexpectedly.
         */
        Foo foo;
        Foo_copy_ctor(&foo, foo_);

        ++(*foo.i);

        /* The deep copy is also necessary if we pass the object
         * by reference to another function, since it is
         * not bound to any constraint on modification.
         */
        modify_argument_by_reference(&foo);

        /* Note: The destructor __must__ be called explicitly,
         *       which is done implicitly in C++.
         */
        Foo_dtor(&foo);
    }

    int main(int argc, char const *argv[]) {
        Foo foo;
        Foo_ctor(&foo, 0);

        modify_copy_of_argument(foo);
        assert(*foo.i == 0);

        Foo_dtor(&foo);
        return 0;
    }
