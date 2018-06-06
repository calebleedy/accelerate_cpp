#include <vector>
#include <iostream>
#include <iomanip>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int digits_of_int(int i) {
  if (i < 0) {
    throw std::domain_error("Int must be greater than 0");
  } else if (i == 0) {
    return 1;
  }

  int count = 0;
  while (i > 0) {
    i /= 10;
    count++;
  }

  return count;
}



int main() {
  vector<int> num;
  vector<int> squares;
  int maxlen = 101;
  for (int i = 0; i < maxlen; ++i) {
    num.push_back(i);
    squares.push_back(i * i);
  }

  int digit_len = digits_of_int(maxlen);

  for (int i = 0; i < maxlen; ++i) {
    cout << std::setw(digit_len) << num[i]; 
    cout << std::setw(digit_len * 2) << squares[i] << endl;
  }

  return 0;
}
