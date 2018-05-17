# Exercises

*1-0*: Compile, execute, and test the programs in this chapter.

See [hello_name.cpp](hello_name.cpp) and [hello_box.cpp](hello_box.cpp).

*1-1*: Are the following definitions valid? Why or why not?

```cpp

const std::string hello = "Hello";
const std::string message = hello + ", world" + "!";
```

These definitions are vaild. A string literal can be coerced into a string,
and since `+` is left associative message will iteratively coerce the two
string literals into strings.

*1-2*: Are the following definitions valid? Why or why not?

```cpp

const std::string exclam = "!";
const std::string message = "Hello" + ", world" + exclam;
```

These are *not* valid definitions. While `exclam` is vaild, `message` is 
not. This is because the `+` operator is left associative and not defined 
for string literals. Thus, the initial `"Hello" + ", world"` yields an
error.

*1-3*: Is the following program valid? If so, what does it do? If not, why not?

```cpp

#include <iostream>
#include <string>

int main()
{
  { const std::string s = "a string";
    std::cout << s << std::endl; }

  { const std::string s = "another string";
    std::cout << s << std::endl; }

  return 0;
}
```

The above program should be valid. In each pair of braces a local variable
`s` is created and printed. Since `s` is a local variable, when the second
statement appears the initial `s` has already been destroyed.

*1-4*: What about this one? What if we change `}}` to `};}` in the third
line from the end?

```cpp

#include <iostream>
#include <string>

int main()
{
  { const std::string s = "a string";
    std::cout << s << std::endl;

  { const std::string s = "another string";
    std::cout << s << std::endl; }}

  return 0;
}

```

This is a valid program. Even though we have another variable `s` it is on
a different layer in the stack. Thus, it does not get redefined. Replacing
`}}` with `};}` does not change anything.

*1-5*: Is this program valid? If so, what does it do? If not, say why not, and
rewrite it to be valid.

```cpp

#include <iostream>
#include <string>

int main()
{
  { std::string s = "a string";
  { std::string x = s + ", really";
    std::cout << s << std::endl; }
    std::cout << x << std::endl;
  }
  return 0;
}
```

This is *not* a valid program because we are trying to print `x` when `x`
is not in scope. I fixed the program by deleting the inner braces.

*1-6*: What does the following program do if, when it asks you for input, you
type two names (for example `Samuel Beckett`)? Predict the behavior before
running the program, then try it.

```cpp

#include <iostream>
#include <string>

int main()
{
  std::cout << "What is your name? ";
  std::string name;
  std::cin >> name;
  std::cout << "Hello, " << name
            << std::endl << "And what is yours? ";
  std::cin >> name;
  std::cout << "Hello, " << name
            << "; nice to meet you too!" << std::endl;
  return 0;
}
```

This program should say `Hello, Samuel`, `And what is yours?`, 
`Hello, Beckett; nice to meet you too!` on separate lines. After running
the program, I noticed that the second and third guess are correct but on
the same line.
