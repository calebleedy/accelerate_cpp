#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main () {
  // square
  int side_length = 5;

  for(int i = 0; i != side_length; ++i) {
    for(int j = 0; j != side_length; ++j) {
      if (i == 0 || j == 0 || i == side_length - 1 || j == side_length - 1) {
        cout << '*';
      } else {
        cout << ' ';
      }
    }
    cout << endl;
  }

  cout << endl;

  // rectangle
  int length = 2;
  int width = 5;

  for(int i = 0; i != length; ++i) {
    for(int j = 0; j != width; ++j) {
      if (i == 0 || j == 0 || i == length - 1 || j == width - 1) {
        cout << '*';
      } else {
        cout << ' ';
      }
    }
    cout << endl;
  }

  // triangle 1
  int tri_size = 7;
  for(int i = 0; i < tri_size; ++i) {
    for(int j = 0; j < i; ++j) {
      if (j == 0 || j == i - 1 || i == tri_size - 1) {
        cout << '*';
      } else {
        cout << ' ';
      }
    }
    cout << endl;
  }

  // triangle 2
  for(int i = 0; i < tri_size; ++i) {
    for(int j = 0; j < tri_size - i; ++j) {
      cout << ' ';
    }
    cout << '*';
    if (i != 0 && i != tri_size - 1) {
      for(int j = 0; j < 2 * i - 1; ++j) {
        cout << ' ';
      } 
      cout << '*';
    }
    if (i == tri_size - 1) {
      for(int j = 0; j < 2 * i; ++j) {
        cout << '*';
      }
    }
    cout << endl;
  }


  return 0;
}
