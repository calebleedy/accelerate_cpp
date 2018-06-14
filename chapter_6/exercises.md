# Exercises

**6-0.** Compile, execute, and test the programs in this chapter

See [homework_analysis.cpp](./homework_analysis.cpp).

**6-1.** Reimplement the `frame` and `hcat` operations from 5.8.1/93 and 
5.8.3/94 to use iterators.

See [picture_frames.cpp](./picture_frames.cpp).

**6-2.** Write a program to test the `find_urls` function.

**6-3.** What does this program fragment do?

```cpp
vector<int> u(10, 100);
vector<int> v;
copy(u.begin(), u.end(), v.begin());

```

Write a program that contains this fragment, and compile and execute it.

This program first creates a vector, named `u`, of integers. The `u` vector
has 10 values of the number 100. Then we initialize an empty vector of integers,
`v`. Then we attempt to copy all of the values of `u` onto `v`. This results in
a seg fault because we are trying to overwrite `v`.

**6-4.** Correct the program you wrote in the previous exercise to copy `u` into
`v`. There are at least two possible ways to correct the program. Implement both,
and describe the relative advantages and disadvantages of each approach.

We corrected the program first by using a `back_insertor` and then by directly
copying `u` at initialization. By copying at initialization it is very clear
that `v` is a copy of `u`. However, copying via back insertion can copy `u` even
if `v` is nonempty. See [ex_4.cpp](./ex_4.cpp).

**6-5.** Write an analysis function to call `optimistic_median`.

See [homework_analysis.cpp](./homework_analysis.cpp).

**6-6.** Note that the function from the previous exercise and the functions 
from 6.2.2/113 and 6.2.3/115 do the same task. Merge these three analysis 
functions into a single function.

**6-7.** The protion of the grading analysis program from 6.2.1/110 that read 
and classified student records depending on whether they did (or did not) do all
the homework is similar to the problem we solved in `extract_fails`. Write a
function to handle this subproblem.

**6-8.** Write a single function that can be used to classify students based on
criteria of your choice. Test this function by using it in place of the 
`extract_fails` program, and use it in the program to analyze student grades.

**6-9.** Use a library algorithm to concatenate all the elements of a 
`vector<string>`.
