# Exercises

**4-0.** Compile, execute, and test the programs in this chapter.

Woohoo! It seemed to work. See the executable `student_grades`.

**4-1.** We noted in 4.2.3/65 that it is essential that the arguments types in a
call to `max` match exactly. Will the following code work? If there is a
problem, how would you fix it?

```cpp

int maxlen;
Student_info s;
max(s.name.size(), maxlen);

```

The following code will not work. However, one can fix the problem by casting
either `s.name.size()` into an `int` or casting `maxlen` into 
`std::string::size_type`.

**4-2.** Write a program to calculate the squares of `int` values up to 100. The
program should write two columns: the first lists the value; the second contains
the square of that value. Use manipulators to manage the output so that the
values line up in columns.

See [ex_2.cpp](./ex_2.cpp).

**4-3.** What happens if we rewrite the previous program to allow values up to
but not including 1000 but neglect to change the arguments to `setwd`? Rewrite
the program to be more robust in the face of changes that allow `i` to grow
without adjusting the `setwd` arguments.

See [ex_3.cpp](./ex_3.cpp).

**4-4.** Now change your squares program to use `double` values instead of
`int`s. Use manipulators to manage the output so that the values line up in
columns.

To view the double values I either need to change my precision to `fixed` or
`scientific`, which is not worth it for integers.

**4-5.** Write a function that reads words from an input stream and stores them
in a `vector`. Use that function both to write programs that count the number of
words in the input, and to count how many times each word occurred.

See [ex_5.cpp](./ex_5.cpp).

**4-6.** Rewrite the `Student_info` structure to calculate the grades
immediately and store only the final grade.

**4-7.** Write a program to calculate the average of the numbers stored in a
`vector<double>`.

See [ex_7.cpp](./ex_7.cpp)

**4-8.** If the following code is legal, what can we infer about the return type
of `f`?

```cpp

double d = f()[n];

```

The function `f()` must have a return type of something similar to a vector of
doubles. It may be possible that it could return an array or other type that 
contains doubles as long as that type has a `[` operator that can take a single
integer as input.

**4-9.** A fairly common bug in C++ implementations is for `setwd` not to work
when you try to use it with a `string`, as we did in 4.2.3/64. Rewrite the
program so that it does not rely on `setwd`. (Hint: create a string with `n`
spaces with `string spaces(n, ' ')`.

By adding `spaces(maxlen - student[i].name.size(), ' ');` we computed the
correct string length.
