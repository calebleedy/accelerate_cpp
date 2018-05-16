# Exercises: Chapter 0

0-0: Compile and run the `Hello, world!` program.

See [hello_world](hello_world.cpp) which I compiled using 
`g++ -Wall hello_world.cpp -o hello_world`.

0-1: What does the following statement do?

```
3 + 4;
```

This statement adds the integers three and four and then discards the result.

0-2: Write a program that, when run, writes

```
This (") is a quote, and this (\) is a backslash.
```

See [backslash](backslash.cpp).

0-3: The string literal `"\t"` represents a tab character; different C++
implementations display tabs in different ways. Experiment with your
implementation to learn how it works.

See [tab](tab.cpp). It appears that `g++` treats tabs as three spaces when not 
surrounded by whitespace, one space when one space is after it, and two spaces
when surrounded by spaces.

0-4: Write a program that, when run, writes the `Hello, world!` program as its
output.

See [hello_world_program.cpp](hello_world_program.cpp).

0-5: Is this a valid program? Why or why not?

```c++
#include <iostream>
int main() std::cout << "Hello, world!" << std::endl;
```

Suprisingly this is *not* a valid program. Apparently, there needs to be an
initializer before `std::cout`. This suprised me because `if` statements in C
do *not* need the surrounding braces.

0-6: Is this a valid program? Why or why not?

```c++
#include <iostream>
int main() {{{{{{ std::cout << "Hello, world!" << std::endl; }}}}}}
```

This *is* a valid program. I am not suprised because most of the time braces
are superfluous.

0-7: What about this one?

```c++

#include <iostream>
int main()
{
  /* This is a comment that extends over several lines
     because is uses /* and */ as its starting and ending delimiters */
     std::cout << "Does this work?" << std::endl;
     return 0;
}
```

This is *not* a valid program because the comment symbols prematurely end the 
comment. This exposes `as its starting ...` and the compiler returns an error
because `as` is not in scope.

0-8: ...and this one?

```c++

#include <iostream>
int main()
{
  // This is a comment that extends over several lines
  // by using // at the beginning of each line instead of using /*
  // or */ to delimit comments.
     std::cout << "Does this work?" << std::endl;
     return 0;
}
```

This works great. This `//` comments ensure that the rest of the line is 
commented out. Hence, it cannot become suddenly uncommented like the previous
example.

0-9: What is the shortest valid program?

I think this is the shortest valid program:

```c++
int main(){}
```

It compiles, but as expected does nothing.

0-10: Rewrite the `Hello, world!` program so that a newline occurs everywhere
that whitespace is allowed in the program.

See [hello_world_newline](hello_world_newline.cpp).
