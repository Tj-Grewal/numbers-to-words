# numbers-to-words

Small C++ utility that converts integers to English words and prints a sequence of them.

This program currently prints numbers from 0 to 21543 in steps of 13 (see `main()` in `numbers.cpp`).

## Customize the range

The program's `main()` calls `printIntStrings(0, 21543, 13);`. To change what is printed, edit `main()` in `numbers.cpp` and adjust the `start`, `end`, and `interval` arguments, then rebuild.
