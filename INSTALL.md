
# Installation of Impossible Triangle 

Generally speaking, this portfolio project is small enough that it is 
intentionally organized flat and without a bin/build/src hierarchy.

The tests require CUnit, a C library package which is available on both 
Red Hat Enterprise Linux and OpenBSD. They are not installed by default,
so one must use either yum/dnf (RHEL) or pkg_add (OpenBSD) to add them.

## Execution

To build and execute the program:

    $ make
    $ itriangle

## Testing

To build and execute the tests: 

    $ make tests
    $ itriangle-tests

## Cleaning

To remove the executables:

    $ make clean
