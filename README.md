# DSBA Introduction to Programming // Workshop 30
Spring semester 2021/22


Class `std::string_view`

Helpful links:

https://www.learncpp.com/cpp-tutorial/an-introduction-to-stdstring_view/

https://www.nextptr.com/tutorial/ta1217154594/cplusplus-stdstring_view-for-better-performance-an-example-use-case

# Tasks

You have a template that reads the contents of the book "Alice in Wonderland" and splits it into a vector of strings. Each string is a single line from the text version of the book.

There are two functions that do the same task. One does it with `std::string` objects, another with `std::string_view` objects.

## Task 0. Compare timing.

Run the template in Release mode. Compare how much time it takes to run the two different versions of the solution.

## Task 1. Good string.

Write a function `isStringGood()` that checks if a string is considered "good".

In this task a "good" string is a string shorter than 50 symbols which has 'A' as its first character.

Make three versions of this function. One takes `std::string` by reference, one takes `const char*` and one takes `std::string_view` as input.

## Task 2. Checking lines.

Count how many "good" lines are there in the vector of lines from Alice and Wonderland.

Use different versions of the functions (`std::string` and `std::string_view`) and compare their runtime like in the example.

Optionally, use all 4 combinations (vector of string/string_view processed by a string/string_view function).

-----


If you finished all these tasks, make an empty Qt project and add a button to it.
