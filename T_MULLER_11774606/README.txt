ASSIGNMENT 1 for C++ PROGRAMMEERMETHODEN
    by Tim Müller (11774606)

For easy compilation, I have attached a Makefile to compile the various tests.
To compile one, simply type 'make test_custom', 'make test_random' or
'make test_code'. These should refer (roughly) to the test file that you will
compile. The binary is put into the bin/ folder. To clarify, though, a more
detailed description per file:
  test_custom: this file contains custom tests used for debugging and to test
        cases where the birth date is after the current date.
  test_random: this file contains the random test as required in the
        assignment. The ideal ratio is 1/7 (about 0.14), but the actual ratio is
        printed by this file.
  test_code: this file contains the delivered test code, pretty much unaltered
        (except for a different assignment1.hpp location).

Running 'make main' will create a main file that allows the user to input a
birthdate him or herself. This has been put into a separete file to not have
duplicate main() functions for the tests.

Finally, by running 'make clean', all binaries will be deleted again, and
'make all' will compile all tests and the main file. This is also the default
action (so simply 'make' will run this).
