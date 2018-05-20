#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {

  // ask for the person's name
  cout << "Please enter your first name: ";

  // read the name
  string name;
  cin >> name;

  // build the greeting
  const string greeting = "Hello, " + name + "!";
  
  int r_pad;
  int c_pad;

  cout << "Please enter the number of row spaces: ";
  cin >> r_pad;

  cout << "Please enter the number of column spaces: ";
  cin >> c_pad;

  const int rows = r_pad * 2 + 3;
  const string::size_type cols = greeting.size() + 2 * c_pad + 2;
  const string spaces(greeting.size() + 2 * c_pad , ' ');
  const string pad_spaces(c_pad, ' ');

  for(int r = 0; r != rows; ++r) {
    string::size_type c = 0;
    while(c != cols) {
      if (r == r_pad + 1 && c == 1) {
        cout << pad_spaces;
        cout << greeting;
        cout << pad_spaces;
        c += greeting.size() + 2 * pad_spaces.size();
      } else {
        if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
          cout << '*';
          ++c;
        } else {
          cout << spaces;
          c += spaces.size();
        }
      }
    }
    cout << endl;
  }
}
