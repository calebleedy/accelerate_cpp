# Exercises

*2-0* Compile and run the program presented in this chapter.

See [hello_border.cpp](./hello_border.cpp).

*2-1* Change the framing program so that it writes its greeting with no
separation from the frame.

This occurs when the value for `pad` changes to 0.

*2-2* Change the framing program so that it uses a different amount of space
to separate the sides from the greeting than it uses to separate the top and
bottom boarders from the greeting.

This occurs by splitting the variable `pad` into two variables---`r_pad` 
and `c_pad`. 

*2-3* Rewrite the framing program to ask the user to supply the amount of
spacing to leave between the frame and the greeting.

We now no longer have `const` values for `r_pad` and `c_pad`, but they are
inputed from `cin`.

*2-4* The framing program writes the mostly blank lines that separate the
borders from the greeting one character at a time. Change the program so that it
writes all the spaces needed in a single output expression.

I updated the program so that spaces in the row padding are all printed at
once. However, this required modification to the greeting line such that
we have three consecutive prints of spaces, greeting, and spaces again.
Overall, I think it makes the program less readable.

*2-5* Write a set of "\*" characters so that they form a square, a rectange,
and a triangle.

See [shapes.cpp](./shapes.cpp).

*2-6* What does the following code do?

```cpp

int i = 0;
while (i < 10) {
  i += 1;
  std::cout << i << std::endl;
}

```

This code prints the integers $1, 2, \cdots, 10$ on an individual line.

*2-7* Write a program to count down from 10 to -5.

See [ex_7.cpp](./ex_7.cpp).

*2-8* Write a program to generate the product of the numbers in the range
`[1, 10)`.

See [ex_8.cpp](./ex_8.cpp).

*2-9* Write a program that asks the user to enter two numbers and tells the user
which number is larger than the other.

See [ex_9.cpp](./ex_9.cpp).

*2-10* Explain each of the uses of `std::` in the following program:

```cpp

int main()
{
  int k = 0;
  while (k != n) {
    using std::cout;
    cout << "*";
    ++k;
  }
  std::cout << std::endl;
}

```

The first use of `std::` makes the `cout` function available in the `while` 
scope. The second (and third) use of `std::` call the `cout` (and `endl`) 
functions from the standard library.
