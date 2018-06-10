# Exercises

**5-0.** Compile, execute, and test the programs in this chapter.

See [student_grades.cpp](./student_grades.cpp) and 
[picture_frames.cpp](./picture_frames.cpp).

**5-1.** Design and implement a program to produce a permuted index. 

See [permuted_data.cpp](permuted_index/permuted_index.cpp).

**5-2.** Write the complete new version of the student-grading program, which
extracts records for failing students, using `vectors`. Write another that uses
`lists`. Measure the performance difference on input files of ten lines, 1000
lines, and 10,000 lines.

I decided to skip this exercise.

**5-3.** By using a `typedef`, we can write one version of the program that 
implements either a `vector`-based solution of a `list`-based solution. Write 
and test this version of the program.

See [student_grades.cpp](./student_grades.cpp).

**5-4.** Look again at the driver functions you wrote in the previous exercise.
Note that it is possible to write a driver that differs only in the declaration
of the type for the data structure that holds the input file. If your `vector`
and `list` test drivers differ in any other way, rewrite them so that they 
differ only in this declaration.

See [student_grades.cpp](./student_grades.cpp).

**5-5.** Write a function named `center(const vector<string>&)` that returns a
picture in which all the lines of the original picture are padded out to their
full width, and the padding is a evenly divided as possible between the left and
right hand sides of the picture. What are the properties of pictures for which
such a function is useful? How can you tell whether a given picture has these
properties?

**5-6.** Rewrite the `extract_fails` function from 5.1.1/77 so that instead of
erasing each failing student from the input vector `v`, it copies the records
for the passing students to the beginning of `v`, and then uses the `resize` 
function to remove the extra elements from the end of `v`. How does the 
performance compare with the one in 5.1.1/77?

**5-7.** Given the implementation of `frame` in 5.8.1/93, and the following code
fragment

```cpp
vector<string> v;
frame(v);
```
describe what happens in this call. In particular, trace through how both the 
`width` function and the `frame` function operate. Now, run the code. If the 
results differ from your expectations, first understand why your expectations
and the program differ, and then change one to match the other.

The initialization of `v` creates an empty vector. After calling frame, the
result (if we were to save it and print it) is two lines of four stars `****`.
This is because the call to width identifies `v` as a zero-length vector. When
we make the frame the first line appends two stars on each side of the longest
string in `v`. However, since the longest string is zero, we are left with four
stars. Then we immediately add the bottom frame because there is no string in
the middle of the frame. Thus, we have two lines of four stars.

**5-8.** In the `hcat` function from 5.8.3/95, what would happen if we defined
`s` outside the scope of the `while`? Rewrite and execute the program to confirm
your hypothesis.

We ended up getting a runtime error with the string length being too long.

**5-9.** Write a program to write the lowercase words in the input followed by
the uppercase words.

See [ex_9.cpp](./ex_9.cpp).

**5-10.** Palindromes are words that are spelled the same right to left as left
to right. Write a program to find all palindrones in a dictionary. Next, find
the longest palindrone.

See [ex_10.cpp](./ex_10.cpp).

**5-11.** In text processing it is sometimes useful to know whether a word has
any ascenders or descenders. Ascenders are the pars of lowercase letters that 
extend above the text line; in the English alphabet, the letters b, d, f, h, k,
l, and t have ascenders. Similarly, the descenders are the parts of the 
lowercase letters that descend below the line. In English, the letters g, j, p,
q, and y have descenders. Write a program to determine whether a word has any 
ascenders or descenders. Extend that program to find the longest word in the 
dictionary that has neither ascenders nor descenders.

I skipped this exercise.
