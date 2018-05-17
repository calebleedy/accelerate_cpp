// ask for a person's name, and print their name in a box
#include <iostream>
#include <string>

int main()
{
  // ask for the person's name
  std::cout << "Please enter your first name: ";

  // read the name
  std::string name;
  std::cin >> name;

  // build the greeting
  const std::string greeting = "Hello, " + name + "!";

  // get the lines
  const std::string spaces (greeting.size(), ' ');
  const std::string second = "* " + spaces + " *";
  const std::string first (second.size(), '*');

  // write the box
  std::cout << std::endl;
  std::cout << first << std::endl;
  std::cout << second << std::endl;
  std::cout << "* " + greeting + " *" << std::endl;
  std::cout << second << std::endl;
  std::cout << first << std::endl;

  return 0;
}

