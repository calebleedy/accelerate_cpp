#include <vector>
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
  vector<int> num;
  vector<int> squares;
  for (int i = 0; i < 11; ++i) {
    num.push_back(i);
    squares.push_back(i * i);
  }

  for (int i = 0; i < 11; ++i) {
    cout << std::setw(2) << num[i]; 
    cout << std::setw(4) << squares[i] << endl;
  }

   return 0;
}
