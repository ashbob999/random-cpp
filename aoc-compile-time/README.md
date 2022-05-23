# aoc-compile-time

A simple proof of concept that proves that an Advent-Of-Code puzzle (2016 Day 1) can be solved at compile time.

It uses cmake to copy the input file into a preprocessor macro, then uses constexpr functions to solve the problem.

Should work on both Windows (msvc) and Linux (GCC >= 12)

This does take much longer to compile the program and shouldn't be used.

https://godbolt.org/z/69TW7sYh1
