#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::sort;

int main() {

  // Get the data
  cout << "Input the data. To quit enter ctrl-d: ";

  vector<double> data;
  double read;

  while(cin >> read) {
    data.push_back(read);
  }

  // Sort the data
  sort(data.begin(), data.end());

  // Create bin vec
  vector<int> bin;
  for(int i = 0; i < data.size(); ++i) {
    bin.push_back(i % 4);
  }
  sort(bin.begin(), bin.end());

  // Print the data

  int quartile_count = -1;
  for(int i = 0; i < data.size(); ++i) {
    if (quartile_count != bin[i]) {
      quartile_count++;
      cout << "Quartile " << quartile_count + 1 << endl;
    }
    cout << data[i] << endl;
  }
  return 0;
}
