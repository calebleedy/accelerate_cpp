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

  int min = data[0].size();
  int max = data[0].size();

  for(int i = 1; i < data.size(); ++i) {
    if(data[i].size() < min) {
      min = data[i].size();
    } else if (data[i].size() > max) {
      max = data[i].size();
    }
  }

  cout << "Max length is " << max << endl;
  cout << "Min length is " << min << endl;

  return 0;
}

