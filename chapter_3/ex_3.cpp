#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main() {
  // Read the data
  cout << "Input the data: ";
  vector<string> data;
  string x;
  while(cin >> x) {
    data.push_back(x);
  }

  vector<string> str_vec;
  vector<int> count_vec;

  for(int i = 0; i < data.size(); ++i) {
    int found = 0;
    for(int j = 0; j < str_vec.size(); ++j) {
      if (str_vec[j] == data[i]) {
        count_vec[j]++;
        found++;
        break;
      }
    }

    if (found == 0) {
      str_vec.push_back(data[i]);
      count_vec.push_back(1);
    }
  }

  // Print
  for(int i = 0; i < str_vec.size(); ++i) {
    cout << str_vec[i] << " " << count_vec[i] << endl;
  }

  return 0;
}
