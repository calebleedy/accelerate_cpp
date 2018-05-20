#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
  cout << "Enter a number: ";
  int num1;
  cin >> num1;

  cout << "Enter another number: ";
  int num2;
  cin >> num2;

  if (num1 > num2) {
    cout << num1 << " is bigger" << endl;
  } else if (num2 > num1) {
    cout << num2 << " is bigger" << endl;
  } else {
    cout << "They are equal";
  }

  return 0;
}
